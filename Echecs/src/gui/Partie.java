package gui;

import gui.pions.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.Arrays;

import static java.lang.Math.abs;

public class Partie
{
    private Echiquier e;
    private Piece_mobile[][] matricePions  = new Piece_mobile[12][8]; //4 colonnes réservés aux pions mangés;
    private int choixActif = 0; //0 par défaut, 1 si on a cliqué sur un pion, 2 si on est en train de transformer un pion
    private int tour = 1; //1 si c'est au tour des blancs, 0 si c'est au tour des noirs
    private int scoreBlanc = 30; //30 points au départ
    private int scoreNoir = 30;
    private Point pos = new Point(-1,-1); //position de la case sur laquelle on cliquera (initialisée en dehors du plateau)
    private boolean finie;
    private boolean termine; //permet d'enregistrer et d'augmenter de 10 le score qu'une seule fois dans la méthode dessiner
    private boolean saveBDD; //true si on choisit de sauvegarder les scores dans la base de données
    private ArrayList<Point> listeDeplaPossib = new ArrayList<>(); //pour garder en mémoire les pions pour la transformation
    private ArrayList<Piece_mobile> listeTCFD = new ArrayList<>(); //pour garder en mémoire les déplacements possibles d'un pion
    private ConnexionBDD coBDD;

    public Partie()
    {
        coBDD = new ConnexionBDD();
        e = new Echiquier(800,50,50);
        finie = false;
        termine = false;
        saveBDD = true;
        matricePions[0][0] = new Tour(new Point(0,0),0);
        matricePions[7][0] = new Tour(new Point(7,0),0);
        matricePions[0][7] = new Tour(new Point(0,7),1);
        matricePions[7][7] = new Tour(new Point(7,7),1);
        matricePions[1][0] = new Cavalier(new Point(1,0),0);
        matricePions[6][0] = new Cavalier(new Point(6,0),0);
        matricePions[1][7] = new Cavalier(new Point(1,7),1);
        matricePions[6][7] = new Cavalier(new Point(6,7),1);
        matricePions[2][0] = new Fou(new Point(2,0),0);
        matricePions[5][0] = new Fou(new Point(5,0),0);
        matricePions[2][7] = new Fou(new Point(2,7),1);
        matricePions[5][7] = new Fou(new Point(5,7),1);
        matricePions[3][0] = new Dame(new Point(3,0),0);
        matricePions[3][7] = new Dame(new Point(3,7),1);
        matricePions[4][0] = new Roi(new Point(4,0),0);
        matricePions[4][7] = new Roi(new Point(4,7),1);
        for (int i=0;i<8;i++) {
            matricePions[i][1] = new Pion(new Point(i,1),0);
            matricePions[i][6] = new Pion(new Point(i,6),1);
        }
    }
    Echiquier getEchiquier() {
        return e;
    }
    public int getChoixActif() {
        return choixActif;
    }
    public void setChoixActif(int c) {
        choixActif = c;
    }
    public int getTour() {
        return tour;
    }
    public void setTour(int t) {
        tour = t;
    }
    public Point getPos() {
        return pos;
    }
    public void setPos(Point p) {
        pos = p;
    }
    public boolean getFinie() {
        return finie;
    }
    public void setFinie(boolean f) {
        finie = f;
    }
    public boolean getSaveBDD() {
        return saveBDD;
    }
    public ArrayList<Point> getListeDeplaPossib() {
        return listeDeplaPossib;
    }
    public ArrayList<Piece_mobile> getListeTCFD() {
        return listeTCFD;
    }
    public void setListeTCFD(ArrayList<Piece_mobile> lTCFD) {
        listeTCFD = lTCFD;
    }
    public void mettreAJour(int tPlateau, int cSGX, int cSGY, boolean s)
    {
        //changement des dimensions et coordonnées de l'échiquier
        e = new Echiquier(tPlateau, cSGX, cSGY);
        saveBDD = s;
    }
    public void dessiner(Graphics g) {
        e.dessiner(g);
        int tailleCase = e.getTaillePlateau() / 8;
        //pions sur l'échiquier
        for (int i=0;i<8;i++) {
            for (int j=0;j<8;j++) {
                if (matricePions[i][j] != null)
                    matricePions[i][j].dessiner(g, new Point(e.getCoinSupGauche().x + i*tailleCase, e.getCoinSupGauche().y + j*tailleCase), tailleCase);
            }
        }
        //pions mangés
        int pb=0,tb=0,cb=0,fb=0,db=0,pn=0,tn=0,cn=0,fn=0,dn=0; //compteurs de pions mangés
        int i=8,j=0;
        while (i < 12 && matricePions[i][j] != null) {
            do {
                switch (matricePions[i][j].getType()) {
                    case 5 :
                        //pions simples mangés blancs
                        if (matricePions[i][j].getCamp() == 1) {
                            matricePions[i][j].dessiner(g, new Point(e.getCoinSupGauche().x + e.getTaillePlateau() + tailleCase / 8 + pb * tailleCase / 8,
                                    e.getCoinSupGauche().y + tailleCase / 4), tailleCase / 2);
                            pb++;
                        }
                        //pions simples mangés noirs
                        else {
                            matricePions[i][j].dessiner(g, new Point(e.getCoinSupGauche().x + e.getTaillePlateau() + tailleCase / 8 + pn * tailleCase / 8,
                                    e.getCoinSupGauche().y + e.getTaillePlateau() - 3 * tailleCase / 4), tailleCase / 2);
                            pn++;
                        }
                        break;

                    case 0 :
                        //tours mangées blanches
                        if (matricePions[i][j].getCamp() == 1) {
                            matricePions[i][j].dessiner(g, new Point(e.getCoinSupGauche().x + e.getTaillePlateau() + tailleCase / 8 + tb * tailleCase / 8,
                                    e.getCoinSupGauche().y + 3 * tailleCase / 4), tailleCase / 2);
                            tb++;
                        }
                        //tours mangées noires
                        else {
                            matricePions[i][j].dessiner(g, new Point(e.getCoinSupGauche().x + e.getTaillePlateau() + tailleCase / 8 + tn * tailleCase / 8,
                                    e.getCoinSupGauche().y + e.getTaillePlateau() - 5 * tailleCase / 4), tailleCase / 2);
                            tn++;
                        }
                        break;

                    case 1 :
                        //cavaliers mangés blancs
                        if (matricePions[i][j].getCamp() == 1) {
                            matricePions[i][j].dessiner(g, new Point(e.getCoinSupGauche().x + e.getTaillePlateau() + tailleCase / 8 + cb * tailleCase / 8,
                                    e.getCoinSupGauche().y + 5 * tailleCase / 4), tailleCase / 2);
                            cb++;
                        }
                        //cavaliers mangés noirs
                        else {
                            matricePions[i][j].dessiner(g, new Point(e.getCoinSupGauche().x + e.getTaillePlateau() + tailleCase / 8 + cn * tailleCase / 8,
                                    e.getCoinSupGauche().y + e.getTaillePlateau() - 7 * tailleCase / 4), tailleCase / 2);
                            cn++;
                        }
                        break;

                    case 2 :
                        //fous mangés blancs
                        if (matricePions[i][j].getCamp() == 1) {
                            matricePions[i][j].dessiner(g, new Point(e.getCoinSupGauche().x + e.getTaillePlateau() + tailleCase / 8 + fb * tailleCase / 8,
                                    e.getCoinSupGauche().y + 7 * tailleCase / 4), tailleCase / 2);
                            fb++;
                        }
                        //fous mangés noirs
                        else {
                            matricePions[i][j].dessiner(g, new Point(e.getCoinSupGauche().x + e.getTaillePlateau() + tailleCase / 8 + fn * tailleCase / 8,
                                    e.getCoinSupGauche().y + e.getTaillePlateau() - 9 * tailleCase / 4), tailleCase / 2);
                            fn++;
                        }
                        break;

                    case 3 :
                        //dames mangées blanches
                        if (matricePions[i][j].getCamp() == 1) {
                            matricePions[i][j].dessiner(g, new Point(e.getCoinSupGauche().x + e.getTaillePlateau() + tailleCase / 8 + db * tailleCase / 8,
                                    e.getCoinSupGauche().y + 9 * tailleCase / 4), tailleCase / 2);
                            db++;
                        }
                        //dames mangées noires
                        else {
                            matricePions[i][j].dessiner(g, new Point(e.getCoinSupGauche().x + e.getTaillePlateau() + tailleCase / 8 + dn * tailleCase / 8,
                                    e.getCoinSupGauche().y + e.getTaillePlateau() - 11 * tailleCase / 4), tailleCase / 2);
                            dn++;
                        }
                        break;
                }
                j++;
            } while (j < 8 && matricePions[i][j] != null);
            if (j == 8) {
                j = 0;
                i++;
            }
        }

        //Affichage de texte
        Font police = new Font("Comic Sans MS", Font.PLAIN, tailleCase/4);
        g.setFont(police);
        g.setColor(Color.black);

        //fin de partie
        if (pat()) {
            finie = true;
            if (echec()[0]) {
                //score
                if (!termine)
                    scoreBlanc += 10;
                g.drawString(" Échec et mat ! Victoire des blancs.", e.getCoinSupGauche().x + e.getTaillePlateau(),
                        e.getCoinSupGauche().y + e.getTaillePlateau() / 2);
            }
            else if (echec()[1]) {
                //score
                if (!termine)
                    scoreNoir += 10;
                g.drawString(" Échec et mat ! Victoire des noirs.", e.getCoinSupGauche().x + e.getTaillePlateau(),
                        e.getCoinSupGauche().y + e.getTaillePlateau() / 2);
            }
            else
                g.drawString(" Pat ! Égalité.", e.getCoinSupGauche().x + e.getTaillePlateau(),
                        e.getCoinSupGauche().y + e.getTaillePlateau() / 2);
            g.drawString(" Score blancs / noirs : " + String.valueOf(scoreBlanc) + " / " + String.valueOf(scoreNoir),
                    e.getCoinSupGauche().x + e.getTaillePlateau(),
                    e.getCoinSupGauche().y + e.getTaillePlateau() / 2 + tailleCase);
            //enregistrement dans la base de données
            if (saveBDD && !termine) {
                coBDD.enregistrerScore("player1F_C",scoreBlanc);
                coBDD.enregistrerScore("player2F_C",scoreNoir);
            }
            termine = true;
        }
        //victoire par abandon
        else if (finie) {
            if (tour == 0) {
                g.drawString(" Victoire des blancs par abandon", e.getCoinSupGauche().x + e.getTaillePlateau(),
                        e.getCoinSupGauche().y + e.getTaillePlateau() / 2);
                if (!termine)
                    scoreBlanc += 10;
            }
            else {
                g.drawString(" Victoire des noirs par abandon", e.getCoinSupGauche().x + e.getTaillePlateau(),
                        e.getCoinSupGauche().y + e.getTaillePlateau() / 2);
                if (!termine)
                    scoreNoir += 10;
            }
            g.drawString(" Score blancs / noirs : " + String.valueOf(scoreBlanc) + " / " + String.valueOf(scoreNoir),
                    e.getCoinSupGauche().x + e.getTaillePlateau(),
                    e.getCoinSupGauche().y + e.getTaillePlateau() / 2 + tailleCase);
            //enregistrement dans la base de données
            if (saveBDD && !termine) {
                coBDD.enregistrerScore("player1F_C", scoreBlanc);
                coBDD.enregistrerScore("player2F_C", scoreNoir);
            }
            termine = true; //le score ne changera plus et ne s'enregistrera plus au prochain appel de la méthode
        }
        //au cours de la partie
        else {
            if (tour == 0)
                g.drawString(" Déplacez un pion noir", e.getCoinSupGauche().x + e.getTaillePlateau(),
                        e.getCoinSupGauche().y + e.getTaillePlateau() / 2 - tailleCase);
            else
                g.drawString(" Déplacez un pion blanc", e.getCoinSupGauche().x + e.getTaillePlateau(),
                        e.getCoinSupGauche().y + e.getTaillePlateau() / 2 + tailleCase);
            if (echec()[0] || echec()[1])
                g.drawString(" Échec !", e.getCoinSupGauche().x + e.getTaillePlateau(), e.getCoinSupGauche().y + e.getTaillePlateau() / 2);
        }
    }
    public Point convertirCoordPos(int x, int y) {
        //Recherche de la case selectionnée à partir des coordonnées dans la fenêtre
        //retourne la position dans l'échiquier entre (0,0) et (7,7), (-1,-1) si en dehors de l'échiquier.
        //changement de repère et division entière (permet de cliquer n'importe où sur la case)
        int tailleCase = e.getTaillePlateau() / 8;
        if (x >= e.getCoinSupGauche().x && y >= e.getCoinSupGauche().y && x <= e.getCoinSupGauche().x + e.getTaillePlateau()
                && y <= e.getCoinSupGauche().y + e.getTaillePlateau())
            return new Point((x - e.getCoinSupGauche().x) / tailleCase, (y - e.getCoinSupGauche().y) / tailleCase);
        return new Point(-1,-1); //en dehors du plateau
    }
    public boolean selectionPossible(Point pos) {
        //retourne true s'il y a un pion de la bonne couleur sur la case, false sinon
        if (pos.x != -1 && matricePions[pos.x][pos.y] != null && matricePions[pos.x][pos.y].getCamp() == tour)
            return true;
        return false;

    }
    public void deplaPossibSimple(Point pos) {
        ArrayList<Point> listePos = new ArrayList<Point>();
        //cas des pions normaux noirs
        if (matricePions[pos.x][pos.y].getCamp() == 0 && pos.y + 1 < 8) {
            //déplacement d'une case
            if (matricePions[pos.x][pos.y + 1] == null)
                listePos.add(new Point(pos.x, pos.y + 1));
            //déplacement de deux cases pour le premier déplacement
            if (matricePions[pos.x][pos.y].getNbDepla() == 0 && matricePions[pos.x][pos.y + 1] == null
                    && pos.y + 2 < 8 && matricePions[pos.x][pos.y + 2] == null)
                listePos.add(new Point(pos.x, pos.y + 2));
            //déplacements en diagonales pour manger d'autres pions
            if (pos.x + 1 < 8 && matricePions[pos.x + 1][pos.y + 1] != null && matricePions[pos.x + 1][pos.y + 1].getCamp() == 1)
                listePos.add(new Point(pos.x + 1, pos.y + 1));
            if (pos.x - 1 >= 0 && matricePions[pos.x - 1][pos.y + 1] != null && matricePions[pos.x - 1][pos.y + 1].getCamp() == 1)
                listePos.add(new Point(pos.x - 1, pos.y + 1));
            //en passant (droite et gauche)
            if (pos.y == 4 && pos.x + 1 < 8 && matricePions[pos.x + 1][4] != null && matricePions[pos.x + 1][4].getCamp() == 1
                    && matricePions[pos.x + 1][4].getType() == 5 && matricePions[pos.x + 1][4].getDernierDepla()
                    && matricePions[pos.x + 1][4].getNbDepla() == 1)
                listePos.add(new Point(pos.x + 1,5)); //cette case est forcément vide car le pion ennemi a avancé de deux cases
            else if (pos.y == 4 && pos.x - 1 >= 0 && matricePions[pos.x - 1][4] != null && matricePions[pos.x - 1][4].getCamp() == 1
                    && matricePions[pos.x - 1][4].getType() == 5 && matricePions[pos.x - 1][4].getDernierDepla()
                    && matricePions[pos.x - 1][4].getNbDepla() == 1)
                listePos.add(new Point(pos.x - 1,5));
        }
        //cas des pions normaux noirs
        else if (matricePions[pos.x][pos.y].getCamp() == 1 && pos.y - 1 >= 0) {
            if (matricePions[pos.x][pos.y - 1] == null)
                listePos.add(new Point(pos.x, pos.y - 1));
            if (matricePions[pos.x][pos.y].getNbDepla() == 0 && matricePions[pos.x][pos.y - 1] == null
                    && pos.y - 2 >= 0 && matricePions[pos.x][pos.y - 2] == null)
                listePos.add(new Point(pos.x, pos.y - 2));
            if (pos.x + 1 < 8 && matricePions[pos.x + 1][pos.y - 1] != null && matricePions[pos.x + 1][pos.y - 1].getCamp() == 0)
                listePos.add(new Point(pos.x + 1, pos.y - 1));
            if (pos.x - 1 >= 0 && matricePions[pos.x - 1][pos.y - 1] != null && matricePions[pos.x - 1][pos.y - 1].getCamp() == 0)
                listePos.add(new Point(pos.x - 1, pos.y - 1));
            if (pos.y == 3 && pos.x + 1 < 8 && matricePions[pos.x + 1][3] != null && matricePions[pos.x + 1][3].getCamp() == 0
                    && matricePions[pos.x + 1][3].getType() == 5 && matricePions[pos.x + 1][3].getDernierDepla()
                    && matricePions[pos.x + 1][3].getNbDepla() == 1)
                listePos.add(new Point(pos.x + 1,2)); //cette case est forcément vide car le pion ennemi a avancé de deux cases
            else if (pos.y == 3 && pos.x - 1 >= 0 && matricePions[pos.x - 1][3] != null && matricePions[pos.x - 1][3].getCamp() == 0
                    && matricePions[pos.x - 1][3].getType() == 5 && matricePions[pos.x - 1][3].getDernierDepla()
                    && matricePions[pos.x - 1][3].getNbDepla() == 1)
                listePos.add(new Point(pos.x - 1,2));
        }
        listeDeplaPossib = listePos;

    }
    public void deplaPossibSpecial(Point pos) {
        ArrayList<Point> listePos;
        ArrayList<Point> posOccupee = new ArrayList<Point>();
        ArrayList<Point> posCachee = new ArrayList<Point>();
        boolean sup;
        int i;
        Point po;
        listePos = matricePions[pos.x][pos.y].deplaPossibles(); //dépend du pion sur la case
        //liste des cases occupées
        for (Point p : listePos) {
            if (matricePions[p.x][p.y] != null)
                posOccupee.add(p);
        }

        //retrait des cases occupées par des alliés
        for (Point p : posOccupee) {
            if (matricePions[p.x][p.y].getCamp() == matricePions[pos.x][pos.y].getCamp())
                listePos.remove(p);
        }

        //retrait des cases "cachées" par des pions
        for (Point p : listePos) {
            sup = false;
            i = 0;
            while (!sup && i < posOccupee.size()) {
                po = posOccupee.get(i);
                if ((p.y == po.y && p.y == pos.y && ((p.x < po.x && po.x < pos.x) || (pos.x < po.x && po.x < p.x)))
                        || (p.x == po.x && p.x == pos.x && ((p.y < po.y && po.y < pos.y) || (pos.y < po.y && po.y < p.y)))
                        || (abs(p.x - pos.x) == abs(p.y - pos.y) && abs(p.x - po.x) == abs(p.y - po.y) &&
                        ((p.x < po.x && po.x < pos.x) || (pos.x < po.x && po.x < p.x)))) {
                    posCachee.add(p);
                    sup = true;
                }
                i++;
            }
        }
        for (Point p : posCachee)
            listePos.remove(p);
        listeDeplaPossib = listePos;
    }
    public void deplaPossibEchec(Point pos) {
        //doit être appelée pour enlever les positions mettant en echec son roi
        Piece_mobile temp;
        ArrayList<Point> listePos = listeDeplaPossib; //sauvegarde de la liste de départ
        ArrayList<Point> deplaAEnlever = new ArrayList<>();
        //test de chaque déplacement du pion pour voir s'il y a échec après
        for (Point p : listePos) {
            //simulation du déplacement
            temp = matricePions[p.x][p.y]; //on conserve le pion s'il y en a un
            matricePions[p.x][p.y] = matricePions[pos.x][pos.y];
            matricePions[p.x][p.y].setPosition(p);
            matricePions[pos.x][pos.y] = null;
            if (echec()[tour])
                deplaAEnlever.add(p); //s'il y a échec sur son roi après le déplacement, on l'enlève de la liste
            //on remet les pions à leur place
            matricePions[pos.x][pos.y] = matricePions[p.x][p.y];
            matricePions[pos.x][pos.y].setPosition(pos);
            matricePions[p.x][p.y] = temp;
        }
        //retrait des cases qui ne résout pas l'échec
        for (Point p : deplaAEnlever)
            listePos.remove(p);
        listeDeplaPossib = listePos; //change l'attribut dans la classe par la liste des déplacements possibles finales
    }
    public void deplaPossib(Point pos) {
        //pre-condition : il y a un pion de la bonne couleur sur la case
        if (matricePions[pos.x][pos.y].getType() == 5)
            deplaPossibSimple(pos); //cas des pions simples
        else
            deplaPossibSpecial(pos);//cas des autres pions
        deplaPossibEchec(pos); //enlève les positions qui mènent à un échec de son roi

        //ajout du roque
        if (matricePions[pos.x][pos.y].getType() == 4 && matricePions[pos.x][pos.y].getNbDepla() == 0) {
            if (matricePions[pos.x][pos.y].getCamp() == 1 && !echec()[1]) {
                if (matricePions[7][7] != null && matricePions[7][7].getCamp() == 1 && matricePions[7][7].getNbDepla() == 0
                        && matricePions[5][7] == null && matricePions[6][7] == null && listeDeplaPossib.contains(new Point(5,7)))
                    listeDeplaPossib.add(new Point(6, 7));
                if (matricePions[0][7] != null && matricePions[0][7].getCamp() == 1 && matricePions[0][7].getNbDepla() == 0
                        && matricePions[1][7] == null && matricePions[2][7] == null && matricePions[3][7] == null
                        && listeDeplaPossib.contains(new Point(3,7)))
                    listeDeplaPossib.add(new Point(2, 7));
            }
            else if (matricePions[pos.x][pos.y].getCamp() == 0 && !echec()[0]) {
                if (matricePions[0][0] != null && matricePions[0][0].getCamp() == 0 && matricePions[0][0].getNbDepla() == 0
                        && matricePions[1][0] == null && matricePions[2][0] == null && matricePions[3][0] == null
                        && listeDeplaPossib.contains(new Point(3,0)))
                    listeDeplaPossib.add(new Point(2, 0));
                if (matricePions[7][0] != null && matricePions[7][0].getCamp() == 0 && matricePions[7][0].getNbDepla() == 0
                        && matricePions[5][0] == null && matricePions[6][0] == null && listeDeplaPossib.contains(new Point(5,0)))
                    listeDeplaPossib.add(new Point(6, 0));
            }
            deplaPossibEchec(pos); //enlève la position roque si cela mènent à un échec de son roi
        }
    }
    public void affichDeplaPossib(ArrayList<Point> listePos,Graphics g,int tBar) {
        Case c;
        //coloration des cases
        for (int j=0;j<8;j++) {
            for (int k=0;k<8;k++) {
                c = e.getCase(j,k);
                if (listePos.contains(new Point(j,k)))
                    g.setColor(new Color(150,255,150,50));
                else
                    g.setColor(new Color(255,150,150,50));
                g.fillRect(c.getCoinSuperieurGauche().x, c.getCoinSuperieurGauche().y + tBar, c.getTaille(), c.getTaille());
            }
        }
    }
    public void deplacer(Point posOld,Point posNew) {
        if (matricePions[posNew.x][posNew.y] != null)
            manger(posNew);
        //cas "en passant" : un pion simple qui va en diagonale sur une case vide -> mange le pion à côté
        else if (matricePions[posOld.x][posOld.y].getType() == 5 && abs(posNew.x - posOld.x) == 1 && abs(posNew.y - posOld.y) == 1)
            manger(new Point(posNew.x,posOld.y));
        //cas "roque"
        else if (matricePions[posOld.x][posOld.y].getType() == 4) {
            if (posNew.x == posOld.x - 2) {
                if (matricePions[posOld.x][posOld.y].getCamp() == 0) {
                    matricePions[3][0] = matricePions[0][0];
                    matricePions[0][0] = null;
                    matricePions[3][0].setPosition(new Point(3, 0));
                }
                else {
                    matricePions[3][7] = matricePions[0][7];
                    matricePions[0][7] = null;
                    matricePions[3][7].setPosition(new Point(3, 7));
                }
            }
            else if (posNew.x == posOld.x + 2) {
                if (matricePions[posOld.x][posOld.y].getCamp() == 0) {
                    matricePions[5][0] = matricePions[7][0];
                    matricePions[7][0] = null;
                    matricePions[5][0].setPosition(new Point(5, 0));
                } else {
                    matricePions[5][7] = matricePions[7][7];
                    matricePions[7][7] = null;
                    matricePions[5][7].setPosition(new Point(5, 7));
                }
            }
        }
        matricePions[posNew.x][posNew.y] = matricePions[posOld.x][posOld.y];
        matricePions[posOld.x][posOld.y] = null;
        matricePions[posNew.x][posNew.y].setPosition(posNew);
        //recherche du pion avec dernierDepla = true pour le remettre à false
        boolean trouve = false;
        int i=0,j;
        while (!trouve && i < 8) { //condition i<8 obligatoire pour le premier déplacement
            j = 0;
            while (!trouve && j < 8) {
                if (matricePions[i][j] != null && matricePions[i][j].getDernierDepla()) {
                    matricePions[i][j].setDernierDepla(false);
                    trouve = true;
                }
                j++;
            }
            i++;
        }
        matricePions[posNew.x][posNew.y].setDernierDepla(true);
        matricePions[posNew.x][posNew.y].incrementerNbDepla();

        //Score
        if (tour == 1)
            scoreBlanc--;
        else
            scoreNoir--;

    }

    public void manger(Point posPionMange) {
        int i=8,j=0;
        //recherche d'une place parmi les pions mangés
        while (matricePions[i][j] != null) {
            do
                j++;
            while (j < 8 && matricePions[i][j] != null);
            if (j==8) {
                j = 0;
                i++;
            } //permet de sortir de la boucle sur i si on a trouvé
        }
        matricePions[i][j] = matricePions[posPionMange.x][posPionMange.y];
        matricePions[i][j].setPosition(new Point(i,j));
        matricePions[posPionMange.x][posPionMange.y] = null;
        //Score
        if (tour == 1)
            scoreBlanc += 2;
        else
            scoreNoir += 2;
    }

    public Point possibPromo() {
        //retourne la position d'un pion pouvant se transformer s'il y en a un, (-1,-1) sinon
        for (int i=0;i<8;i++) {
            //pion simple blanc en première ligne de l'échiquier ou pion simple noir en dernière ligne de l'échiquier
            if (matricePions[i][0] != null && matricePions[i][0].getType() == 5 && matricePions[i][0].getCamp() == 1)
                return new Point(i,0);
            else if (matricePions[i][7] != null && matricePions[i][7].getType() == 5 && matricePions[i][7].getCamp() == 0)
                return new Point(i,7);
        }
        return new Point(-1,-1);
    }
    public ArrayList<Piece_mobile> rechercherPionsTCFD(Point posT) {
        Piece_mobile t=null,c=null,f=null,d=null;
        boolean fini = false;
        int i=0,j,camp = matricePions[posT.x][posT.y].getCamp();
        while (!fini) {
            j = 0;
            while (j < 8 && !fini) {
                if (matricePions[i][j] != null) {
                    switch (matricePions[i][j].getType()) {
                        case 0:
                            if (t == null && matricePions[i][j].getCamp() == camp)
                                t = matricePions[i][j];
                            break;
                        case 1:
                            if (c == null && matricePions[i][j].getCamp() == camp)
                                c = matricePions[i][j];
                            break;
                        case 2:
                            if (f == null && matricePions[i][j].getCamp() == camp)
                                f = matricePions[i][j];
                            break;
                        case 3:
                            if (d == null && matricePions[i][j].getCamp() == camp)
                                d = matricePions[i][j];
                            break;
                    }
                }
                fini = (t != null && c != null && f!= null && d!= null);
                j++;
            }
            i++;
        }
        ArrayList<Piece_mobile> listeTCFD = new ArrayList<>(Arrays.asList(t, c, f, d));
        return listeTCFD;
    }
    public void affichPromo(ArrayList<Piece_mobile> listeTCFD, Graphics g,int tBar) {
        int tailleCase = e.getTaillePlateau() / 8;
        g.setColor(Color.RED);
        g.fillRect(e.getCoinSupGauche().x + 3*tailleCase/2, e.getCoinSupGauche().y + 5*tailleCase/2 + tBar, 5*tailleCase, 3*tailleCase);
        g.setColor(Color.CYAN);
        g.fillRect(e.getCoinSupGauche().x + 7*tailleCase/4, e.getCoinSupGauche().y + 11*tailleCase/4 + tBar, 9*tailleCase/2, 5*tailleCase/2);
        g.setColor(Color.black);
        Font police = new Font("Comic Sans MS", Font.PLAIN, 23*tailleCase/100);
        g.setFont(police);
        g.drawString(" Choisissez un pion pour la promotion",e.getCoinSupGauche().x + 7*tailleCase/4, e.getCoinSupGauche().y + 4*tailleCase);

        //Redessine les pions
        g.drawImage(listeTCFD.get(0).getImage().getImage(), e.getCoinSupGauche().x + 2*tailleCase,
                e.getCoinSupGauche().y + 4*tailleCase + tBar, tailleCase, tailleCase, null);
        g.drawImage(listeTCFD.get(1).getImage().getImage(), e.getCoinSupGauche().x + 3*tailleCase,
                e.getCoinSupGauche().y + 4*tailleCase + tBar, tailleCase, tailleCase, null);
        g.drawImage(listeTCFD.get(2).getImage().getImage(), e.getCoinSupGauche().x + 4*tailleCase,
                e.getCoinSupGauche().y + 4*tailleCase + tBar, tailleCase, tailleCase, null);
        g.drawImage(listeTCFD.get(3).getImage().getImage(), e.getCoinSupGauche().x + 5*tailleCase,
                e.getCoinSupGauche().y + 4*tailleCase + tBar, tailleCase, tailleCase, null);
    }
    public void transformer(Point posT,Point posNew) {

        switch (matricePions[posNew.x][posNew.y].getType()) {
            case 0 :
                matricePions[posT.x][posT.y] = new Tour(matricePions[posNew.x][posNew.y]);
                break;
            case 1 :
                matricePions[posT.x][posT.y] = new Cavalier(matricePions[posNew.x][posNew.y]);
                break;
            case 2 :
                matricePions[posT.x][posT.y] = new Fou(matricePions[posNew.x][posNew.y]);
                break;
            case 3 :
                matricePions[posT.x][posT.y] = new Dame(matricePions[posNew.x][posNew.y]);
                break;
        }
        matricePions[posT.x][posT.y].setPosition(posT);
        //Score
        if (tour == 1)
            scoreBlanc++;
        else
            scoreNoir++;
    }
    public boolean[] echec() {
        boolean[] echec = new boolean[2];
        echec[0] = false; //échec pour le roi blanc
        echec[1] = false; //échec pour le roi noir
        int i=0,j,k;
        Point p;
        ArrayList<Point> deplaPossibles = listeDeplaPossib; //sauvegarde de la liste
        while ((!echec[0] || !echec[1]) && i < 8) {
            j = 0;
            while ((!echec[0] || !echec[1]) && j < 8) {
                if (matricePions[i][j] != null) {
                    //on remplit la liste des déplacements possibles du pion (sans prendre en compte les échecs)
                    if (matricePions[i][j].getType() == 5)
                        deplaPossibSimple(new Point(i, j));
                    else
                        deplaPossibSpecial(new Point(i, j));
                    k = 0;
                    //on s'arrête de chercher quand on trouve le roi du camp opposé au camp du pion considéré en échec
                    //si campPion = 1, -1*(campPion-1) = 0 et si campPion = 0, -1*(campPion-1) = 1
                    while (!echec[-1*(matricePions[i][j].getCamp()-1)] && k < listeDeplaPossib.size()) {
                        p = listeDeplaPossib.get(k);
                        if (matricePions[p.x][p.y] != null && matricePions[p.x][p.y].getType() == 4 &&
                                matricePions[p.x][p.y].getCamp() != matricePions[i][j].getCamp())
                            echec[matricePions[p.x][p.y].getCamp()] = true;
                        k++;
                    }
                }
                j++;
            }
            i++;
        }
        listeDeplaPossib = deplaPossibles; //permet de retrouver la liste de départ
        return echec;
    }
    public boolean pat()
    {
        //cas où il ne reste que les rois
        //cette case est remplie uniquement si tous les pions ont été mangés (sauf les rois)
        if (matricePions[11][5] != null)
            return true;
        else {
            boolean pat = true; //les pions alliés ne peuvent plus bouger (initialisation)
            int i = 0, j;
            //on regarde si les pions alliés peuvent bouger
            while (pat && i < 8) {
                j = 0;
                while (pat && j < 8) {
                    if (matricePions[i][j] != null && matricePions[i][j].getCamp() == tour) {
                        deplaPossib(new Point(i, j)); //change la liste listeDeplaPossib
                        if (!listeDeplaPossib.isEmpty()) //si on trouve un déplacement possible d'un pion allié
                            pat = false;
                    }
                    j++;
                }
                i++;
            }
            return pat;
        }
    }
}

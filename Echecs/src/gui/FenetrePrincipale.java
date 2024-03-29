package gui;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class FenetrePrincipale extends JFrame {

    private MonPanel contentPane ;
    int cSGX = 250, cSGY = 0, largeur = 1400, hauteur = 1100;
    private JToolBar toolBar;
    private JButton bAbandonner, bRecommencer, bParam, bQuitter;
    private Partie p;

    public FenetrePrincipale()
    {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(cSGX,cSGY,largeur,hauteur);
        setTitle("Jeu d'échec");

        // Panneau de composants
        contentPane = new MonPanel(this);
        contentPane.setLayout(null);
        setContentPane(contentPane);
        contentPane.setBackground(Color.WHITE);
        contentPane.addMouseListener(new MouseListener() {
            @Override
            public void mouseClicked(MouseEvent e) {
                formMouseClicked(e) ;
            }

            @Override
            public void mousePressed(MouseEvent e) {
            }

            @Override
            public void mouseReleased(MouseEvent e) {
            }

            @Override
            public void mouseEntered(MouseEvent e) {
            }

            @Override
            public void mouseExited(MouseEvent e) {
            }
        });

        // Composant barre d'outils
        toolBar = new JToolBar();
        toolBar.setBounds(0,0,800,30);
        contentPane.add(toolBar);
        contentPane.setFocusable(true);

        bAbandonner = new JButton("Déclarer forfait");
        toolBar.add(bAbandonner);
        bAbandonner.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                abandonner(e);
            }
        });

        bRecommencer = new JButton("Recommencer");
        toolBar.add(bRecommencer);
        bRecommencer.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                recommencer(e);
            }
        });

        bParam = new JButton("Paramètres");
        toolBar.add(bParam);
        bParam.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                ouvrirParam();
            }
        });

        bQuitter = new JButton("Quitter");
        toolBar.add(bQuitter);
        bQuitter.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dispose();
            }
        });

        p =  new Partie();

    }
    public int getLargeur() {
        return largeur;
    }
    public void setLargeur(int l) {
        largeur = l;
    }
    public int getHauteur() {
        return hauteur;
    }
    public void setHauteur(int h) {
        hauteur = h;
    }
    public int getCSGX() {
        return cSGX;
    }
    public void setCSGX(int x) {
        cSGX = x;
    }
    public int getCSGY() {
        return cSGY;
    }
    public void setCSGY(int y) {
        cSGY = y;
    }
    public void abandonner(ActionEvent e) {
        p.setFinie(true);
        dessiner(getContentPane().getGraphics());
    }
    public void recommencer(ActionEvent e) {
        p = new Partie();
        dessiner(getContentPane().getGraphics());
    }
    public void ouvrirParam() {
        FenetreDialogue dialog = new FenetreDialogue(this, p, getContentPane().getGraphics()); // ouvre une fenetre de dialogue, pas possible de mettre avant dans le gestionnaire de bouton car this ne fait pas référence à la fenetre principale là-bas
        dialog.setVisible(true); // affiche la fenetre de dialogue
    }
    public void dessiner(Graphics g)
    {
        Graphics bufferGraphics;
        Image offscreen;

        // On crée une image en mémoire de la taille du ContentPane
        offscreen = createImage(this.getContentPane().getWidth(),this.getContentPane().getHeight() - toolBar.getHeight());

        // On récupère l'objet de type Graphics permettant de dessiner dans cette image
        bufferGraphics = offscreen.getGraphics();

        // On colore le fond de l'image en blanc
        bufferGraphics.setColor(Color.WHITE);
        bufferGraphics.fillRect(0,0,this.getContentPane().getWidth(), this.getContentPane().getHeight()-toolBar.getHeight());

        // On dessine les objets graphiques de la liste dans l'image en mémoire pour éviter les
        // problèmes de scintillements
        p.dessiner(bufferGraphics);
        // On afficher l'image mémoire à l'écran
        g.drawImage(offscreen,0,toolBar.getHeight(),null);
    }
    private void formMouseClicked(MouseEvent evt) {
        if (!p.getFinie()) {
            // On récupere les coordonnées du pointeur de la souris dans la fenêtre
            int sourisX = evt.getPoint().x;
            int sourisY = evt.getPoint().y - toolBar.getHeight();
            Point choix = p.convertirCoordPos(sourisX, sourisY);

            //choix d'un pion
            if (p.getChoixActif() == 0) {
                //recherche du pion sur la case pointée par la souris
                if (p.selectionPossible(choix)) { //on a cliqué sur un pion de la bonne couleur
                    p.setPos(choix); //on stocke la position du pion choisi dans l'attribut pos de Partie
                    p.deplaPossib(choix); //procédure qui remplie la liste des déplacements possibles
                    p.affichDeplaPossib(p.getListeDeplaPossib(), getContentPane().getGraphics(), toolBar.getHeight());
                    p.setChoixActif(1);
                }
            }

            //choix d'un déplacement
            else if (p.getChoixActif() == 1) {
                if (p.getListeDeplaPossib().contains(choix)) {
                    p.deplacer(p.getPos(), choix); //s'il y a un pion sur la case, appel automatique de la procédure manger
                    p.setPos(p.possibPromo()); //on garde en mémoire la position du pion à transformer
                    if (p.getPos().x != -1) { //il y a une promotion possible
                        dessiner(getContentPane().getGraphics());
                        p.setListeTCFD(p.rechercherPionsTCFD(p.getPos())); //liste des pions : tour, cavalier, fou, dame
                        p.affichPromo(p.getListeTCFD(), getContentPane().getGraphics(), toolBar.getHeight());
                        p.setChoixActif(2); //prochain clic pour le choix de la transformation
                    }
                    else {//au tour du joueur opposé
                        p.setTour(-1 * (p.getTour() - 1)); //tour du joueur opposé : -1*(1-1)=0 et -1*(0-1)=1
                        p.setChoixActif(0);
                        dessiner(getContentPane().getGraphics());
                    }
                }
                else {//on a cliqué sur une case rouge : revient au choix du pion
                    dessiner(getContentPane().getGraphics());
                    p.setChoixActif(0);
                }
            }
            //choix d'une transformation
            else {
                if (choix.x >= 2 && choix.x <= 5 && choix.y == 4) {
                    p.transformer(p.getPos(), p.getListeTCFD().get(choix.x - 2).getPosition());
                    p.setTour(-1 * (p.getTour() - 1)); //tour du joueur opposé : -1*(1-1)=0 et -1*(0-1)=1
                    p.setChoixActif(0);
                    dessiner(getContentPane().getGraphics());
                }
            }
        }
    }
}

package gui;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Point;

public class Echiquier {
    private int taillePlateau = 800; //taille d'un côté de l'échiquier (carré)
    private Case [][] grille = new Case[8][8];
    private Point coinSupGauche = new Point(50, 50);
    public Echiquier(int tPlateau, int cSGX, int cSGY)
    {
        coinSupGauche = new Point(cSGX,cSGY);
        taillePlateau = tPlateau;
        int tailleCase = taillePlateau/8;
        //cases de l'échiquier
        for (int i=0;i<8;i++)
        {
            for (int j=0;j<8;j++)
            {
                Point coinSuperieurGauche = new Point( coinSupGauche.x + i*tailleCase,coinSupGauche.y + j*tailleCase);
                if ((i + j) % 2 == 0) //séparation des cases paires et impaires pour la couleur
                    grille[i][j] = new Case(coinSuperieurGauche,Color.gray,tailleCase);
                else
                    grille[i][j] = new Case(coinSuperieurGauche,Color.lightGray,tailleCase);
            }
        }
    }
    public int getTaillePlateau() {
        return taillePlateau;
    }
    public void setTaillePlateau(int t) {
        taillePlateau = t;
    }
    public Point getCoinSupGauche() {
        return coinSupGauche;
    }
    public void setCoinSupGauche(int x, int y) {
        coinSupGauche = new Point(x,y);
    }
    public Case getCase(int x, int y) {
        return grille[x][y];
    }
    public void dessiner(Graphics g) {
        for (int i=0;i<8;i++)
        {
            for (int j=0;j<8;j++)
                grille[i][j].dessiner(g); //appel de la méthode dessiner des cases
        }
    }
}

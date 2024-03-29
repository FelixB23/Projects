package gui;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Point;

public class Case {
    private int taille = 100; //taille d'un côté du carré
    private Point coinSuperieurGauche;
    private Color couleur;
    public Case(Point p, Color c, int t) {
        taille = t;
        couleur = c;
        coinSuperieurGauche = p;
    }
    public int getTaille() {
        return taille;
    }
    public Point getCoinSuperieurGauche() {
        return coinSuperieurGauche;
    }
    public void dessiner(Graphics g) {
        g.setColor(couleur);
        g.fillRect(coinSuperieurGauche.x,coinSuperieurGauche.y, taille, taille);
    }
}

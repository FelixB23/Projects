package gui.pions;

import java.awt.Graphics;
import java.awt.Point;
import java.util.ArrayList;
import javax.swing.ImageIcon;

public abstract class Piece_mobile {
    protected Point position; //Position du pion dans l'échiquier entre (0,0) et (11,7),
    //les places (8,0),...,(8,7),...,(11,0),...,(11,7) étant réservées aux pions mangés
    protected int type; //0:tour, 1:cavalier, 2:fou, 3:dame, 4:roi, 5:pion
    protected ImageIcon image;
    private int camp; //1 pour blanc et 0 pour noir
    private int nbDepla = 0; //utile pour roque et déplacements des pions simples
    private boolean dernierDepla = false; //true s'il s'agit du dernier pion déplacé (utile pour "en passant")
    public Piece_mobile(Point p, int c) {
        position = p;
        camp = c;
    }
    public Piece_mobile(Piece_mobile p) { //constructeur de recopie pour cloner un pion
        position = p.position;
        camp = p.camp;
        type = p.type;
        image = p.image;
    }
    public Point getPosition() {
        return position;
    }
    public void setPosition(Point p) {
        position = p;
    }
    public int getType() {
        return type;
    }
    public int getCamp() {
        return camp;
    }
    public ImageIcon getImage() {
        return image;
    }
    public int getNbDepla() {
        return nbDepla;
    }
    public void incrementerNbDepla() {
        nbDepla++;
    }
    public boolean getDernierDepla() {
        return dernierDepla;
    }
    public void setDernierDepla(boolean d) {
        dernierDepla = d;
    }
    public void dessiner(Graphics g, Point coinSuperieurGauche, int taille) {
        g.drawImage(image.getImage(), coinSuperieurGauche.x, coinSuperieurGauche.y, taille, taille, null);
    }
    public abstract ArrayList<Point> deplaPossibles();
}



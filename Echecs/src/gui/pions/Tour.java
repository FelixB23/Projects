package gui.pions;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class Tour extends Piece_mobile {
    public Tour(Point p, int c) {
        super(p, c);
        type = 0;
        if (c == 0)
            image = new ImageIcon("images/tour_noir.png");
        else
            image = new ImageIcon("images/tour_blanc.png");
    }
    public Tour(Piece_mobile p) {
        super(p);
    }
    public ArrayList<Point> deplaPossibles() {
        ArrayList<Point> listePos = new ArrayList<Point>();
        for (int i=0;i<8;i++) {
            listePos.add(new Point(position.x,i));
            listePos.add(new Point(i,position.y));
        }
        return listePos;
    }
}

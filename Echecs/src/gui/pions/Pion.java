package gui.pions;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class Pion extends Piece_mobile {
    public Pion(Point p, int c) {
        super(p, c);
        type = 5;
        if (c == 0)
            image = new ImageIcon("images/pion_noir.png");
        else
            image = new ImageIcon("images/pion_blanc.png");
    }
    public ArrayList<Point> deplaPossibles() {
        return null; //méthode jamais utilisée
    }
}

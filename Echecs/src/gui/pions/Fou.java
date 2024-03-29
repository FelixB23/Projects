package gui.pions;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class Fou extends Piece_mobile {
    public Fou(Point p, int c) {
        super(p, c);
        type = 2;
        if (c == 0)
            image = new ImageIcon("images/fou_noir.png");
        else
            image = new ImageIcon("images/fou_blanc.png");
    }
    public Fou(Piece_mobile p) {
        super(p);
    }
    public ArrayList<Point> deplaPossibles() {
        ArrayList<Point> listePos = new ArrayList<Point>();
        for (int i=-7;i<=7;i++) {
            if (position.x + i >= 0 && position.x + i < 8 && position.y + i >= 0 && position.y + i < 8)
                listePos.add(new Point(position.x + i,position.y + i));
            if (position.x + i >= 0 && position.x + i < 8 && position.y - i >= 0 && position.y - i < 8)
                listePos.add(new Point(position.x + i,position.y - i));
        }
        return listePos;
    }
}

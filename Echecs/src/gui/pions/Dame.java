package gui.pions;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class Dame extends Piece_mobile {
    public Dame(Point p, int c) {
        super(p, c);
        type = 3;
        if (c == 0)
            image = new ImageIcon("images/dame_noir.png");
        else
            image = new ImageIcon("images/dame_blanc.png");
    }
    public Dame(Piece_mobile p) {
        super(p);
    }
    public ArrayList<Point> deplaPossibles() {
        ArrayList<Point> listePos = new ArrayList<Point>();
        for (int i=-7;i<=7;i++) {
            if (position.x + i >= 0 && position.x + i < 8 && position.y + i >= 0 && position.y + i < 8)
                listePos.add(new Point(position.x + i,position.y + i));
            if (position.x + i >= 0 && position.x + i < 8 && position.y - i >= 0 && position.y - i < 8)
                listePos.add(new Point(position.x + i,position.y - i));
            if (i>=0) {
                listePos.add(new Point(position.x,i));
                listePos.add(new Point(i,position.y));
            }
        }
        return listePos;
    }

}

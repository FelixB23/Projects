package gui.pions;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class Cavalier extends Piece_mobile {
    public Cavalier(Point p, int c) {
        super(p, c);
        type = 1;
        if (c == 0)
            image = new ImageIcon("images/cavalier_noir.png");
        else
            image = new ImageIcon("images/cavalier_blanc.png");
    }
    public Cavalier(Piece_mobile p) {
        super(p);
    }
    public ArrayList<Point> deplaPossibles() {
        ArrayList<Point> listePos = new ArrayList<Point>();
        for (int i=-1;i<=1;i+=2) {
            for (int j=-2;j<=2;j+=4) {
                if (position.x + i >= 0 && position.x + i < 8 && position.y + j >= 0 && position.y + j < 8)
                    listePos.add(new Point(position.x + i, position.y + j));
                if (position.x + j >= 0 && position.x + j < 8 && position.y + i >= 0 && position.y + i < 8)
                    listePos.add(new Point(position.x + j, position.y + i));
            }
        }
        return listePos;
    }
}
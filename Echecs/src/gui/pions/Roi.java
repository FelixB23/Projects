package gui.pions;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class Roi extends Piece_mobile {
    public Roi(Point p, int c) {
        super(p, c);
        type = 4;
        if (c == 0)
            image = new ImageIcon("images/roi_noir.png");
        else
            image = new ImageIcon("images/roi_blanc.png");
    }
    public ArrayList<Point> deplaPossibles() {
        ArrayList<Point> listePos = new ArrayList<Point>();
        for (int i=-1;i<=1;i++) {
            for (int j=-1;j<=1;j++) {
                if (position.x + i >= 0 && position.x + i < 8 && position.y + j >= 0 && position.y + j < 8)
                    listePos.add(new Point(position.x + i, position.y + j));
            }
        }
        return listePos;
    }

}

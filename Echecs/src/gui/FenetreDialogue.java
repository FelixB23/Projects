package gui;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class FenetreDialogue extends JDialog { // hérite de la classe de fenêtre JDialog, qui est comme JFrame mais moins développée

    private JPanel myContentPane;
    private JLabel lLargeurF, lHauteurF, lCoinSupGaucheFX, lCoinSupGaucheFY, lTaillePlateau, lCoinSupGauchePX, lCoinSupGauchePY, lSaveBDD;
    private JSlider sLargeurF, sHauteurF, sCoinSupGaucheFX, sCoinSupGaucheFY, sTaillePlateau, sCoinSupGauchePX, sCoinSupGauchePY;
    ButtonGroup choixBDD;
    private JRadioButton ouiBDD, nonBDD;
    private JButton bOK, bAnnuler;
    private FenetrePrincipale fp; // pour faire des échanges avec la fenetre principale
    private Partie p;

    public FenetreDialogue(FenetrePrincipale f, Partie par, Graphics g) {
        fp = f;
        p = par;
        int width = 3*fp.getLargeur() / 4;
        int height = 3*fp.getHauteur() / 4;

        setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
        setBounds(fp.getCSGX() + fp.getLargeur() / 8, fp.getCSGY() + fp.getHauteur() / 8, width, height);
        setTitle("Paramètres");

        // Panneau qui va contenir tous les composants
        myContentPane = new JPanel();
        myContentPane.setLayout(null);
        setContentPane(myContentPane);

        //Composant label
        lLargeurF = new JLabel("Largeur de la fenêtre : ");
        lLargeurF.setBounds(width / 20, 0, 9*width / 10, height / 20);
        myContentPane.add(lLargeurF);

        lHauteurF = new JLabel("Hauteur de la fenêtre : ");
        lHauteurF.setBounds(width / 20, 2*height / 18, 9*width / 10, height / 20);
        myContentPane.add(lHauteurF);

        lCoinSupGaucheFX = new JLabel("Abscisse du coin supérieur gauche de la fenêtre :");
        lCoinSupGaucheFX.setBounds(width / 20, 4*height / 18, 9*width / 10, height / 20);
        myContentPane.add(lCoinSupGaucheFX);

        lCoinSupGaucheFY = new JLabel("Ordonnée du coin supérieur gauche de la fenêtre :");
        lCoinSupGaucheFY.setBounds(width / 20, 6*height / 18, 9*width / 10, height / 20);
        myContentPane.add(lCoinSupGaucheFY);

        lTaillePlateau = new JLabel("Taille de l'échiquier : ");
        lTaillePlateau.setBounds(width / 20, 8*height / 18, 9*width / 10, height / 20);
        myContentPane.add(lTaillePlateau);

        lCoinSupGauchePX = new JLabel("Abscisse du coin supérieur gauche de l'échiquier :");
        lCoinSupGauchePX.setBounds(width / 20, 10*height / 18, 9*width / 10, height / 20);
        myContentPane.add(lCoinSupGauchePX);

        lCoinSupGauchePY = new JLabel("Ordonnée du coin supérieur gauche de l'échiquier :");
        lCoinSupGauchePY.setBounds(width / 20, 12*height / 18, 9*width / 10, height / 20);
        myContentPane.add(lCoinSupGauchePY);

        lSaveBDD = new JLabel("Enregistrer les scores dans la base de données :");
        lSaveBDD.setBounds(width / 20, 14*height / 18, 9*width / 10, height / 20);
        myContentPane.add(lSaveBDD);

        Font police = new Font("Comic Sans MS", Font.PLAIN, height/30);
        lLargeurF.setFont(police);
        lHauteurF.setFont(police);
        lCoinSupGaucheFX.setFont(police);
        lCoinSupGaucheFY.setFont(police);
        lTaillePlateau.setFont(police);
        lCoinSupGauchePX.setFont(police);
        lCoinSupGauchePY.setFont(police);
        lSaveBDD.setFont(police);

        //Sliders
        sLargeurF = new JSlider(400, 2000, fp.getLargeur());
        sLargeurF.setBounds(width / 6, height / 18, 2*width / 3, height / 15);
        sLargeurF.setMinorTickSpacing(40);
        sLargeurF.setMajorTickSpacing(200);
        sLargeurF.setPaintTicks(true);
        sLargeurF.setPaintLabels(true);
        myContentPane.add(sLargeurF);

        sHauteurF = new JSlider(400, 1600, fp.getHauteur());
        sHauteurF.setBounds(width / 6, 3*height / 18, 2*width / 3, height / 15);
        sHauteurF.setMinorTickSpacing(40);
        sHauteurF.setMajorTickSpacing(200);
        sHauteurF.setPaintTicks(true);
        sHauteurF.setPaintLabels(true);
        myContentPane.add(sHauteurF);

        sCoinSupGaucheFX = new JSlider(0, 800, fp.getCSGX());
        sCoinSupGaucheFX.setBounds(width / 6, 5*height / 18, 2*width / 3, height / 15);
        sCoinSupGaucheFX.setMinorTickSpacing(40);
        sCoinSupGaucheFX.setMajorTickSpacing(200);
        sCoinSupGaucheFX.setPaintTicks(true);
        sCoinSupGaucheFX.setPaintLabels(true);
        myContentPane.add(sCoinSupGaucheFX);

        sCoinSupGaucheFY = new JSlider(0, 800, fp.getCSGY());
        sCoinSupGaucheFY.setBounds(width / 6, 7*height / 18, 2*width / 3, height / 15);
        sCoinSupGaucheFY.setMinorTickSpacing(40);
        sCoinSupGaucheFY.setMajorTickSpacing(200);
        sCoinSupGaucheFY.setPaintTicks(true);
        sCoinSupGaucheFY.setPaintLabels(true);
        myContentPane.add(sCoinSupGaucheFY);

        sTaillePlateau = new JSlider(200, 1400, p.getEchiquier().getTaillePlateau());
        sTaillePlateau.setBounds(width / 6, 9*height / 18, 2*width / 3, height / 15);
        sTaillePlateau.setMinorTickSpacing(40);
        sTaillePlateau.setMajorTickSpacing(200);
        sTaillePlateau.setPaintTicks(true);
        sTaillePlateau.setPaintLabels(true);
        myContentPane.add(sTaillePlateau);

        sCoinSupGauchePX = new JSlider(0, 300, p.getEchiquier().getCoinSupGauche().x);
        sCoinSupGauchePX.setBounds(width / 6, 11*height / 18, 2*width / 3, height / 15);
        sCoinSupGauchePX.setMinorTickSpacing(10);
        sCoinSupGauchePX.setMajorTickSpacing(50);
        sCoinSupGauchePX.setPaintTicks(true);
        sCoinSupGauchePX.setPaintLabels(true);
        myContentPane.add(sCoinSupGauchePX);

        sCoinSupGauchePY = new JSlider(0, 300, p.getEchiquier().getCoinSupGauche().y);
        sCoinSupGauchePY.setBounds(width / 6, 13*height / 18, 2*width / 3, height / 15);
        sCoinSupGauchePY.setMinorTickSpacing(10);
        sCoinSupGauchePY.setMajorTickSpacing(50);
        sCoinSupGauchePY.setPaintTicks(true);
        sCoinSupGauchePY.setPaintLabels(true);
        myContentPane.add(sCoinSupGauchePY);

        //Radio Button
        choixBDD = new ButtonGroup();

        ouiBDD = new JRadioButton("Oui", p.getSaveBDD());
        ouiBDD.setBounds(width / 6, 15*height / 18, width / 6, height / 20);
        ouiBDD.setFont(police);
        choixBDD.add(ouiBDD);
        myContentPane.add(ouiBDD);

        nonBDD = new JRadioButton("Non", !p.getSaveBDD());
        nonBDD.setBounds(3*width / 6, 15*height / 18, width / 6, height / 20);
        nonBDD.setFont(police);
        choixBDD.add(nonBDD);
        myContentPane.add(nonBDD);

        // Composant Bouton: OK
        bOK = new JButton("OK");
        bOK.setBounds(width / 6, 16*height / 18, width / 6, height / 20);
        myContentPane.add(bOK);
        bOK.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                modifier(g);
            }
        });

        // Composant Bouton: Annuler
        bAnnuler = new JButton("Annuler");
        bAnnuler.setBounds(4*width / 6, 16*height / 18, width / 6, height / 20);
        myContentPane.add(bAnnuler);
        bAnnuler.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dispose();
            }
        });

    }
    public void modifier(Graphics g) {
        p.getEchiquier().setTaillePlateau(sTaillePlateau.getValue());
        p.getEchiquier().setCoinSupGauche(sCoinSupGauchePX.getValue(),sCoinSupGauchePY.getValue());
        fp.setLargeur(sLargeurF.getValue());
        fp.setHauteur(sHauteurF.getValue());
        fp.setCSGX(sCoinSupGaucheFX.getValue());
        fp.setCSGY(sCoinSupGaucheFY.getValue());
        fp.setBounds(fp.getCSGX(),fp.getCSGY(),fp.getLargeur(),fp.getHauteur());
        p.mettreAJour(sTaillePlateau.getValue(),sCoinSupGauchePX.getValue(),sCoinSupGauchePY.getValue(),ouiBDD.isSelected());
        fp.dessiner(g);
        dispose(); // détruit la fenêtre
    }
}
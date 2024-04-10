package code;

import java.util.Scanner;

public class Prog {

	public static void main(String[] args)
	{
		int largeur, hauteur, nbPionsAAligner, col;
		Scanner lire = new Scanner(System.in);
		do
		{
			System.out.println("Entrez la largeur de la grille (entre 4 et 9): ");
			largeur = lire.nextInt();
		}
		while (largeur<4 || largeur>9);
		
		do
		{
			System.out.println("Entrez la hauteur de la grille (entre 4 et 9): ");
			hauteur = lire.nextInt();
		}
		while (hauteur<4 || hauteur>9);
		
		do
		{
			System.out.println("Choisir le nombre de pions a aligner pour gagner (entre 3 et 9): ");
			nbPionsAAligner = lire.nextInt();
		}
		while (nbPionsAAligner<3 || nbPionsAAligner>9);
		
		Partie p = new Partie(hauteur, largeur, nbPionsAAligner); //creation de la partie
		System.out.println(p.afficher());
		
		while(!(p.partieFinie()))
		{
			do
			{
				System.out.println("Joueur rouge 'X': entrez une colonne (entre 0 et " + (largeur-1) + "): ");
				col = lire.nextInt();
			}
			while (!(p.coupPossible(col)));
			p.jouer(col);
			System.out.println(p.afficher());
			if (!(p.partieFinie())) //on s'arrete si le joueur rouge a gagne
			{
				do
				{
					System.out.println("Joueur jaune 'O': entrez une colonne (entre 0 et " + (largeur-1) + "): ");
					col = lire.nextInt();
				}
				while (!(p.coupPossible(col)));
				p.jouer(col);
				System.out.println(p.afficher());
			}
		}
		lire.close();
		if (p.gagne())
			System.out.println("Gagne !");
		else
			System.out.println("Egalite !");
	}
}
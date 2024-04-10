package code;

public class Partie {
	
	//Attributs
	private int m_largeur = 7;
	private int m_hauteur = 6;
	private int m_nbPionsAAligner = 4;
	private Grille m_g;
	private int m_joueur = 1;
	
	//Methods
	public Partie(int hauteur, int largeur, int nbPionsAAligner) 
	{
		m_nbPionsAAligner = nbPionsAAligner;
		m_largeur = largeur;
		m_hauteur = hauteur;
		m_g = new Grille(m_largeur, m_hauteur);
	}
	
	public int getJoueur() 
	{
		return m_joueur;
	}
	
	public String afficher() 
	{
		return m_g.afficher();
	}
	
	public boolean ligneDroite(int i, int j) 
	{
		int k=1;
		Case c;
		c = m_g.getCase(i,j);
		if (c instanceof CaseRouge)
		{
			while (j+k<m_largeur && k<m_nbPionsAAligner && m_g.getCase(i,j+k) instanceof CaseRouge) 
				k++;
			if (k==m_nbPionsAAligner)
				return true;
		}
		else if (c instanceof CaseJaune)
		{
			while (j+k<m_largeur && k<m_nbPionsAAligner && m_g.getCase(i,j+k) instanceof CaseJaune) 
				k++;
			if (k==m_nbPionsAAligner)
				return true;
		}
		return false;
	}
	
	public boolean ligneBas(int i, int j) 
	{
		int k=1;
		Case c = m_g.getCase(i,j);
		if (c instanceof CaseRouge) 
		{
			while (i+k<m_hauteur && k<m_nbPionsAAligner && m_g.getCase(i+k,j) instanceof CaseRouge)
				k++;
			if (k==m_nbPionsAAligner)
				return true;
		}
		else if (c instanceof CaseJaune)
		{
			while (i+k<m_hauteur && k<m_nbPionsAAligner && m_g.getCase(i+k,j) instanceof CaseJaune)
				k++;
			if (k==m_nbPionsAAligner)
				return true;
		}
		return false;
	}
	
	public boolean ligneBasDroite(int i, int j) 
	{
		int k=1;
		Case c = m_g.getCase(i,j);
		if (c instanceof CaseRouge) 
		{
			while (i+k<m_hauteur && j+k<m_largeur && k<m_nbPionsAAligner && m_g.getCase(i+k,j+k) instanceof CaseRouge)
				k++;
			if (k==m_nbPionsAAligner)
				return true;
		}
		else if (c instanceof CaseJaune)
		{
			while (i+k<m_hauteur && j+k<m_largeur && k<m_nbPionsAAligner && m_g.getCase(i+k,j+k) instanceof CaseJaune)
				k++;
			if (k==m_nbPionsAAligner)
				return true;
		}
		return false;
	}
	
	public boolean ligneBasGauche(int i, int j) 
	{
		int k=1;
		Case c = m_g.getCase(i,j);
		if (c instanceof CaseRouge) 
		{
			while (i+k<m_hauteur && j-k>=0 && k<m_nbPionsAAligner && m_g.getCase(i+k,j-k) instanceof CaseRouge)
				k++;
			if (k==m_nbPionsAAligner)
				return true;
		}
		else if (c instanceof CaseJaune)
		{
			while (i+k<m_hauteur && j-k>=0 && k<m_nbPionsAAligner && m_g.getCase(i+k,j-k) instanceof CaseJaune)
				k++;
			if (k==m_nbPionsAAligner)
				return true;
		}
		return false;
	}
	
	public boolean gagne() 
	{
		boolean t=false;
		int i=0, j;
		while (i<m_hauteur && t==false)
		{
			j=0;
			while (j<m_largeur && t==false)
			{
				if (ligneDroite(i,j) || ligneBas(i,j) || ligneBasDroite(i,j) || ligneBasGauche(i,j))
					t=true;
				j++;
			}
			i++;
		}
		return t;
	}
	
	public boolean partieFinie()
	{
		if (gagne()|| m_g.pleine()) {
			return true;
		}
		return false;	
	}
	
	public boolean coupPossible(int colonne)
	{
		if (colonne>=0 && colonne<m_largeur) //on est bien dans la grille
		{
			//Si la premiere case de la colonne est vide, c'est qu'il reste de la place
			if (m_g.getCase(0,colonne) instanceof CaseVide)
				return true;
		}
		return false;
	}
	
	public void jouer(int colonne) //pre-condition : coupPossible(col)
	{
		int k=m_hauteur-1;
		while (!(m_g.getCase(k,colonne) instanceof CaseVide))
			k--;
		if (m_joueur==1)
		{
			CaseRouge c = new CaseRouge();
			m_g.setCase(k, colonne, c);
			m_joueur = 2;
		}
		else
		{
			CaseJaune c = new CaseJaune();
			m_g.setCase(k, colonne, c);
			m_joueur = 1;
		}
	}
}
package code;
import java.util.HashMap;

public class Grille {
	
	private int m_largeur = 7;
	private int m_hauteur = 6;
	private HashMap<Coordonnees,Case> m_cases;
	
	public Grille(int largeur,int hauteur)
	{
		m_largeur = largeur;
		m_hauteur = hauteur;
		m_cases = new HashMap<Coordonnees,Case>();
		for (int i=0;i<m_hauteur;i++)
		{
			for (int j=0;j<m_largeur;j++)
			{
				Coordonnees coord = new Coordonnees();
				coord.setI(i);
				coord.setJ(j);
				m_cases.put(coord, new CaseVide(i,j)); 
			}
		}
	}
	
	public Case getCase(int i, int j)
	{
		Coordonnees coord = new Coordonnees();
		coord.setI(i);
		coord.setJ(j);
		return m_cases.get(coord);
	}
	
	public void setCase(int i, int j, Case c)
	{
		Coordonnees coord = new Coordonnees();
		coord.setI(i);
		coord.setJ(j);
		this.m_cases.put(coord,c);
	}
	
	public String afficher()
	{
		//premiere ligne
		String aff = new String();
		aff = "---";
		
		for (int j=0;j<m_largeur;j++)
			aff += "-" + "0" + j + "-";
		aff += "-\n";
		
		//lignes du milieu
		for (int i=0;i<m_hauteur;i++)
		{
			aff += "0" + i + "|";
			for (int j=0;j<m_largeur;j++)
				aff += getCase(i,j).afficher();
			aff += "|\n";
		}
		
		//derniere ligne
		aff += "----";
		for (int j=0;j<m_largeur;j++)
			aff += "----";
		aff += "\n";
		return aff;
	}
	
	public boolean pleine()
	{
		boolean p = true;
		int i=0, j=0;
		while (p==true && i<m_hauteur)
		{
			while (p==true && j<m_largeur)
			{
				//si la case est vide
				if (getCase(i,j) instanceof CaseVide)
					p = false;
				j++;
			}
			i++;
		}
		return p;
	}
}
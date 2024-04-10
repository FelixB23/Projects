package code;

public abstract class Case {
	
	//attributs
	private Coordonnees m_p;
	
	//methodes
	public Case() 
	{
		Coordonnees m_p = new Coordonnees();
	}
	
	public Case(int i, int j)
	{
		Coordonnees m_p = new Coordonnees();
		m_p.setI(i);
		m_p.setJ(j);
	}
	
	public int getI() {
		return m_p.getI();
	}
	
	public int getJ() {
		return m_p.getJ();
	}
	

	//methode abstraite
	public abstract String afficher();
}
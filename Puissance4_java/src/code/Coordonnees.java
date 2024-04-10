package code;

public class Coordonnees {
	
	private int m_i = 0;
	private int m_j = 5;
	
	public Coordonnees()
	{

	}
	
	public int getI()
	{
		return m_i;
	}
	
	public void setI(int i)
	{
		this.m_i = i;
	}
	
	public int getJ()
	{
		return m_j;
	}
	
	public void setJ(int j)
	{
		this.m_j = j;
	}
	
	@Override
	public boolean equals(Object o) 
	{
		if (o == null)
			return false;
		else
		{
			if (o instanceof Coordonnees)
				return (((Coordonnees) o).m_i==m_i && ((Coordonnees) o).m_j==m_j);
			else
				return false;
		}
	}

	@Override
	public int hashCode() 
	{
		return m_i*10 + m_j; //renvoie un code different j
	}

}

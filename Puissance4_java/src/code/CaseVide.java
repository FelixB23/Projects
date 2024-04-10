package code;

public class CaseVide extends Case {
	
	public CaseVide() 
	{
		super();
	}
	
	public CaseVide(int i, int j) 
	{
		super(i,j);
	}
	
	@Override 
	public String afficher() {	
		return "    ";
	}
}
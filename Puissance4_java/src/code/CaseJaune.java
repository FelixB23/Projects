package code;

public class CaseJaune extends Case {
	
	public CaseJaune() 
	{
		super();
	}
	
	public CaseJaune(int i, int j) 
	{
		super(i,j);
	}
	
	@Override 
	public String afficher() {	
		return "  O ";
	}
}
package code;

public class CaseRouge extends Case {
	
	public CaseRouge() 
	{
		super();
	}
	
	public CaseRouge(int i, int j) 
	{
		super(i,j);
	}
		
	@Override 
	public String afficher() {	
		return "  X ";
	}
}
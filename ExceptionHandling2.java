import java.util.*;

class MyException extends Exception{
	
}
	//----------------------------------------------

public class ExceptionHandling2 {
	
	public static int m() {
		try {
			return 1;
			//throw new Exception(); //even if you do this because there is finally, it will output 10
		}
		catch (Exception e) {
			return 2;
		}
		finally {
			return 10;
		}
	}
	
	//----------------------------------------------

	public static void main(String[] array) {
		
		
		try {
			throw new MyException();
		}
		catch(MyException me) {
			System.out.println("Works!");
		}
		
		//System.out.println(m()); //will print 10 from method above
		
		try {
			
			//some code
			try {
				//int i = Integer.parseInt("Hi"); //will print "Inside"
				
				//String name = null;
				//System.out.println(((String)null).length()); //will print "Outside"
				
				//System.out.println("abc".length());
				//return; //will print 3 "Finally..."
				
			}
			catch(NumberFormatException nfe) {
				System.out.println("Inside");
			}
			
		}
		catch (ArrayIndexOutOfBoundsException npe) {
			System.out.println("Outside again");
			
		/*catch (NullPointerException nps){
			System.out.println("Outside");*/
		}
		
		finally {
			System.out.println("Finally...");
		}
		
		System.out.println("Done!");

	}

}
//Exceptions that will make a program crash

//import java.util.*;
//import java.util.InputMismatchException;
import java.util.Scanner;
//import java.io.*;

public class ExceptionHandling {
	
	public static void main (String[] params) /*throws Exception*/ {
	
		//Example 1: array index out of bounds exception
		//int[] array = {1,6,9};
		//System.out.println(array[3]);
		
		//Example 2: null pointer running a nonstatic method
		//String name = null; //pointer pointing to nothing
		//System.out.println(name.length()); //theres no length to the string because it is null
		//will create a null pointer exception
		
		//Example 3: class cast exception
		/*Parent ref;
		ref = new Child2();
		((Child1) ref).m();*/
		
		//Example 4: string index out of bounds
		//String name = "Emma";
		//System.out.println(name.charAt(10));
		
		//Example 5: divide by 0; arithmetic exception
		//System.out.println(1/0);
		
		//Example 6: illegal state exception
		/*Scanner s = new Scanner(System.in);
		int i;
		System.out.println("Enter a number: ");
		s.close;
		i = s.nextInt();*/	
		
		//Example 7: file not found exception
		/*File myFile = new File("abc.dat");
		try {
			Scanner scanner = new Scanner(myFile);
		}catch (Exception e) {
			//some code goes here...
		}*/

		Scanner s = new Scanner(System.in);
		
		String input;
		int age = 0;
		boolean goAgain = true;
		
		while(goAgain) {
		
		try{
			goAgain = false;
			System.out.println("Enter age: ");
			input = s.nextLine();
			age = Integer.parseInt(input);
			
		}catch (Exception e) {
			System.out.println("Invalid age!");
			goAgain = true;
		}
	}
		System.out.println("Your age is " + age);
		//-----------------------------------------
		/*int i;
		String name = "abc";
		int [] array = {1};
		
		try {
			System.out.println(array[0]);
			System.out.println(name.length());
			System.out.println("Enter a number: ");
			i = s.nextInt();
			System.out.println("You entered: " + i);	
		}catch (NullPointerException npe) {
			System.out.println(npe.getMessage());
		}catch(InputMismatchException ime) {
			System.out.println(ime.getMessage());
		}catch (Exception e) {
			System.out.println(e);
		}	
		finally {
			System.out.println("This is reached regardless!");
		}
		System.out.println("Something bad happened!");*/
	}
}

class Parent{
	
}

class Child1 extends Parent{
	public void m() {
		System.out.println("Child 1...");
	}
}

class Child2 extends Parent{
	
}
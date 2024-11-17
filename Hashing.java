//Hashing - mapping data to integers

import java.util.*;

public class Hashing {

	public static void main(String[] args) {
		
		//System.out.println("abc".hashCode());
		//System.out.println("XXXXZZZzaasgad".hashCode());
		
		/*String [] names = new String[10];
		int index = "abc".hashCode();
		
		names[index%10] = "abc";
		
		for(String name : names) {
			System.out.println(name);
		}*/
		
		/*Employee e = new Employee();
		System.out.println(e.hashCode());*/
		
		ArrayList<String> [] names = new ArrayList[5];
		
		for(int i = 0; i < 5; i++) {
			names[i] = new ArrayList<>();
		}
		
		names[("Erick".hashCode())%5].add("Erick");
		names[("John".hashCode())%5].add("John");
		names[("Emma".hashCode())%5].add("Emma");
		
		for(int i = 0; i < 5; i++) {
			System.out.println(names[i]);
		}
	}

}

class Employee{
	
}
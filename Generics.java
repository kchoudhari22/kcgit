import java.util.ArrayList;

public class Generics {
	
	/*private static void doSomething(Integer i) {
		System.out.println(i);
	}
	
	private static void doSomething(Boolean i) {
		System.out.println(i);
	}*/
	
	/*private static <T,W> void doSomething(T i, W j) {
		System.out.println(i + " " + j);
	}*/
	
	/*private static <T> void anotherMethod (ArrayList <T> myList) {
		System.out.println(myList);
	}*/
	
	/*private static <T> void anotherMethod (ArrayList <T> myList) {
		System.out.println(myList);
	}*/

	public static void main(String[] args) {
		/*DisplayInteger myInt = new DisplayInteger(20);
		DisplayEmployee myEmp = new DisplayEmployee (new Worker());
		
		myInt.display();
		myEmp.display();*/
		
		//DisplayData <Integer> myInt = new DisplayData<>(20);
		//DisplayData <Employee> myEmp = new DisplayData<> (new Employee());
		//DisplayData <Manager> myMan = new DisplayData<> (new Manager());
		
		//myInt.display();
		//myEmp.display();
		//myMan.display();
		
		//DisplayData<MyClass> myClass = new DisplayData <>(new MyClass());
		//myClass.display();
		
		//DisplayData <Manager> myMan = new DisplayData<> (new Manager());
		//myMan.display();
		
		//doSomething(12);
		//doSomething(new Manager());
		//doSomething(new Manager(), 23);
		
		/*ArrayList<Boolean> list = new ArrayList<>();
		list.add(true);
		list.add(false);
		anotherMethod(list);*/
		
		//DisplayData <Manager, Integer> myManager = new DisplayData<> (new Manager());
	}
}
interface MyInterface{
	public void method();
}

class MyClass implements MyInterface{
	public void method() {
		System.out.println("Nothing...");
	}
	
}

class Employee{
	public String toString() {
		return "Employee";
	}
}

class Manager extends Employee implements MyInterface{
	public String toString() {
		return "Manager";
	}
	
	public void method() {
		System.out.println("Manager do nothing...");
	}
	
}

class DisplayData <T extends Employee & MyInterface, W>{
	private T data;
	private W anotherdata;
	
	public DisplayData (T data) {
		this.data= data;
	}
	
	public void display () {
		System.out.println(data);
	}
}

class DisplayInteger{
	private Integer data;
	public DisplayInteger (Integer data) {
		this.data= data;
	}
	
	public void display () {
		System.out.println(data);
	}
}

class DisplayEmployee{
	private Employee data;
	public DisplayEmployee (Employee data) {
		this.data= data;
	}
	
	public void display () {
		System.out.println(data);
	}
}
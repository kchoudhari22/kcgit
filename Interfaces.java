import java.util.Comparator;

public class Interfaces {
	
	public static void main(String[] args) {
		
		//Payable ref;
		//ref = new Salaried ("John", 200.5);
		//System.out.println(ref instanceof Salaried);
		
		/*Salaried s1 = new Salaried("Larry", 100), s2 = new Salaried("Emma", 50);
		System.out.println(s1.compareTo(s2));
		System.out.println(s2.compareTo(s1));*/
		
		/*Salaried n1 = new Salaried ("abc", 100),
				n2 = new Salaried ("bcd", 50);
		int n = (new SortByName()).compare(n1,n2);
		System.out.println(n);*/
		//returns -1 because the strings are not the same
		
		Salaried m1 = new Salaried ("abc", 100),
				m2 = new Salaried ("bcd", 50);
		int m = (new SortBySalary()).compare(m1,m2);
		System.out.println(m);
		//returns 1 because 100 is bigger than 50
	}
}

interface Doable{
	public void abstractMethod();
}
interface Payable{
	public final int cost = 200;
	abstract public void pay();
}

class SortByName implements Comparator<Salaried>{

	@Override
	public int compare(Salaried s1, Salaried s2) {
		return (s1.getName()).compareTo(s2.getName());
	}
}

class SortBySalary implements Comparator<Salaried>{
	
	@Override
	public int compare(Salaried s1, Salaried s2) {
		if (s1.getSalary() > s2.getSalary())
			return 1;
		if (s1.getSalary() < s2.getSalary())
			return -1;
		return 0;
	}
}

class Salaried extends Employee implements Payable, Doable, Comparable<Salaried>{
	
	private double salary;

	public Salaried(String name, double salary) {
		super(name);
		//System.out.println(cost);
		this.salary = salary;
	}
	
	@Override
	public void pay() {
		System.out.println("Paying a Salaried.");
	}
	
	@Override
	public void abstractMethod() {
		System.out.println("Some code goes here...");
	}
	
	public int compareTo (Salaried salaried) {
		return(int)(this.salary - salaried.salary);
	}
	
	public double getSalary() {
		return salary;
	}
}

class Volunteer extends Employee{
	
	private int hours;
	private int salary;

	public int getHours() {
		return hours;
	}

	public void setHours(int hours) {
		this.hours = hours;
	}

	public Volunteer(String name, int hours) {
		super(name);
		this.hours = hours;
	}
	
	@Override
	public String toString() {
		return "Volunteer [hours=" + hours + "]";
	}
	
}

class Employee{
	
	private String name;
	
	public Employee(String name) {
		super();
		this.name = name;
	}
	
	public String getName() {
		return name;
	}
}
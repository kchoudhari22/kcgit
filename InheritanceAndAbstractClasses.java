//Inheritance Notes
//Code based on hierarchy
//Make the class abstract, for inheritance purposes

//Employee Class: id, name (what is common to all employees)
//Salary Employees: id, name, a salary		Hourly Employees: id, name, numbers of hours worked and the wage
//Managers: id, name salary, a bonus
//Supervisors: id, name, salary, bonus

import java.util.ArrayList;

public class InheritanceAndAbstractClasses {

	public static void main(String[] args) {
		
		/*Employee e = new Employee("John Jones", "1222");
		System.out.println(e);*/
		
		/*HourlyPaid hp = new HourlyPaid ("Jenna", "2352", 1, 1); //name, id, wage, hoursWorked
		hp.printCheck();*/
		
		Company company = new Company(); //creates a company object
		//company.printEmployees();
		//company.printCheck("1111"); //prints hourly employee Kim
		
		company.deleteByBonus(10); //will delete the manger with bonus more than 10$
		company.printEmployees(); //will print all employees
		
		
		//prints a managers information
		/*Employee e;
		e = new Manager ("David", "12544", 12.3, 1.3); //creates a new Manager object
		//((Manager)e).chill(); //calls chill method in Manager class
		e.printCheck();*/
		
		//Making an array of 1000 employees
		//And then making index 45 Sal empoyee/info
		//Printing check for Sal
		//Making Sal a manager and making him chill
		
		/*Employee [] arr = new Employee [1000];
		//You can do this instead of the line above
		//Object [] arr = new Object [1000];
		arr [45] = new Salaried ("Sal", "232", 253.3);
		((Salaried) arr [45].printCheck();
		((Manager)arr [45]).chill();
		if (arr[45] instanceof Manager)((Manager)arr[45]).chill();*/
	}

}

class Company{
	private ArrayList <Employee> list;

	public Company() {
		list = new ArrayList<>();
		list.add(new HourlyPaid ("Kim", "1111", 12, 3)); //integers are hours, wage
		list.add(new HourlyPaid ("Jon", "111", 10, 60));
		list.add(new Salaried ("Jenna", "222", 522)); //integer is salary
		list.add(new Manager ("Malik", "333", 125, 6.5)); //integers are salary and bonus
		list.add(new Manager ("Rich", "3333", 125, 66.5));
	}
	
	public void addEmployee (Employee e) {
		list.add(e);
	}
	
	public void deleteEmployee (String id) { //delete an employee based on their id
		int size = list.size();
		for (int i = 0; i < size; i++) {
			if(list.get(i).getId().compareTo(id) == 0) { //will compare the strings of ids to see if its the right employee to remove
				list.remove(i);
				break;	
			}
		}
	}
	
	//If managers reach 7$ or more in bonus we delete them
	public void deleteByBonus(double limit) {
		int size = list.size();
		for(int i = 0; i < size; i++) {
			if(list.get(i) instanceof Manager && ((Manager)list.get(i)).getBonus() > limit) {
				list.remove(i);
				i --;
				size --;
			}
		}
	}
	
	public void printCheck(String id) {
		int size = list.size();
		for(int i = 0; i < size; i++) {
			if(list.get(i).getId().compareTo(id) == 0) { //will compare the strings of ids to see if its the right employee to remove
				(list.get(i)).printCheck();
				break;	
			}
		}
	}
	
	public void printEmployees() {
		System.out.println(list);
	}
} //end of Company class

class Manager extends Salaried{
	private double bonus;

	public double getBonus() {
		return bonus;
	}

	public void setBonus(double bonus) {
		this.bonus = bonus;
	}

	public Manager(String name, String id, double salary, double bonus) {
		super(name, id, salary);
		this.bonus = bonus;
	}
	
	public void chill() {
		System.out.println("Chilling...");
	}
	
	@Override
	public void printCheck() {
		super.printCheck();
		System.out.println("Bonus: " + bonus);
	}
	
	public String toString() {
		return "Manager Paid \\" + super.toString();
	}
} //end of Manager class

class Salaried extends Employee{
	private double salary;
	
	public Salaried (String name, String id, double salary) {
		super(name, id);
		this.salary = salary;
	}
	
	@Override
	public void printCheck() {
		//System.out.println("Salary Paid: " + toString());
		super.printCheck();
		System.out.println("Salary is: " + salary);
	}
	
	public String toString() {
		return "Salaried Paid\\" + super.toString();
	}
}//end of Salaried class

//extends means everything public, or protected, inside the class Employee
//will be visible inside the HourlyPaid class
class HourlyPaid extends Employee{
	double wage;
	double hoursWorked;
	
	//You can generate this constructor or you can...
	/*public HourlyPaid(String name, String id, double wage, double hoursWorked) {
		super(name, id);
		this.wage = wage;
		this.hoursWorked = hoursWorked;
	}*/
	
	//...Explicitly call
	public HourlyPaid (String name, String id, double wage, double hoursWorked) {
		super(name, id);
		this.wage = wage;
		this.hoursWorked = hoursWorked;		
	}
	
	public HourlyPaid() {
		super("No name", "No id");
		wage = -1;
		hoursWorked = -1;
	}
	
	//print check
	public void printCheck() {
		double grossPay = wage *hoursWorked;
		double netPay = grossPay * .94; //6% tax reduction
		//will go to the parent Employee class toString and return name and id
		//System.out.println("Hourly Paid: " + super.toString());
		super.printCheck();
		System.out.println("Gross pay: " + grossPay);
		System.out.println("Net pay: " + netPay);
	}
	
	public String toString() {
		return "Hourly Paid\\" + super.toString();
	}
	
}//end of HourlyPaid class

//Employee class will be the super class that you will inherit from
//You cannot inherit from two classes
abstract class Employee{
	//data should always be private
	private String name;
	private String id;
	
	//setters and getters
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	
	//constructor
	public Employee(String name, String id) {
		//super(); don't need this line
		this.name = name;
		this.id = id;
	}
	
	//toString
	@Override
	public String toString() {
		//return "Employee [name=" + name + ", id=" + id + "]"; //original line of code
		return "[Name=" + name + ", ID=" + id + "]"; //removed Employee word
	}
	
	public void printCheck() {
		System.out.println("\n-----------------------\n");
		System.out.println("Name: " + name);
		System.out.println("ID: " + id);
		
	}
	
} //end of Employee class

//Review questions on inheritance

public class Questions {
	
	//two different methods will the same name is overloading
		public static void mainMethod(Child c) {
			System.out.println("This is the child version...");
			c.print();
		}
		
		public static void mainMethod(Parent p) {
			System.out.println("This is the parent version...");
			p.print();
			
		}

	public static void main(String[] args) {
		
		/*Parent p = new Parent();
		p.print();*/
		//will print "Parent printing"...
		
		/*Child c = new Child();
		c.print();*/
		//will print "Parent printing"... because of inheritance
		
		/*Parent pc;
		pc = new Child();
		pc.print();*/
		//will print "Child printing..." because it will go to the @Override
		
		//pc.anotherPrint(); //this does not work because pc is of type Parent class
		//and it does not see it; in order to fix this you have to cast this to Child
		//like so...
		//((Child)pc).anotherPrint();
		//will print "Special Child Printing..."
		
		/*Parent p = new Parent();
		mainMethod(p);*/
		//will print "This is the parent version..."
		
		/*Child c = new Child();
		mainMethod(c);*/
		//will print "This is the child version..."
		
		/*Child c = new Child();
		mainMethod(c);*/
		//will print from the @Override print
		//and will print "Child printing..."
		
		/*Parent p = new Parent();
		mainMethod(p);*/
		//will print "Parent printing..." from Parent class
		
		//Parent pc = new Child();
		//this is a reference of type Parent to a Child object so
		//in this case the method on the next line will run the
		//overridden (@Override) print method in the Child class
		//mainMethod(pc); //the mainMethod(Parent p) fnct will be called
		//because it is passing pc of type Parent but it
		//will print "Child printing..." though because it will take the
		//reference of type Parent that is printing to a child object
		//and then it will run the @Override print inside Child class
		
		/*Child c = new Child();
		c.someMethod();*/
		//will print "Child printing..."
		
		/*Parent p = new Parent();
		p.someMethod();*/
		//this will work because someMethod is inside the class Parent
		//will print "Parent printing..."
		
		/*Parent pc = new Child();
		pc.someMethod();*/
		//will print "Child printing..."
	}

}

class Parent{
	public void print() {
		System.out.println("Parent printing...");
	}
	
	public void someMethod() {
		print(); //will call the print coming from Parent
		//and will be inherited by the class Child, so it is visible to both
	}
}

class Child extends Parent{
	
	@Override
	public void print() {
		System.out.println("Child printing...");
		
	}
	
	public void anotherPrint() {
		System.out.println("Special Child Printing...");
	}
}

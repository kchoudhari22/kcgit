/*Katelyn Choudhari
  COP3330
  Unit 9 Homework
  04-14-2024*/

public class DriverClass {
    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.addNewEmployee(new Employee ("Kim Oz", 1235.5, 3));
        list.addNewEmployee(new Employee ("Rim Oz", 8235.5, 1));
        list.addNewEmployee(new Employee ("Dane Ali ", 3235.5, 0));
        list.addNewEmployee(new Employee ("Aidan Jones ", 2035.5, 2));
        list.addNewEmployee(new Employee ("Nadia Jones", 5035.5, 3));
        list.addNewEmployee(new Employee ("Ed Renu", 6035, 2));
        list.addNewEmployee(new Employee ("Naadi Jones", 36035.75, 5));

        list.printAllEmployees();
        System.out.println("The highest net salary = " + list.highestNetSalary());
    
        list.deleteEmployeeByName("Rim Oz");
        list.deleteEmployeeByName("Nadia Jones");
        System.out.println(list.searchByName("Gary D. Richardson"));
    
        list.printAllEmployees();
    }
}

class LinkedList{
    Node company; 
    
    public LinkedList () {
        company = null;
    }
    
    // Print all employees in the format [id,name,net salary]
    public void printAllEmployees () {
        Node current = company;
        while (current != null) {
            System.out.println(current.getEmployee());
            Node subCurrent = current.getBelow();
            while (subCurrent != null) {
                System.out.println("   " + subCurrent.getEmployee());
                subCurrent = subCurrent.getBelow();
            }
            current = current.getNext();
        }
    }
    
    // Add a new employee
    public void addNewEmployee (Employee e) {
        Node newNode = new Node(e);
        if (company == null) {
            company = newNode;
        } else {
            Node current = company;
            Node previous = null;
            while (current != null && current.getEmployee().getId() < e.getId()) {
                previous = current;
                current = current.getNext();
            }
            
            if (current != null && current.getEmployee().getId() == e.getId()) {
                while (current.getBelow() != null) {
                    current = current.getBelow();
                }
                current.setBelow(newNode);
            } else {
                if (previous == null) {
                    newNode.setNext(company);
                    company = newNode;
                } else {
                    newNode.setNext(current);
                    previous.setNext(newNode);
                }
            }
        }
    }
    
    // Search for an employee by name
    public boolean searchByName (String name) {
        Node current = company;
        while (current != null) {
            if (current.getEmployee().getName().equalsIgnoreCase(name.trim())) {
                return true;
            }
            Node subCurrent = current.getBelow();
            while (subCurrent != null) {
                if (subCurrent.getEmployee().getName().equalsIgnoreCase(name.trim())) {
                    return true;
                }
                subCurrent = subCurrent.getBelow();
            }
            current = current.getNext();
        }
        return false;
    }
    
    // Find the highest net salary
    public double highestNetSalary () {
        double maxSalary = 0.0;
        Node current = company;
        while (current != null) {
            maxSalary = Math.max(maxSalary, current.getEmployee().getNetSalary());
            Node subCurrent = current.getBelow();
            while (subCurrent != null) {
                maxSalary = Math.max(maxSalary, subCurrent.getEmployee().getNetSalary());
                subCurrent = subCurrent.getBelow();
            }
            current = current.getNext();
        }
        return maxSalary;
    }
    
    // Delete an employee by name
    public void deleteEmployeeByName(String name) {
        Node current = company;
        Node previous = null;

        while (current != null) {
            if (current.getEmployee().getName().equalsIgnoreCase(name.trim())) {
                if (current.getBelow() != null) {
                    if (previous != null) {
                        previous.setNext(current.getBelow());
                    } else {
                        company = current.getBelow();
                    }
                    current.getBelow().setNext(current.getNext());
                } else {
                    if (previous != null) {
                        previous.setNext(current.getNext());
                    } else {
                        company = current.getNext();
                    }
                }
                return;
            }
            Node subCurrent = current.getBelow();
            Node subPrevious = current;
            while (subCurrent != null) {
                if (subCurrent.getEmployee().getName().equalsIgnoreCase(name.trim())) {
                    subPrevious.setBelow(subCurrent.getBelow());
                    return;
                }
                subPrevious = subCurrent;
                subCurrent = subCurrent.getBelow();
            }
            previous = current;
            current = current.getNext();
        }
    }
    
    // Utility method to calculate the ID based on the ASCII values of the characters in the name
    private int calculateId(String name) {
        return name.toUpperCase().trim().chars().sum();
    }
}

class Employee {
    private String name;
    private int id;
    private int numberOfDependents;
    private double salary;

    public Employee(String name, double salary, int numberOfDependents) {
        this.name = name.trim();
        this.salary = salary;
        this.numberOfDependents = numberOfDependents;
        this.id = this.name.toUpperCase().trim().chars().sum();
    }

    public String getName() {
        return name;
    }
    
    public int getId() {
        return id;
    }
    
    public double getNetSalary() {
        return salary * 0.91 + (numberOfDependents * 0.01 * salary);
    }
    
    @Override
    public String toString() {
        return String.format("[%d,%s,%.2f]", getId(), getName(), getNetSalary());
    }

}

class Node {
    private Employee e;
    private Node next;
    private Node below;

    public Node(Employee e) {
        this.e = e;
        this.next = null;
        this.below = null;
    }
    
    // getters and setters
    public Employee getEmployee() {
        return e;
    }

    public Node getNext() {
        return next;
    }

    public void setNext(Node next) {
        this.next = next;
    }

    public Node getBelow() {
        return below;
    }

    public void setBelow(Node below) {
        this.below = below;
    }
}
/*Katelyn Choudhari
  COP3330
  Final Project
  04-26-2024*/

/*Please see the comments I left on my submission Thanks :)*/

// imports
import java.io.*;
import java.util.*;

// Custom exception class for handling invalid student IDs
class IDException extends Exception {
    public IDException(String message) {
        super(message);
    }
}

// Abstract base class for all students
abstract class Student {
    private String name;
    private String id;
    
    // Constructor for the Student class initializing name and ID
    public Student(String name, String id) {
        this.name = name;
        this.id = id;
    }
    
    // Getters and setters for student name and ID
    public String getName() {
        return name;
    }

    public String getId() {
        return id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setId(String id) {
        this.id = id;
    }

    // Abstract method for printing the fee invoice which will be implemented by the subclasses
    abstract public void printInvoice();

}

// Abstract Graduate student superclass for Masters and PhD students
abstract class GraduateStudent extends Student {
    public GraduateStudent(String name, String id) {
        super(name, id);
    }
    
    // Abstract method for printing the fee invoice which will be implement by the subclasses
    @Override
    public void printInvoice() {
    }
}

// Classes for each sSpecific student type: Undergraduate, Masters, PhD

// Undergraduate student class
class UndergraduateStudent extends Student {
    private boolean resident;
    private double gpa;
    private List<String> courseIds;  // List to hold assigned course IDs
    
    // Constructor
    public UndergraduateStudent(String name, String id, boolean resident, double gpa, List<String> courseIds) {
        super(name, id);
        this.resident = resident;
        this.gpa = gpa;
        //this.courseIds = courseIds;
        this.courseIds = new ArrayList<>(courseIds);
    }
    
    // Method to print an invoice for tuition costs based on courses and residency status
    @Override
    public void printInvoice() {
        double baseRate = 120.25;  // Base rate per credit hour for residents
        if (!resident) {
            baseRate *= 2;  // Double the rate for non-residents
        }
        
        double totalTuition = 0; // Initialize tuition cost
        
        // Print headers for the invoice
        System.out.println("VALENCE COLLEGE");
        System.out.println("ORLANDO FL 10101");
        System.out.println("----------------------------------------");
        System.out.println("Fee Invoice Prepared for Student:");
        System.out.println(getId() + "-" + getName().toUpperCase()); // Display student ID and name
        System.out.println("\n1 Credit Hour = $" + String.format("%.2f", baseRate)); // Display the cost per credit hour
        System.out.println("\nCRN\tCR_PREFIX\tCR_HOURS\t$AMOUNT");
        
        // Iterate over each course ID, get course details, calculate cost, and prints it to the invoice
        for (String courseId : courseIds) {
            String[] details = ProjectDriver.getLectureDetails(courseId);
            int creditHours = Integer.parseInt(details[details.length - 1]); // Gets credit hours from the last element of each course
            double costForCourse = creditHours * baseRate; // Calculates the cost for the course
            System.out.printf("%s\t%s\t\t%d\t\t$ %.2f\n", courseId, details[1], creditHours, costForCourse);
            totalTuition += costForCourse; // Calculate total tuition cost
        }

        double healthAndIdFees = 35.00; // Additional fee
        System.out.println("\n\t\tHealth & I.D fees\t$ 35.00");
        
        // Calculate total due, apply discounts if applicable
        double totalDue = totalTuition + healthAndIdFees;
        double discount = 0;
        if (gpa >= 3.5 && totalDue > 500) {
            discount = totalDue * 0.25;  // 25% discount for 3.5 or higher GPA and cost greater than 500
            totalDue -= discount;
        }
        
        // Prints invoice headers, totals and any discount (if it applies)
        System.out.println("--------------------------------------");
        System.out.printf("\t\t\t\t\t$ %.2f\n", totalTuition + healthAndIdFees);
        System.out.printf("\t\t\t\t\t -$ %.2f\n", discount);
        System.out.println("                                   -----------");
        System.out.printf("\t\tTotal Payments \t$ %.2f\n\n", totalDue);
    }
}

// Graduate Master student class
class MsStudent extends GraduateStudent {
    private List<String> courseIds; // List to hold assigned course IDs
    
    // Constructor
    public MsStudent(String name, String id, List<String> courseIds) {
        super(name, id);
        this.courseIds = new ArrayList<>(courseIds);
    }
    
    // Method to print an invoice for tuition costs based on credit hours
    @Override
    public void printInvoice() {
        double ratePerCreditHour = 300.00;  // Flat rate per credit hour
        double totalTuition = 0; // Initialize tuition cost
        double healthAndIdFees = 35.00; // Additional fee
        
        // Print headers for the invoice
        System.out.println("VALENCE COLLEGE");
        System.out.println("ORLANDO FL 10101");
        System.out.println("----------------------------------------");
        System.out.println("Fee Invoice Prepared for Student:");
        System.out.println(getId() + "-" + getName().toUpperCase());
        System.out.println("\n1 Credit Hour = $" + String.format("%.2f", ratePerCreditHour));
        System.out.println("\nCRN\tCR_PREFIX\tCR_HOURS\t$AMOUNT");
        
        // Iterate over each course ID, get course details, calculate cost, and prints it to the invoice
        for (String courseId : courseIds) {
        	 String[] details = ProjectDriver.getLectureDetails(courseId);
            int creditHours = Integer.parseInt(details[details.length - 1]); // Gets credit hours from the last element of each course
            double costForCourse = creditHours * ratePerCreditHour; // Calculates the cost for the course
            System.out.printf("%s\t%s\t\t%d\t\t$ %.2f\n", courseId, details[1], creditHours, costForCourse);
            totalTuition += costForCourse; // Calculate total tuition cost
        }
        
        // Prints invoice headers and totals
        System.out.println("\n\t\tHealth & I.D fees\t$ 35.00");
        System.out.println("--------------------------------------");
        System.out.printf("\t\tTotal Payments\t\t$ %.2f\n\n", totalTuition + healthAndIdFees);
    }
}

// PhD student class
class PhdStudent extends GraduateStudent {
    private String advisor; // Student advisor
    private String researchSubject; // Student research subject
    private List<String> labsSupervised; // Labs the student supervises
    
    // Constructor
    public PhdStudent(String name, String id, String advisor, String researchSubject, List<String> labsSupervised) {
        super(name, id);
        this.advisor = advisor;
        this.researchSubject = researchSubject;
        this.labsSupervised = labsSupervised;
    }
    
    // Method to print an invoice for tuition costs based research subject and number of labs supervised
    @Override
    public void printInvoice() {
        double researchFee = 700.00;  // Base research fee
        double healthAndIdFees = 35.00;  // Additional fee

        if (labsSupervised.size() >= 2) {
            researchFee *= 0.5;  // 50% discount if supervising two labs
        }
        if (labsSupervised.size() >= 3) {
            researchFee = 0;  // No research fee if supervising three or more labs
        }
        
        // Print headers for the invoice
        System.out.println("VALENCE COLLEGE");
        System.out.println("ORLANDO FL 10101");
        System.out.println("----------------------------------------");
        System.out.println("Fee Invoice Prepared for Student:");
        System.out.println(getId() + "-" + getName().toUpperCase());
        System.out.println("\nRESEARCH");
        System.out.printf("%s\t\t\t$ %.2f\n", researchSubject.toUpperCase(), researchFee); // Displays the tuition amount after discount is applied based on the number of labs supervised
        // Prints invoice headers and totals
        System.out.println("\n\tHealth & I.D fees\t$ 35.00");
        System.out.println("--------------------------------------");
        System.out.printf("\t\tTotal Payments\t$ %.2f\n\n", researchFee + healthAndIdFees); // Calculates and prints the PhD student total
    }
}

// Main class
public class ProjectDriver {
    private static List<Student> students = new ArrayList<>(); // Static list to hold all students
    private static Map<String, String[]> lectures = new HashMap<>(); // Map to hold lectures details
    private static Map<String, String> labToLecture = new HashMap<>(); // Map linking lab IDs to lecture IDs
    private static Map<String, String> labsDetails = new HashMap<>(); // Map storing lab and lab room details
    
    // Public static methods to access and modify the data
    public static void addStudent(Student student) {
        students.add(student);
    }

    public static List<Student> getStudents() {
        return new ArrayList<>(students);  // Returns a copy of the list
    }

    public static String[] getLectureDetails(String lectureId) {
        return lectures.get(lectureId);
    }

    public static void addLecture(String lectureId, String[] details) {
        lectures.put(lectureId, details);
    }

    public static String getLabRoom(String labId) {
        return labsDetails.get(labId);
    }

    public static void addLab(String labId, String lectureId, String room) {
        labToLecture.put(labId, lectureId);
        labsDetails.put(labId, room);
    }
    
    public static void main(String[] args) {
        readClassesAndLabsFromFile(); // Reads the lec.txt file
        Scanner scanner = new Scanner(System.in); // Starts program and displays the Main Menu
        displayMainMenu(scanner);
        writeClassesAndLabsToFile(); // Writes any course changes to the file on program exit
    }

    // Read the lec.txt file and parse into needed parts
    private static void readClassesAndLabsFromFile() {
        File file = new File("lec.txt"); // Creates a file object pointing to lec.txt
        if (!file.exists()) { // Checks if the file exists
            System.out.println("Error: The file lec.txt does not exist.");
            return;
        }

        try (Scanner fileScanner = new Scanner(file)) {
            String currentLectureId = "";
            
            // Read each line from the file
            while (fileScanner.hasNextLine()) {
                String line = fileScanner.nextLine();
                
                // Split the line into parts by commas
                String[] parts = line.split(",");
                
                // Check if the line is a lecture
                if (parts.length > 2) { // This is a lecture
                    currentLectureId = parts[0]; // Update current lecture ID
                    lectures.put(parts[0], parts); // Store lecture details in the map
                } else if (parts.length == 2 && !currentLectureId.isEmpty()) { // This is a lab
                    labToLecture.put(parts[0], currentLectureId); // Maps the lab to the lecture course number
                    labsDetails.put(parts[0], parts[1]);
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println("Error: Unable to open lec.txt for reading.");
        }
    }
    
    // Method to write the updated lectures and labs back to the file
    private static void writeClassesAndLabsToFile() {
        try (PrintWriter writer = new PrintWriter(new File("lec.txt"))) {
            for (Map.Entry<String, String[]> lectureEntry : lectures.entrySet()) { // Iterate over each entry in the lectures map
                String lectureId = lectureEntry.getKey();
                String[] details = lectureEntry.getValue();
                // Write lecture details to the file
                writer.println(lectureId + "," + String.join(",", Arrays.copyOfRange(details, 1, details.length)));
                
                // Find all labs associated with this lecture and write them to the file
                labToLecture.entrySet().stream() // Processes the collection of objects (the lab IDs mapped to the lecture IDs)
                    .filter(entry -> entry.getValue().equals(lectureId)) // Tests each key-value pair to check if the value (the lecture ID associated with a lab) matches the lecture ID being processed
                    .forEach(labEntry -> { // If the lecture ID matches, get the lab ID from the map a.k.a the key from the pair
                        String labId = labEntry.getKey();
                        String labRoom = labsDetails.getOrDefault(labId, "Unknown"); // Gets the room details for the lab using its ID; if not found it prints 'Unknown'
                        writer.println(labId + "," + labRoom); // Writes the lab ID and room details to the output file
                    });
            }
        } catch (FileNotFoundException e) {
            System.out.println("Error: Unable to open lec.txt for writing. Please check file permissions.");
        }
    }
    
    // Method displays the Main Menu and handles user navigation
    private static void displayMainMenu(Scanner scanner) {
        int choice = -1;
        // Loop menu till user exits
        while (choice != 0) {
        	// Print Main Menu options
            System.out.println("\nMain Menu");
            System.out.println("1. Student Management");
            System.out.println("2. Class Management");
            System.out.println("0: Exit");
            System.out.print("Enter your selection: ");
            try {
                choice = Integer.parseInt(scanner.nextLine()); // Parse the user input into an integer
                switch (choice) {
                    case 1:
                        displayStudentManagementMenu(scanner);
                        break;
                    case 2:
                        displayClassManagementMenu(scanner);
                        break;
                    case 0:
                        System.out.println("Exiting. Take care!");
                        break;
                    default:
                        System.out.println("Invalid choice. Please try again.");
                }
            } catch (NumberFormatException e) {
                System.out.println("Invalid input, please enter a number.");
            }
        }
    }
    
    // Method displays the Class Management Menu
    private static void displayClassManagementMenu(Scanner scanner) {
        String option = "";
        // Loop menu till user exits
        while (!"x".equals(option)) {
        	// Print Main Menu options
            System.out.println("\nClass Management Menu");
            System.out.println("A. Search for a class or lab using the class/lab number");
            System.out.println("B. Delete a class and its associated labs");
            System.out.println("C. Add a course");
            System.out.println("D. List all classes and labs");
            System.out.println("X. Back to main menu");
            System.out.print("Enter your selection: ");
            option = scanner.nextLine().trim().toLowerCase(); // Accept lowercase menu choice input
            handleClassManagementOptions(option, scanner);
        }
    }
    
    // Method to handle the Class Management Menu option
    private static void handleClassManagementOptions(String option, Scanner scanner) {
        switch (option) {
            case "a":
                searchForClass(scanner);
                break;
            case "b":
                deleteClass(scanner);
                break;
            case "c":
            	addCourse(scanner);
                //addLabToClass(scanner);
                break;
            case "d":
                listAllClasses();
                break;
            case "x":
                System.out.println("Returning to main menu...");
                break;
            default:
                System.out.println("Invalid choice. Please try again.");
        }
    }
    
    // Search method to search classes based on lecture or lab ID
    private static void searchForClass(Scanner scanner) {
        System.out.println("Enter the class/lab number:");
        String classId = scanner.nextLine();

        if (lectures.containsKey(classId)) { // Checks if ID entered is a lecture
            String[] details = lectures.get(classId);
            System.out.println("Lecture: " + Arrays.toString(details));
        } else if (labToLecture.containsKey(classId)) { // Checks if ID entered is a lab
            String lectureId = labToLecture.get(classId);
            String[] lectureDetails = lectures.get(lectureId);
            System.out.println("Lab for lecture: " + Arrays.toString(lectureDetails));
            System.out.println("Lab room location: " + classId + ", " + labsDetails.get(classId)); // Gets the lab room
        } else {
            System.out.println("No class or lab found with ID: " + classId);
        }
    }
    
    // Helper method to get the classroom of a lab if needed
    private static String getClassRoom(String labId) {
        return labToLecture.getOrDefault(labId, "Unknown room");
    }
    
    // Delete method to remove a class and all its labs from the lec.txt file
    // Searches and deletes by lecture ID
    // Does not allow a lecture that has labs to be deleted
    private static void deleteClass(Scanner scanner) {
        System.out.println("Enter the class number to delete:");
        String classId = scanner.nextLine();
        
        // Check if the class is found and if it has associated labs
        if (lectures.containsKey(classId)) {
            if (labToLecture.values().contains(classId)) {
                // Lecture has associated labs
                System.out.println("Cannot delete lecture because it has associated labs.");
            } else {
                // Safe to delete lecture/removes the class if it has no labs
                lectures.remove(classId);
                System.out.println("Class removed successfully.");
            }
        } else {
            System.out.println("Class not found.");
        }
    }
    
    // Add method to add either a lecture (and its labs) or a lab to a lecture; re-writes to the lec.txt file
    private static void addCourse(Scanner scanner) {
        System.out.println("Would you like to add a (L)ecture or a (B)lab? Enter L or B");
        String type = scanner.nextLine().trim().toLowerCase();
        
        if ("l".equals(type)) {
            System.out.println("Enter lecture details separated by a comma (ID, Name, Description, Level, Modality, [Room, Has Labs [Yes/No]], Credits):");
            String input = scanner.nextLine();
            String[] lectureDetails = input.split(",");

            // Determine if the course is online or F2F based on Modality
            if ("Online".equalsIgnoreCase(lectureDetails[4].trim())) {
                if (lectureDetails.length != 6) {
                    System.out.println("Invalid input format for an online course. Expected ID, Name, Description, Level, Modality, Credits.");
                    return;
                }
            } else { // For F2F or mixed modality
                if (lectureDetails.length != 8) {
                    System.out.println("Invalid input format for a F2F course. Expected ID, Name, Description, Level, Modality, Room, Has Labs [Yes/No], Credits.");
                    return;
                }
            }

            // Add lecture to the lectures map
            lectures.put(lectureDetails[0].trim(), lectureDetails);
            System.out.println("Lecture added successfully.");

        } else if ("b".equals(type)) {
            System.out.println("Enter the class number of the lecture to add a lab to:");
            String lectureId = scanner.nextLine().trim();
            if (lectures.containsKey(lectureId)) {
                String[] details = lectures.get(lectureId);
                
                // Check if the lecture is online before adding a lab
                if ("Online".equalsIgnoreCase(details[4].trim())) {
                    System.out.println("Labs cannot be added to online lectures.");
                } else {
                    System.out.println("Enter lab ID and room (e.g., 12345,ROM-101):");
                    String[] labDetails = scanner.nextLine().split(",");
                    if (labDetails.length == 2) {
                        String labId = labDetails[0].trim();
                        String room = labDetails[1].trim();
                        labToLecture.put(labId, lectureId);
                        labsDetails.put(labId, room);
                        System.out.println("Lab added successfully to class " + lectureId);
                    } else {
                        System.out.println("Invalid lab details. Please use the format 'LabID,Room'.");
                    }
                }
            } else {
                System.out.println("Lecture class not found.");
            }
        } else {
            System.out.println("Invalid option. Please select 'L' for lecture or 'B' for lab.");
        }
    }
    
    // Method displays all the current courses in the lec.txt file
    private static void listAllClasses() {
        System.out.println("Listing all classes:");
        lectures.forEach((key, value) -> {
            System.out.println("Class ID: " + key + " - Details: " + Arrays.toString(value));
            labToLecture.entrySet().stream()
                .filter(entry -> entry.getValue().equals(key))
                .forEach(entry -> System.out.println("  Lab ID: " + entry.getKey() + " - Room: " + labsDetails.get(entry.getKey())));
        });
    }
    
    
    // Method displays the Student Management Menu
    private static void displayStudentManagementMenu(Scanner scanner) {
        String letterOption = "";
        // Loop menu till user exits
        while (!"x".equals(letterOption)) {
        	// Print Student Management Menu options
            System.out.println("\nStudent Management Menu");
            System.out.println("A. Add a student");
            System.out.println("B. Search for a student by ID");
            System.out.println("C. Delete a student");
            System.out.println("D. Print the fee invoice of a student by ID");
            System.out.println("E. Print all names of students grouped by type");
            System.out.println("X. Back to main menu");
            System.out.print("Enter your selection: ");
            letterOption = scanner.nextLine().trim().toLowerCase(); // Accept lowercase menu choice input
            handleStudentManagementOptions(letterOption, scanner);
        }
    }
    
    // Method to handle the Student Management Menu option
    private static void handleStudentManagementOptions(String option, Scanner scanner) {
        switch (option) {
            case "a":
                addStudent(scanner);
                break;
            case "b":
                searchForStudentById(scanner);
                break;
            case "c":
                deleteStudent(scanner);
                break;
            case "d":
                printInvoice(scanner);
                break;
            case "e":
                printGroupedStudents(scanner);
                break;
            case "x":
                break;
            default:
                System.out.println("Invalid option. Please try again.");
        }
    }
    
	 // Methods for adding, searching, and deleting students and classes
	
	 // Add a student method
	 private static void addStudent(Scanner scanner) {
	     try {
	         System.out.println("Enter student ID (Format: LLDDDD):");
	         String id = scanner.nextLine().trim().toLowerCase(); // Accept lowercase input
	         validateStudentID(id); // Validates and throws IDException if invalid
	
	         System.out.println("Enter student type (PhD, Masters, or Undergraduate):");
	         String type = scanner.nextLine().trim().toLowerCase(); // Accept lowercase input
	
	         System.out.println("Enter the remaining student information separated by '|':");
	         System.out.println("Example formats:");
	         System.out.println("PhD: Name|Advisor|Research Subject|Labs (comma-separated)");
	         System.out.println("Masters: Name|Courses (comma-separated)");
	         System.out.println("Undergraduate: Name|Resident (Yes/No)|GPA|Courses (comma-separated)");
	         String[] details = scanner.nextLine().split("\\|");
	         Student student = createStudentByType(type, details, id);
	         students.add(student);
	         System.out.println("Student added successfully.");
	     } catch (IDException | IllegalArgumentException e) {
	         System.out.println("Error: " + e.getMessage());
	     }
	 }
    
    // Method to get additional student information by type
    private static void printInputFormatByType(String type) {
        switch (type) {
            case "phd":
                System.out.println("For PhD students enter: Name|Advisor|Research Subject|Labs (Separate labs by commas)");
                break;
            case "masters":
                System.out.println("For Masters students enter: Name|Courses (Separate courses by commas)");
                break;
            case "undergraduate":
                System.out.println("For Undergraduate students enter: Name|Resident (Yes/No)|GPA");
                break;
            default:
                throw new IllegalArgumentException("Invalid student type entered.");
        }
    }
    
    // Method to create a student object based on the provided type and details
    private static Student createStudentByType(String type, String[] details, String id) throws IllegalArgumentException {
        switch (type) {
            case "phd":
                if (details.length < 4) throw new IllegalArgumentException("Insufficient data provided for PhD student.");
                String namePhd = details[0];
                String advisor = details[1];
                String researchSubject = details[2];
                List<String> labs = Arrays.asList(details[3].split(","));
                return new PhdStudent(namePhd, id, advisor, researchSubject, labs);
            case "masters":
                if (details.length < 2) throw new IllegalArgumentException("Insufficient data provided for Masters student.");
                String nameMs = details[0];
                List<String> masterCourses = Arrays.asList(details[1].split(","));
                return new MsStudent(nameMs, id, masterCourses);
            case "undergraduate":
                if (details.length < 4) throw new IllegalArgumentException("Insufficient data provided for Undergraduate student.");
                String nameUg = details[0];
                boolean resident = "yes".equalsIgnoreCase(details[1]);
                double gpa = Double.parseDouble(details[2]);
                List<String> undergraduateCourses = Arrays.asList(details[3].split(","));
                return new UndergraduateStudent(nameUg, id, resident, gpa, undergraduateCourses);
            default:
                throw new IllegalArgumentException("Invalid student type provided.");
        }
    }
    
    // Search a student by ID method
    private static void searchForStudentById(Scanner scanner) {
        System.out.println("Enter student ID:");
        String inputId = scanner.nextLine().trim().toLowerCase(); // Accept lowercase input
        Student foundStudent = students.stream()
                                       .filter(s -> s.getId().toLowerCase().equals(inputId)) // Ensure stored IDs are compared in lowercase
                                       .findFirst()
                                       .orElse(null);
        if (foundStudent != null) {
            System.out.println("Student Found: " + foundStudent.getName());
        } else {
            System.out.println("No student found with ID: " + inputId);
        }
    }
    
    // Delete a student by ID method
    private static void deleteStudent(Scanner scanner) {
        System.out.println("Enter student ID to delete:");
        String id = scanner.nextLine().trim().toLowerCase(); // Accept lowercase input
        boolean found = false;
        Iterator<Student> iterator = students.iterator();
        while (iterator.hasNext()) {
            Student student = iterator.next();
            if (student.getId().toLowerCase().equals(id)) {
                iterator.remove();
                System.out.println("Student deleted successfully.");
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("No student found with ID: " + id);
        }
    }


    // Validation of student ID method
    private static void validateStudentID(String id) throws IDException {
        // Check the format - two letters followed by four digits
        if (!id.matches("[a-zA-Z]{2}\\d{4}")) {
            throw new IDException("Invalid ID format. Expected format: LLDDDD (e.g., ab1234).");
        }

        // Check for uniqueness of the ID
        for (Student student : students) {
            if (student.getId().equals(id)) {
                throw new IDException("ID already exists. Each student must have a unique ID.");
            }
        }
    }
    
    // Method prints the fee invoice of a student by ID
    private static void printInvoice(Scanner scanner) {
        System.out.println("Enter student ID:");
        String id = scanner.nextLine().trim().toLowerCase(); // Accept lowercase input
        Student foundStudent = null;
        for (Student student : students) {
            if (student.getId().toLowerCase().equals(id)) {
                foundStudent = student;
                break;
            }
        }
        if (foundStudent != null) {
            foundStudent.printInvoice();
        } else {
            System.out.println("No student found with ID: " + id);
        }
    }
    
    // Method prints all names of students grouped by type of student
    private static void printGroupedStudents(Scanner scanner) {
        System.out.println("PhD Students:");
        for (Student student : students) {
            if (student instanceof PhdStudent) {
                System.out.println(student.getName());
            }
        }

        System.out.println("Masters Students:");
        for (Student student : students) {
            if (student instanceof MsStudent) {
                System.out.println(student.getName());
            }
        }

        System.out.println("Undergraduate Students:");
        for (Student student : students) {
            if (student instanceof UndergraduateStudent) {
                System.out.println(student.getName());
            }
        }
    }
}
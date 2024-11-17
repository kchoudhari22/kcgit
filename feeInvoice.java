/*Katelyn Choudhari
  COP3330
  Unit 1 Homework
  01-19-2024*/

import java.util.Scanner;

public class feeInvoice {
	
	//initialize input to scan from user
	public static void main(String[] args) {
		Scanner studentName, studentId, courseDetails; /*studentCourse1, studentCourse2, credHours1, credHours2*/
		studentName = new Scanner (System.in);
		studentId = new Scanner (System.in);
		courseDetails = new Scanner (System.in);
		String name;
		String id;
		String[] course1;
		String[] course2;
		
		//scan for user student info and course details
		System.out.println("Enter student full name: ");
		name = studentName.nextLine();
		
		System.out.println("Enter student ID: ");
		id = studentId.nextLine();
		
		System.out.println("Enter crn/credit hours for the first course: ");
		course1 = courseDetails.nextLine().split("/");
		
		System.out.println("Enter crn/credit hours for the second course: ");
		course2 = courseDetails.nextLine().split("/");
		
		//calculates fee invoice; cost per course based on credit hours and total cost for all courses 
		double x = 120.25;
		double credHours1 = Integer.parseInt(course1[1]);
		double credHours2 = Integer.parseInt(course2[1]);
		double cost1 = (x * credHours1); 
		double cost2 = (x * credHours2);
		double totalCost = (cost1 + cost2 + 35.00);
		
		//outputs fee invoice to terminal
		System.out.println("\nThank You!\nHere is the Fee Invoice:\n\nSIMPLE COLLEGE\nORLANDO FL 10101\n********************\n\nFee Invoice Prepared for: ");
		System.out.println("[" + name + "] [" + id + "]\n");
		System.out.println("1 Credit Hour = $120.25\n\nCRN\tCREDIT HOURS\n" + course1[0] +"\t"+ course1[1] + "\t\t$" + cost1 + "\n" + course2[0] +"\t"+ course2[1] + "\t\t$" + cost2 + "\n\nHealth & ID fees\t$35.00");
		System.out.println("--------------------------------\nTotal Payments\t\t" + totalCost);
		
		//closes scanner
		studentName.close();
		studentId.close();
		courseDetails.close();
	}
}
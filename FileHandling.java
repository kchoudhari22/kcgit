import java.io.*;
import java.util.*;
//Reads a file of course numbers, prefixes and credit hours
//and then creates two new text files that output the undergraduate
//and graduate courses in the two new files sorted by course number
public class FileHandling {
	
	public static void createFile (ArrayList<Course> list, String fileName) {
		//create a file and send everything to the new file
		PrintWriter pw = null;
		try {
			pw = new PrintWriter(new File(fileName));
		
			for(Course course : list) {
				pw.println(course);
			}
		
		}catch (Exception e) {
			
		}
		finally {
			pw.close();
		}
	}

	public static void main(String[] args) throws FileNotFoundException{
		//Read, write and sort the data.txt file that now has course information
		//Put the undergraduate and graduate courses into their own output files
		//ArrayList<Course> list = new ArrayList<>();
		ArrayList<Course> gradList = new ArrayList<>();
		ArrayList<Course> underGradList = new ArrayList<>();
		
		Scanner scanner = new Scanner (new File("data.txt"));
	
		String line = "";
		String [] items = null;
	
		while (scanner.hasNextLine()){
			line = scanner.nextLine(); //reads the whole line
			items = line.split("\t");
			
			if(Integer.parseInt(items[0]) < 5000)
					underGradList.add(new Course (Integer.parseInt(items[0]), items[1], Integer.parseInt(items[2]) ));
			else
					gradList.add(new Course (Integer.parseInt(items[0]), items[1], Integer.parseInt(items[2]) ));
			//list.add(new Course(Integer.parseInt(items[0]), items[1], Integer.parseInt(items[2])));
		}
		
		Collections.sort(underGradList);
			
		for (Course course : underGradList) {
			System.out.println(course);
		}
	
		Collections.sort(gradList, new SortByCourseNumber());
		System.out.println("----------------------------");		
		for (Course course : gradList) {
			System.out.println(course);
		}
		
		//call method that creates new files
		createFile(underGradList, "Undergraduate.txt");
		createFile(gradList, "Graduate.txt");
		
	}
}

class SortByCourseNumber implements Comparator<Course>{
	@Override
	public int compare(Course c1, Course c2) {
		if (c1.getCreditHours() > c2.getCreditHours() ) return 1;
		if (c1.getCreditHours() < c2.getCreditHours() ) return -1;
		return 0;
	}
}

class Course implements Comparable<Course>{
	private int crn;
	private String prefix;
	private int creditHours;
	
	@Override
	public int compareTo (Course course) {
		if (this.crn > course.crn) return 1;
		if (this.crn < course.crn) return -1;
		return 0;
	}
	
	//getters/setters
	public int getCrn() {
		return crn;
	}

	public void setCrn(int crn) {
		this.crn = crn;
	}

	public String getPrefix() {
		return prefix;
	}

	public void setPrefix(String prefix) {
		this.prefix = prefix;
	}

	public int getCreditHours() {
		return creditHours;
	}

	public void setCreditHours(int creditHours) {
		this.creditHours = creditHours;
	}
	
	//constructor
	public Course(int crn, String prefix, int creditHours) {
		super();
		this.crn = crn;
		this.prefix = prefix;
		this.creditHours = creditHours;
	}

	//toString
	@Override
	public String toString() {
		return "Course [crn=" + crn + ", prefix=" + prefix + ", creditHours=" + creditHours + "]";
	}
}

//NOTES
/*
 * File file = new File ("data.txt"); //open a file Scanner scanner = new
 * Scanner (file);
 * 
 * while(scanner.hasNextLine()) { String line = scanner.nextLine();
 * System.out.println(line); }
 */
		
/*String data = "123 Happy Street Orlando 32828";
Scanner scanner = new Scanner(data);
String line;
while (scanner.hasNextLine()){
	line = scanner.nextLine();
	System.out.println(line);
	}*/

/*String data = "123 , Happy Street , Orlando , 32828\n2565 , Another Street , 32825";
Scanner scanner = new Scanner (data);
String line;
String streetName = "";
String [] items;
while (scanner.hasNextLine()){
	line = scanner.nextLine();
	items = line.split(",");
	System.out.println(items[1]);
	}*/

//----------------------------------------
/*
 * //Write to a file PrintWriter pw = new PrintWriter(new File ("out.txt"));
 * pw.print("Hello "); pw.println("there!"); pw.close();
 */
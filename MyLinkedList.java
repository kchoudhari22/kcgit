import java.util.*;

public class MyLinkedList {

	public static void main(String[] args) {
		
		/*LinkedList<String> list = new LinkedList<>();
		
		list.add("Ericka");
		list.add("John");
		list.add("Emma");	
		
		//insert to index 1
		list.add(1, "Jimmy");
		
		//delete
		list.remove(2);
		
		System.out.println(list);*/
		
		//create your own linked list
		LinkedList list = new LinkedList();
		
		//from the front
		/*Node node = new Node();
		node.name = "Ericka";
		list.addFront(node);
		
		node = new Node();
		node.name = "Jimmy";
		list.addFront(node);
		
		node = new Node();
		node.name = "John";
		list.addFront(node);*/
		
		
		//from the back
		Node node = new Node();
		node.name = "Ericka";
		list.addBack(node);
		
		node = new Node();
		node.name = "Jimmy";
		list.addBack(node);
		
		node = new Node();
		node.name = "John";
		list.addBack(node);
		
		list.printShell(list.head);
		//list.print();
		//System.out.println(list);
	}

}

//create your own linked list
class Node{
	String name;
	Node next;
}

class LinkedList{
	
	Node head;
	
	public LinkedList() {
		head = null;
	}
	
	//adds one node / add people
	public void addFront(Node node) {
		if(head == null) {
			head = node;
			head.next = null;
			return;
		}
		//links last node to the head
		node.next = head;
		head = node;
	}
	
	public void addBack(Node node) {
		if(head == null) {
			head = node;
			head.next = null;
			return;
		}
		//add to back of list
		Node temp = head;
		while (temp.next != null) {
			temp = temp.next;
		}
		temp.next = node;
		temp.next.next = null;
	}
	
	//returns names/string
	/*public String toString() {
		return head.name;
	}*/
	
	//print linked list
	public void print() {
		Node temp = head;
		
		while(temp != null) {
			System.out.print(temp.name + "->");
			temp = temp.next;
		}
		System.out.println("NULL");
	}
	
	//print recursively shell
	public void printShell(Node head){
		head = this.head;
		printR(head);
	}
	//print recursively
	public void printR(Node head) {
		if(head != null) {
			printR(head.next);
			System.out.println(head.name);
		}
	}
}

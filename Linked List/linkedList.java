import java.util.*;

/* This program in java is to implement linked list. Linked list is a data structure where eac element is considered as an object. Its just like an array of elements but the memory allocated is not continuous. One head should be there which should link to another node. */
/*Creating a class node with 2 datas and a consructor. The data members are the node next and the data that should be added. The constructor is to initialize the data and the node value. */
class node{
	node next;
	int data;

	public node(int data){
  		this.data=data;
			this.next=null;
	}
}

/*Another pubic class which has a node head as data member, one constructor to intialize the value, 2 functions to add the elements to the end of the list and to print the added datas and a main function. */
public class linkedList{
	node head;

	public linkedList(){
		this.head=null;
	}

	public void addNode(int data){
		node newhead=new node(data);
		if(this.head==null)
		head=newhead;
		else{
		node temp;
		for(temp=this.head;temp.next!=null;temp=temp.next);
		temp.next=newhead;
		}
	}

	/*Deleting the element in the passed position*/
	void deleteNode(int pos){
		if(head == null){
			return ;
		}
		node temp = head;
		if(pos == 0){
			head = temp.next;
		}
		for(int i = 0;temp != null && i < pos-i-1;i++){
			temp=temp.next;
		}
		if(temp == null || temp.next == null)
			return ;
		node next=temp.next.next;
		temp.next = next;
	}
	public void print(){
		for(node newtemp=this.head;newtemp!=null;newtemp=newtemp.next){
		System.out.println(newtemp.data);
		}
	}
	public static void main(String[] args){
	linkedList list = new linkedList();
	list.addNode(1);
	list.addNode(2);
	list.addNode(3);
	System.out.println("The elements of linked list are:");
	list.print();
	Scanner Sc = new Scanner(System.in);
	System.out.print("Enter the position to be deleted:");
	int pos=Sc.nextInt();
	list.deleteNode(pos);
	System.out.println("The elements of linked list after deletion of element in mentioned position are:");
	list.print();
  }
} 

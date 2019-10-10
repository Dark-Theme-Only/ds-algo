
#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
	int val; 
	struct Node* next; 
}; 

Node* reverse(Node* head) 
{ 
  if (head == NULL) return NULL; 
        Node *cur = head, *nextNode, *prevNode;
        prevNode = NULL;

        while (cur != NULL) {
            nextNode = cur->next;
            cur->next = prevNode;
            prevNode = cur;
            cur = nextNode;
        }

        head = prevNode;
        return head;
} 

Node* newNode(int key) 
{ 
	Node* temp = new Node; 
	temp->val = key; 
	temp->next = NULL; 
	return temp; 
} 

void printlist(Node* head) 
{ 
	while (head != NULL) { 
		cout << head->val << " "; 
		head = head->next; 
	} 
	cout << endl; 
} 


int main() 
{ 
	Node* head1 = newNode(1); 
	head1->next = newNode(2); 
	head1->next->next = newNode(3); 
	head1->next->next->next = newNode(4); 
	head1->next->next->next->next = newNode(5); 
	head1->next->next->next->next->next = newNode(6); 
	head1->next->next->next->next->next->next = newNode(7); 
	head1->next->next->next->next->next->next->next = newNode(8); 
	cout << "Given linked list\n"; 
	printlist(head1); 
	head1=reverse(head1); 
	cout << "\nReversed linked list\n"; 
	printlist(head1); 
	return 0; 
} 

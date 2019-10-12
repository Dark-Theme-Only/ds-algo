#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node *next;
	//node *prev;

	node(int d){
		data=d;
		next=NULL;
		//prev=NULL;
	}
};

node *kthfromLast(node *head,int k){

	node *sptr=head;
	node *fptr=head;

	for(int i=0;i<k;i++){
		fptr=fptr->next;
	}

	while(fptr!=NULL){
		sptr=sptr->next;
		fptr=fptr->next;
	}

	return sptr;
}

int main(){
	int x;
	node *head=NULL;
	node *tail=NULL;
	cin>>x;
	head=new node(x);
	tail=head;
	while(1){
		cin>>x;
		if(x==-1){
			break;
		}
		node *newNode=new node(x);
		tail->next=newNode;
		tail=newNode;
	}	
	int k; cin>>k;
node *res=kthfromLast(head,k);
cout<<res->data<<endl;
	return 0;
}
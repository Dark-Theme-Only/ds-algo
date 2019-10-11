#include <iostream>

template <typename T>
class LinkedList{
	struct Node{
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data=T{},Node* next=nullptr, Node* prev=nullptr){
			data_=data;
			next_=next;
			prev_=prev;
		}
	};
	Node* front_;
	Node* back_;
public:
	LinkedList(){
		front_=nullptr;
		back_=nullptr;
	}
	void push_front(const T& data);
	void push_back(const T& data);
	void pop_front();
	void pop_back();
	void print() const;
	void reversePrint() const;
	~LinkedList();
};

template <typename T>
void LinkedList<T>::push_front(const T& data){
    Node* nn = new Node(data,front_);
    if(front_!=nullptr)
        front_->prev_=nn;
    else
        back_=nn;
    front_=nn;
    

}
template <typename T>
void LinkedList<T>::push_back(const T& data){
    Node* nn = new Node (data,{},back_);
    if(front_!=nullptr)
         back_->next_=nn;
    else
        front_=nn;
        
    back_=nn;
}
template <typename T>
void LinkedList<T>::pop_front(){
    if(front_){
        Node* rm = front_;
        front_ = rm->next_;
        if(front_)
            front_->prev_=nullptr;
        else
            back_=nullptr;
        delete rm;
    }
    

}
template <typename T>
void LinkedList<T>::pop_back(){
    if(back_){
        Node* rm = back_;
        back_= rm->prev_;
        if(back_)
            back_->next_=nullptr;
        else
            front_=nullptr;
        delete rm;
    }
    

}
template <typename T>
void LinkedList<T>::print() const{
	Node* curr=front_;
	while(curr!=nullptr){
		std::cout << curr->data_ << " ";
		curr=curr->next_;
	}
	if(!front_){
		std::cout << "empty list";
	}
	std::cout << std::endl;
}

template <typename T>
LinkedList<T>::~LinkedList(){
    Node* cn = front_;
    Node* nn;
    while(cn!=nullptr){
        nn = cn->next_;
        delete cn;
        cn = nn;
    }
    
}



int main()
{
    
    LinkedList<int> myList;
    myList.print();
    int n = 3;
    
    for(int i = 0; i<n;i++){
        myList.push_back(i);
    }
    
    myList.print();
    for(int i = 0; i<n;i++){
        myList.pop_back();
        myList.print();
    }
    
    for(int i = 0; i<n;i++){
        myList.push_front(i);
        
    }
    myList.print();
    
    for(int i = 0; i<n;i++){
        myList.pop_front();
        myList.print();
    }
    
    
}

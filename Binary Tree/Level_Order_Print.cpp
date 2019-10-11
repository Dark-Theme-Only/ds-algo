#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d):data(d),left(NULL),right(NULL){}
};

void LevelOrderInsertion(Node* &root) ///iteratively
{
    cout<<"enter the root Node value"<<endl;
    int d;
    cin>>d;
    root=new Node(d);
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* parent=q.front();
        q.pop();
        int c1,c2;
        cout<<"enter the children of "<<parent->data<<endl;
        cin>>c1>>c2;
        if(c1!=-1)
        {
            parent->left=new Node(c1);
            q.push(parent->left);
        }
        if(c2!=-1)
        {
            parent->right=new Node(c2);
            q.push(parent->right);
        }
    }
}

// Here we will use the fifo property of a queue ie whenever we will encounter a node we will 
// print it and push its children in queue 

void LevelOrderPrint(Node*root){
    queue<Node*> q;
    q.push(root);
    // here null is used to mark the termination of a level 
    q.push(NULL);
    while(!q.empty()){
        Node* f = q.front();
        if(f==NULL){
            q.pop();
            cout<<endl;
            if(!q.empty()){
                // all the children of previous level are inserted in the queue 
                q.push(NULL);
            }
        }
        else{
            q.pop();
            cout<<f->data<<" ";
            // if left child is not null we will push it in the queue
            if(f->left){
                q.push(f->left);
            }
            // if right child is not null we will push it in the queue
            if(f->right){
                q.push(f->right);
            }
        }
    }
}

int main()
{
    Node* root=NULL;
    LevelOrderInsertion(root);
    LevelOrderPrint(root);
    return 0;
}

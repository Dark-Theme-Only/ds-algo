public class Inordertraversal {
    static class Node{
        int value;
        Node left;
        Node right;
        Node(int value){
            this.value=value;
            this.left=null;
            this.right=null;
        }
    }
    //Inorder traversal of a tree
    //Left-Root-Right
    //Uses recursion to print node in order left, root, right
    public void InorderPrint(Node node){
        if(node==null){
            return;
        }
        InorderPrint(node.left);  //Left
        System.out.println(node.value);  //root
        InorderPrint(node.right);   //right
    }
    public static void main(String [] args){
        Node n=new Node(1);
        Node n1=new Node(2);
        Node n2=new Node(3);
        Node n3=new Node(4);
        Node n4=new Node(5);
        Node n5=new Node(6);
        Node n6=new Node(7);
        n.left=n1;
        n.right=n2;
        n1.left=n3;
        n1.right=n4;
        n2.left=n5;
        n2.right=n6;
        Inordertraversal i=new Inordertraversal();
        i.InorderPrint(n);
    }
}

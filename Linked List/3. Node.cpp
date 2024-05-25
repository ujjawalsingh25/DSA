#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next_address;
    // Node(int data){
    //     this -> data = data;
    //     this -> next_address = NULL;
    // }
    Node(int data): data(data), next_address(NULL) {}
};

int main()
{
    // int *c = new int(b);
    // cout<<"Value of b: "<<(*c)<<endl; //Value of 'b' with making new pointer 'c' with 'new' keyboard.
    // *c=100;
    // b=*c;
    // cout<<"New value of b changed through pointer: "<<b<<endl;
    
    cout <<"Node"<<" | "<<"Next_Address"<<endl;

    Node* node1 = new Node(10);        // *node1 = 10 && node1 = address containing value 10.
    cout<<node1 -> data<<" | ";
    cout<<node1 -> next_address<<endl;
    
    Node *ptr_node;
    Node obj(15);
    ptr_node =&obj;
    cout<<ptr_node -> data<<" | ";
    cout<<ptr_node -> next_address<<endl;
    ptr_node -> data = 25;         // Use -> to access data member
    cout<<ptr_node -> data<<" | ";
    cout<<ptr_node -> next_address<<endl;


    return 0;
}
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next_address;
    Node(int data): data(data), next_address(NULL) {}
};


void insert_at_head(Node* &head, int data){
    // create new node 
    Node* temp = new Node(data);
    temp -> next_address = head;
    head = temp;
}


void insert_at_tail(Node* &tail, int data){
    // create new node 
    Node* temp = new Node(data);
    tail -> next_address = temp;
    tail = temp;
}


void insert_at_midPosition(Node* &head, Node* &tail, int pos, int data){
    // Insertion at start
    if(pos == 1){
        insert_at_head(head, data);
        return;
    }

    Node* temp = head;
    int count = 1;

    // Insertion at last
    if(temp -> next_address == NULL){
        insert_at_tail(tail , data);
        return;
    }

    while(count < pos -1){
        temp = temp -> next_address;
        count++;
    }

    // Creating a node for data
    Node* nodeToInsert = new Node(data);
    
    nodeToInsert -> next_address = temp -> next_address;
    temp -> next_address = nodeToInsert;
}


void display(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next_address;
    }
    cout<<endl;
}

int main()
{    
    Node* node1 = new Node(10);        // *node1 = 10 && node1 = address containing value 10.
    // cout<<node1 -> data<<" | ";
    // cout<<node1 -> next_address<<endl;

    Node* head = node1;
    Node* tail = node1;
    display(head);

    // insert_at_head(head, 5);
    // insert_at_head(head, 12);
    // insert_at_head(head, 25);
    // display(head);

    insert_at_tail(tail, 5);
    insert_at_tail(tail, 12);
    insert_at_tail(tail, 25);
    display(head);                  // Comment head to print or create another display for tail.

    insert_at_midPosition(head, tail, 2, 32);
    display(head);
    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;


    return 0;
}
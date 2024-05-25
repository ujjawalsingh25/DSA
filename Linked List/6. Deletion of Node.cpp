#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next_address;
   Node(int data): data(data), next_address(NULL) {}
    //destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next_address != NULL) {
            delete next_address;
            this->next_address = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

void insert_at_tail(Node* &tail, int data){
    // create new node 
    Node* temp = new Node(data);
    tail -> next_address = temp;
    tail = temp;
}

void delete_node(int pos, Node* &head){
    if(pos == 1){
        Node* temp = head;
        head = head -> next_address;
        temp = temp -> next_address;      // set temp again to head i.e its next address (new head after deletion) 
        delete temp;                     // clear memory of head.
    }
    else {
        Node* current = head;
        Node* prev = NULL;

        int count =1;
        while(count < pos){
            prev = current;
            current = current -> next_address;
            count++;
        }
        prev -> next_address = current -> next_address;
        current -> next_address = NULL;
        delete current;
    }
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

    Node* head = node1;
    Node* tail = node1;
    display(head);

    insert_at_tail(tail, 5);
    insert_at_tail(tail, 12);
    insert_at_tail(tail, 25);
    display(head);                  // Comment head to print or create another display for tail.

    delete_node(2, head);
    display(head);
    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;

    return 0;
}
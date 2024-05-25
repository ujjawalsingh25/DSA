#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next_address;
        Node(int data): data(data), next_address(NULL) {}
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

void insert_at_tail(Node* &tail, int insertBefore_data, int data){
    if(tail == NULL){                       // Empty List
        Node* newNode = new Node(data);
        tail = newNode;
        newNode -> next_address = newNode;
    }
    else {                  // Non- empty list
        Node* current = tail;
        while(current -> data != insertBefore_data){
            current = current -> next_address;
        }
        // Element found before which we need to insert list and **** current is iterating to that element.
        Node* temp = new Node(data);            // Step 1. Make a new node
        temp -> next_address = current -> next_address;
        current -> next_address = temp;
    }
}

void delete_node(Node* &tail, int element){
    // let List is not empty & element is present in list

    Node* prev = tail;                  // create node previous
    Node* current = prev -> next_address;       // create node current
    while(current -> data != element){
        prev = current;
        current = current -> next_address;
    }

    prev -> next_address = current -> next_address;
    if(current == prev){                // List having single element
        tail = NULL;
    }
    else if(tail == current){           // List having 2 or more than 2 element.
        tail = prev;    
    }
    current -> next_address = NULL;
    delete current;
}

void display(Node* tail){
    Node* temp = tail;
    do{
        cout<<tail -> data<<" ";
        tail = tail -> next_address;
    } while(tail != temp);
}
 
int main()
{
    Node* tail = NULL;

    insert_at_tail(tail, 5, 3);         // insert in empty list
    insert_at_tail(tail, 3, 6);        // insert after 1st or last (head/tail) list
    insert_at_tail(tail, 6, 25);      // insert at tail end or last
    insert_at_tail(tail, 3, 12);        // Insert in between of lists.
    insert_at_tail(tail, 6, 23);        // Insert in between of lists.
    display(tail);

    delete_node(tail, 3);
    display(tail);

    return 0;
}
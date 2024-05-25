#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next_address;
        Node(int data): data(data), next_address(NULL) {}
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


bool circular_check(Node* &head){
    if(head == NULL) return true;
    Node* temp = head -> next_address;
    while(temp != NULL && temp != head){
        temp = temp -> next_address;
    }
    if(temp == NULL)  return false;

    return true;
}


void display(Node* tail){
    Node* temp = tail;
    do{
        cout<<tail -> data<<" ";
        tail = tail -> next_address;
    } while(tail != temp);
    cout<<endl;
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
    

    if(circular_check(tail)){
        cout<<"YES"<<endl;
    }
    else{
       cout<<"NO"<<endl; 
    }


    return 0;
}
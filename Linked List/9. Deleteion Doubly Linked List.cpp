#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev_address;
        Node* next_address;
        Node(int data): data(data), prev_address(NULL), next_address(NULL) {}

        ~Node(){
        int val = data;
        if(next_address != NULL) {
            delete next_address;
            next_address = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
        
};

void insert_at_tail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail -> next_address = temp;
    temp -> prev_address = tail;
    tail = temp;
}


void delete_node(int pos, Node* &head){
    if(pos == 1){
        Node* temp = head;
        temp -> next_address -> prev_address = NULL;     // set temp again to head i.e its next address (new head after deletion) 
        head = temp -> next_address;
        temp -> next_address = NULL;
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

        current -> prev_address = NULL;
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
    }cout<<endl;
}

int main()
{
    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    insert_at_tail(tail, 25);       // inserted at tail.
    insert_at_tail(tail, 15);
    insert_at_tail(tail, 45);
    insert_at_tail(tail, 55);

    delete_node(3, head);
    display(head);

    Node* iter = head;
    cout<<"\nData"<<" - "<<" Prev Address"<<"   - "<<"Current Address"<< "  - "<<"Next Address"<<endl;
    for(int i=0;i<1;i++){
        cout<<iter -> data<<"   -       "<<iter -> prev_address<< "         - "<<&iter -> data<<"   - "<<iter -> next_address<<endl;
        iter = iter -> next_address;
    }
    for(int i=1;i<6;i++){
        cout<<iter -> data<<"   - "<<iter -> prev_address<< "   - "<<&iter -> data<<"   - "<<iter -> next_address<<endl;
        iter = iter -> next_address;
    }cout<<endl;

    return 0;
}
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev_address;
        Node* next_address;
        Node(int data): data(data), prev_address(NULL), next_address(NULL) {}
};

void insert_at_head(Node* &head, int data){
    Node* temp = new Node(data);            // **** New Node create and assign data *****
    temp -> next_address = head;      // (prev)_tempData_(next) --next to head --->> (head)(prev)_headData_(next)
    head -> prev_address = temp;      // (prev)_tempData_(next) <<--next to head --- (head)(prev)_headData_(next)
    head = temp;                        // head come before.
}

void insert_at_tail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail -> next_address = temp;
    temp -> prev_address = tail;
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
    temp -> next_address -> prev_address = nodeToInsert;
    temp -> next_address = nodeToInsert;
    nodeToInsert -> prev_address = temp;

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

    insert_at_head(head, 12);       // inserted at head.
    insert_at_head(head, 34);

    insert_at_tail(tail, 25);       // inserted at tail.
    insert_at_tail(tail, 15);

    insert_at_midPosition(head, tail, 3, 95);       // inserted at mid position.
    cout<<endl;
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
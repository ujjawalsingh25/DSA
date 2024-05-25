#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next_address;
    Node(int data): data(data), next_address(NULL) {}
};

void insert_at_tail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail -> next_address = temp;
    tail = temp;                       
}

void display(Node* &head){
    Node* temp = head;              // Because we always traverse from head.
    while(temp  != NULL){
        cout<<temp -> data <<" ";
        temp = temp -> next_address;         // increment for traversal.
    }
    cout<<endl;
}


Node* sortNodes(Node* &head){
    Node* current = head;
    while(current != NULL){
        Node* min_index = current;
        Node* temp = current -> next_address;
        while(temp != NULL){
            if(temp -> data < min_index -> data)
                min_index = temp;
            temp = temp -> next_address;
        }
        swap(current -> data , min_index -> data);
        current = current -> next_address;
    }
    return head;
}



int main()
{
    Node* node1 = new Node(10);
    
    Node* head = node1;
    Node* tail = node1;

    insert_at_tail(tail, 22);
    insert_at_tail(tail, 55);
    insert_at_tail(tail, 42);
    insert_at_tail(tail, 25);
    insert_at_tail(tail, 36);
    insert_at_tail(tail, 73);
    display(head);
    cout<<"Head: "<<head -> data<<endl;
    cout<<"Tail: "<<tail -> data<<endl;

    Node* ans_asHead = sortNodes(head);
    display(ans_asHead);

    return 0;
}

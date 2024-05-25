#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next_address;
    Node(int data): data(data), next_address(NULL) {}
};

void insert_at_tail(Node* &tail, int data){
    // create a node
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

Node* reverse_list(Node* head){
    Node* prev = NULL;
    Node* current = head;
    Node* forward = NULL;

    while(current != NULL){ 
        forward = current -> next_address;
        current -> next_address = prev;
        prev = current;
        current = forward;
    }
    return prev;
}

Node* reverse_k_element(Node* &head, int place){
    if(head == NULL) return NULL;

    Node* forward = NULL;
    Node* current = head;
    Node* prev = NULL;
    int count = 0;

    while(current != NULL && count < place){
        // forward = current -> next_address;
        // current -> next_address = prev;
        // prev = current;
        // current = forward;
        Node* prev = reverse_list(current);
        count++;
    }
    if(forward != NULL){
        head -> next_address = reverse_k_element(forward, place);
    }
   return prev;
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
    insert_at_tail(tail, 73);
    display(head);

    Node* ans_asHead = reverse_k_element(head, 2);
    display(ans_asHead);

    return 0;
}
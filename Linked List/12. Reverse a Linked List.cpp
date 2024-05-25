// l2
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
   tail  -> next_address = temp;
   tail = temp;
}

void display(Node* &head){
    Node* temp = head;
    while(temp  != NULL){
        cout<<temp -> data <<" ";
        temp = temp -> next_address;         // increment for traversal.
    }
    cout<<endl;
}


 
// -----  Through Iteration ----------------------------------------------------- 

// Node* reverse_list(Node* head){
//     if(head == NULL || head -> next_address == NULL){
//         return head;
//     }
//     Node* prev = NULL;
//     Node* current = head;
//     Node* forward = NULL;

//     while(current != NULL){ 
//         forward = current -> next_address;
//         current -> next_address = prev;
//         prev = current;
//         current = forward;
//     }
//     return prev;
// }
// -------------------------------------------------------------------


// -----  Through Recursion  -----------------------------------------------------

// void reverse_recursion(Node* &head, Node* &current, Node* &prev){
//  if(current == NULL){
//         head = prev;
//         return;
//     }
   
//     Node* forward = current -> next_address;
//     reverse_recursion(head, forward, current);
//     current -> next_address = prev;
// }

// Node* reverse_list_through_recursion(Node* head){
//     Node* current = head;
//     Node* prev = NULL;
//     reverse_recursion(head, current, prev);
//     return head;
// }

// -----------------------------------------------------------------------------


// ------------------------Through recursion 2  -------------------------------
Node* reverse_recursion2(Node* &head){
    if(head == NULL || head -> next_address ==  NULL){          // Empty or single list
        return head;
    }
    Node* chotaHead = reverse_recursion2(head -> next_address);

    head -> next_address -> next_address = head;
    head -> next_address = NULL;

    return chotaHead;
}

// -----------------------------------------------------------------------------



int main()
{
    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    insert_at_tail(tail, 22);
    insert_at_tail(tail, 42);
    insert_at_tail(tail, 25);
    insert_at_tail(tail, 73);
    display(head);
    
    // Node* reverse = reverse_list(head);
    // Node* reverse = reverse_list_through_recursion(head);
    Node* reverse = reverse_recursion2(head);
    while(reverse  != NULL){
        cout<<reverse -> data <<" ";
        reverse = reverse -> next_address;         // increment for traversal.
    }

    return 0;
}
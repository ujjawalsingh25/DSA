// pnd
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

int length(Node* &head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        temp = temp -> next_address;
        count++;
    }   return count;
}

Node* reverseNode(Node* &head){
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

void palindrome_check(Node* &head, Node* &tail){
    int len = length(head)/2;
    Node* temp = head;
    int count =0;
    while(count <= len){
        temp = temp -> next_address;
        count++;
    }
    // cout<<len<<" - " <<temp -> data<<endl;
    Node* revHead = reverseNode(temp);
    display(revHead);
    while(revHead != NULL){
        cout<<revHead -> data <<" - "<< head -> data<<endl;
        if(revHead -> data != head -> data) {
           cout<<"NO"<<endl;
            return;
        }
        revHead = revHead -> next_address;
        head = head -> next_address;
    }   
    cout<<"Yes"<<endl;
}


int main()
{
    Node* node1 = new Node(10);
    
    Node* head = node1;
    Node* tail = node1;

    insert_at_tail(tail, 11);
    insert_at_tail(tail, 12);
    insert_at_tail(tail, 13);
    insert_at_tail(tail, 12);
    insert_at_tail(tail, 11);
    insert_at_tail(tail, 10);
    display(head);
    
    palindrome_check(head, tail);

    return 0;
}
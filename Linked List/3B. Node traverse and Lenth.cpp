#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev_address;
        Node* next_address;
        Node(int data): data(data), prev_address(NULL), next_address(NULL) {}
};

void display(Node* &head){
    Node* temp = head;
    while(temp != 0){
        cout<<temp -> data<<" ";
        temp = temp -> next_address;
    }cout<<endl;
}

int node_length(Node* &head){
    int len=0;
    Node* temp = head;
    while(temp != 0){
        len++;
        temp = temp -> next_address;
    }
    return len;
}

int main()
{
    Node* node1 = new Node(4);

    Node* head = node1;
    display(head);
    int len = node_length(head);
    cout<<len<<endl;

    
    return 0;
}
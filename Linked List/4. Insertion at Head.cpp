#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next_address;
    Node(int data): data(data), next_address(NULL) {}
};

void insert_at_head(Node* &head, int data){
    Node* temp = new Node(data);
    temp -> next_address = head;
    head = temp;                        // head should be on 1st.
}


void display(Node* &head){
    Node* temp = head;              // Because we always traverse from head.
    cout<<endl;
    while(temp  != NULL){
        cout<<temp -> data <<" ";
        temp = temp -> next_address;         // increment for traversal.
    }
    cout<<endl<<endl;
}

int main()
{
    Node* node1 = new Node(10);
    
    Node* head = node1;
    Node* tail = node1;

    insert_at_head(head, 22);
    insert_at_head(head, 55);
    insert_at_head(head, 42);
    insert_at_head(head, 25);
    insert_at_head(head, 73);
    display(head);


    Node* iter = head;
    cout<<"Data"<<" - "<<" Current Address"<< "  - "<< "   Next Address"<<endl;
    for(int i=0; i<6;i++){
        cout<< iter -> data<< "   -   "<<&iter -> data<<"   -   "<<iter -> next_address<<endl;
        iter = iter ->next_address;
    }cout<<endl;

    return 0;
}
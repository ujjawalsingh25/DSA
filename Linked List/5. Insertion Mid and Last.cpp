#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next_address;
        Node(int data): data(data), next_address(NULL) {}
    // Node(int data){
    //     this -> data = data;
    //     this -> next_address = NULL;
    // }
};

void insert_at_head(Node* &head, int data){
    Node* temp = new Node(data);
    temp -> next_address = head;
    head = temp;                        // head should be on 1st.
}


void insert_at_tail(Node* &tail, int data){
    // create a node
    Node* temp = new Node(data);
    tail -> next_address = temp;
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
    temp -> next_address = nodeToInsert;

}


void display(Node* &head){
    Node* temp = head;
    cout<<endl;
    while(temp  != NULL){
        cout<<temp -> data <<" ";
        temp = temp -> next_address;         // increment for traversal.
    }
    cout<<endl;
}

int main()
{
    Node* node1 = new Node(10);
    
    Node* head = node1;
    Node* tail = node1;

    // insert_at_head(head, 22);
    // insert_at_head(head, 55);
    // insert_at_head(head, 42);
    // insert_at_head(head, 25);
    // insert_at_head(head, 73);
    // display(head);

    insert_at_tail(tail, 22);
    insert_at_tail(tail, 55);
    insert_at_tail(tail, 42);
    insert_at_tail(tail, 25);
    insert_at_tail(tail, 73);
    display(head);

    insert_at_midPosition(head, tail, 3, 75);
    display(head);

    Node* iter = head;
    cout<<"\nData"<<" - "<<" Current Address"<< "  - "<< "   Next Address"<<endl;
    for(int i=0; i<6;i++){
        cout<< iter -> data<< "   -   "<<&iter -> data<<"   -   "<<iter -> next_address<<endl;
        iter = iter ->next_address;
    }cout<<endl;

    return 0;
}
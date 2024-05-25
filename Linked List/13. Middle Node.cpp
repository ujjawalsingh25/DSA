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
    cout<<endl;
    while(temp  != NULL){
        cout<<temp -> data <<" ";
        temp = temp -> next_address;         // increment for traversal.
    }
    cout<<endl;
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


// Node* middle_node(Node* &head){
//     Node* temp = head;
//     int len = (node_length(head) / 2);
//     int count =0;
//     while(count<len){
//         temp = temp -> next_address;
//         count++;
//     }
//     return temp;
// }


Node* middle_node(Node* &head){
    if(head == NULL || head -> next_address == NULL)   return head;         // Empty or single node
    if(head -> next_address -> next_address == NULL) {              // For 2 nodes.
           return head -> next_address;                 
    }

    Node* slow = head;
    Node* fast = head -> next_address;

    while(fast != NULL){
        fast = fast -> next_address;
        if(fast != NULL){
            fast = fast -> next_address;
        }
        slow = slow -> next_address;
    }
    return slow;
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

    Node* ans = middle_node(head);
    cout<<"Middle: "<<ans -> data<<"   - "<<&ans -> data<<" - " <<ans -> next_address<<endl<<endl;

    Node* iter = head;
    cout<<"Data"<<" - "<<" Current Address"<< "  - "<< "   Next Address"<<endl;
    for(int i=0; i<6;i++){
        cout<< iter -> data<< "   -   "<<&iter -> data<<"   -   "<<iter -> next_address<<endl;
        iter = iter ->next_address;
    }cout<<endl;

    return 0;
}
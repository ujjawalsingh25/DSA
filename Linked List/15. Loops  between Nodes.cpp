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


Node* check_loop(Node* &head){
    if(head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;// -> next_address;
    while(fast != NULL && slow != NULL){
        fast = fast -> next_address;
        if(fast != NULL){
            fast = fast -> next_address;
        }
        slow = slow -> next_address;

        if(fast == slow)    return slow;
    }
    return NULL;
}


Node* starting_node(Node* &head){
    if(head == NULL) return NULL;
    Node* slow = head;
    Node* intersection_point = check_loop(head);

    while(slow != intersection_point){      // The place where fast and slow equal or intersect 
        slow = slow -> next_address;        // Take slow back to start and fast/ intersection_point will remain at same position
        intersection_point = intersection_point -> next_address;            // From there increment both slow and fast by one.
    }                                                               // The place they again meet is the starting point of loop.
    return slow;
}

void remove_nodeLoop(Node* &head){
    if(head == NULL) return ;

    Node* start_ofLoop = starting_node(head);
    Node* temp = start_ofLoop;

    while(temp -> next_address != start_ofLoop){
        temp = temp -> next_address;
    }
    temp -> next_address = NULL;
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
    tail -> next_address = head -> next_address;
    cout<<"Head: "<<head -> data<<endl;
    cout<<"Tail: "<<tail -> data<<endl;
    // display(head);

    Node* ans_asHead = check_loop(head);
    if(ans_asHead != NULL){
        cout<<"Loop Present"<<endl;
    }
    else{
       cout<<"Loop not present"<<endl; 
    }

    Node* start = starting_node(head);
    cout<<"Loop starts at: "<<start -> data<<endl;

    remove_nodeLoop(head);
    display(head);

    return 0;
}
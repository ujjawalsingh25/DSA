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

void mergeNode(Node* &first, Node* &second){
    Node* current1 = first;
    Node* forward1 = first -> next_address;
    Node* current2 = second;
    Node* forward2 = second -> next_address;
    
    while(forward1 != NULL && forward2 != NULL){
        if(current1 -> data <= current2 -> data && current2 -> data <= forward1 -> data){
            current1 -> next_address = current2;
            forward2 = current2 -> next_address;
            current2 -> next_address = forward1;
            current1 = current2;
            current2 = forward2;
        }
        else {
            current1 = forward1;
            forward1 = forward1 -> next_address;
            // Attach the remaining nodes, if any
            if (forward1 == NULL) {
                current1 -> next_address = current2;
            }    
        }
    }
}

Node* merge_nodes(Node* head1, Node* &head2){
    // if (head1 == NULL && head2 == NULL) return NULL;
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    if(head1 -> data <= head2 -> data){
        mergeNode(head1, head2);
        return head1;
    }
    else{
        mergeNode(head2, head1);
        return head2;
    }
}




int main()
{
    Node* node1 = new Node(10);
    Node* node2 = new Node(23);
    
    Node* head1 = node1;
    Node* tail1 = node1;
    Node* head2 = node2;
    Node* tail2 = node2;

    insert_at_tail(tail1, 22);
    insert_at_tail(tail1, 55);
    insert_at_tail(tail1, 62);
    display(head1);
    cout<<"Head: "<<head1 -> data<<endl;
    cout<<"Tail: "<<tail1 -> data<<endl;

    insert_at_tail(tail2, 25);
    insert_at_tail(tail2, 36);
    insert_at_tail(tail2, 73);
    display(head2);
    cout<<"Head: "<<head2 -> data<<endl;
    cout<<"Tail: "<<tail2 -> data<<endl;

    Node* ans_asHead = merge_nodes(head1, head2);
    display(ans_asHead);
    // cout<<"Ans: "<<ans_asHead -> data<<endl;

    return 0;
}
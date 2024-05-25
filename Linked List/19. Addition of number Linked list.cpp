
#include<iostream>
#include<vector>
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


Node* addNo(Node* &first, Node* &second){
    int sum=0, carry=0, digit=0;
    Node* sumVal = NULL;
    Node* headSum = sumVal;
    while(first != NULL || second != NULL || carry != 0){

        int val1 = (first != NULL) ? first->data : 0;
        int val2 = (second != NULL) ? second->data : 0;
        cout<<val1<<" + "<<val2<<endl;    
        sum = val1 + val2 + carry;
        digit = sum % 10;                      // / 13%10 = 3  ->> digit
        carry = sum / 10;                     // 13/10 = 1  ->> carry
        Node* add = new Node(digit);

        if(sumVal == NULL){
            sumVal = add;
            headSum = sumVal;
        }
        else{
            sumVal->next_address = add;
            sumVal = sumVal->next_address;
        }

        if (first != NULL) first = first->next_address;
        if (second != NULL) second = second->next_address;
    }
    cout<<"----------"<<endl;
    return headSum;
}

void sum_number(Node* &head1, Node* &head2){
    Node* first = reverseNode(head1);
    Node* second = reverseNode(head2);
    display(first);
    display(second);    cout<<"---------"<<endl; 

    Node* addition = addNo(first, second);
    Node* answer = reverseNode(addition);
    display(answer);
}



int main()
{
    Node* node1 = new Node(3);
    Node* node2 = new Node(3);
    
    Node* head1 = node1;
    Node* tail1 = node1;
    Node* head2 = node2;
    Node* tail2 = node2;

    insert_at_tail(tail1, 5);
    display(head1);

    insert_at_tail(tail2, 4);
    insert_at_tail(tail2, 5);
    display(head2);             cout<<"---------"<<endl;

    sum_number(head1, head2);

    return 0;
}
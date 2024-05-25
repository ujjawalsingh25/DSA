/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


// ----------- Clone using MAP. -------------------------------------------------

#include<bits/stdc++.h>
#include<unordered_map>

void insert_at_tail(Node* &cloneHead, Node* &cloneTail, int data){
    Node* insert = new Node(data);
    if(cloneHead == NULL){
        cloneHead = insert;
        cloneTail = insert;
        return;
    }
    else{
        cloneTail -> next = insert;
        cloneTail = insert;
    }
}

class Solution {
public:
    Node* copyRandomList(Node* head) {
// Step 1: Create a clone NODE.
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL){
            insert_at_tail(cloneHead, cloneTail, temp -> val);
            temp = temp -> next;
        }

// Step 2: Create a map.
        
        unordered_map<Node* , Node*> mapp;
        Node* realNode = head;
        Node* cloneNode = cloneHead;
        while(realNode != NULL && cloneNode != NULL){
            mapp[realNode] = cloneNode;
            realNode = realNode -> next;
            cloneNode = cloneNode -> next;
        }
        
// Step 3: Copy ramdom address of real Node to clone Node.
        realNode = head;            // Again put to head.
        cloneNode = cloneHead;      // Again put clonehead at list head
        while(realNode != NULL){
            cloneNode -> random = mapp[realNode -> random];
            realNode = realNode -> next;
            cloneNode = cloneNode -> next;
        }
      return cloneHead;
    }
};
// ------------------------------------------------------------------------------


// ----- Clone without mapping ------------------------------------------------

// Node* copyRandomList(Node* head) {
// // Step 1: Create a clone list.
//         Node* cloneHead = NULL;
//         Node* cloneTail = NULL;
//         Node* temp = head;
//         while(temp != NULL){
//             insert_at_tail(cloneHead, cloneTail, temp -> val);
//             temp = temp -> next;
//         }
// // Step 2: Add clone list in between of real list.
//         Node* realHead = head;
//         cloneHead = head;
//         Node* realForward = NULL;
//         Node* cloneForward = NULL;
//         while(realHead != NULL && cloneHead != NULL){
//             realForward = realHead -> next;
//             realHead -> next = cloneHead;
//             realHead = realForward;

//             cloneForward = cloneHead -> next;
//             cloneHead -> next = realHead;       // realHead has been forwarded prev.
//             cloneHead = cloneForward;
//         }
// // Step 3: Copy random pointers
//         temp = head;
//         while(temp != NULL){
//             // temp -> next -> random = temp -> next ? temp -> random -> next: temp -> random;
//             if(temp -> next != NULL){
//                 if(temp -> random != NULL){
//                     temp -> next -> random = temp -> random -> next;
//                 }    
//             }
//             else{
//                 temp -> next = temp -> random;
//             }
//             temp = temp -> next -> next;
//         }
// // Step 4: Revert changes done in step 2.
//         realHead = head;
//         cloneHead = head;
//         while(realHead != NULL && cloneHead != NULL){
//             realHead -> next = cloneHead -> next;
//             realHead = realHead -> next;

//             if(realHead != NULL){
//                 cloneHead -> next = realHead -> next;
//             }cloneHead = cloneHead -> next;
//         }
//       return cloneHead;
    // }
// };
// ------------------------------------------------------------------------------



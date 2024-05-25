#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

class node{
  public:
    int data;
    node* left;
    node* right;

    node(int data) : data(data) , left(NULL) , right(NULL) {}  
};

node* buildTree(node* root){
    int data;
    cout<<"enter node data: ";
    cin>>data;

    root = new node(data);
    if(data == -1) return NULL;

    cout<<"For left insertion of " <<data<<" ";
    root -> left = buildTree(root -> left);
    cout<<"For right insertion of " <<data<<" ";
    root -> right = buildTree(root -> right);
  return root;
}

void displayTree(node* root){
    queue<node*> quu;
    quu.push(root);
    quu.push(NULL);         // seperator in order to seperate parent and child in levels

    while(!quu.empty()){
        node* temp = quu.front();
        quu.pop();

        if(temp == NULL){           // Last level completed line_Break for next level
            cout<<endl;
            if(!quu.empty())    quu.push(NULL);         // Seperator for further nodes
        }
        else{           
            cout<<temp->data<<" ";

            if(temp-> left) quu.push(temp -> left);
            if(temp-> right) quu.push(temp -> right);
        }
    }
}

// ----------------------------------------------------------------------------------
// enter data : 5 3 1 -1 2 -1 -1 4 -1 -1 7 6 -1 -1 8 -1 -1
// ----- Displaying Tree ------                     
//           5                            
//        /    \                
//       3      7          
//     /  \    /  \         
//    1   4   6    8        
//     \             
//      2      
// InOrder : 1 2 3 4 5 6 7 8    -->>> InORder Traversal in BST always give sorted nodes 
// Enter kth place : 3
// Kth Smallest Node Val : 3
// Kth Largest Node Val : 5
// ----------------------------------------------------------------------------------
// ******************************************************************
// ||     InORder Traversal in BST always give sorted nodes         ||
// ******************************************************************
// Time Complexity: O(n)
// Space Complexity: O(n) 
// ----------------------------------------------------------------------------------

void findUsingInOrder(node* root, int place, int &count, int &kth_val){
    if(root == NULL || count >= place)  return;

    findUsingInOrder(root -> left, place, count, kth_val);       //  InORder Traversal in BST always give sorted nodes    
    count++;
    // cout<<root -> data<<" ";
    if(count == place) {
        kth_val = root -> data;
        return;
    }
    findUsingInOrder(root -> right, place, count, kth_val);      // InORder Traversal in BST always give sorted nodes    
}

int k_SmallestVal(node* root, int place){
    int count = 0;
    int kth_val = -1;
    findUsingInOrder(root, place, count, kth_val);

  return kth_val;  
}

int main()
{
    int place;
    node* root = NULL;
    root = buildTree(root);
    cout<<endl<<"----- Displaying Tree ------"<<endl;
    displayTree(root);

     cout<<"-------------------"<<endl;
    cout<<"Enter kth place : ";
    cin>>place;
    int valSmallest = k_SmallestVal(root, place);
    int valLargest = k_SmallestVal(root, 8 - place);            // For largest (n-k)th place of smallest
    cout<<"Kth Smallest Node Val : "<<valSmallest<<endl;
    cout<<"Kth Largest Node Val : "<<valLargest<<endl;

  return 0;
}
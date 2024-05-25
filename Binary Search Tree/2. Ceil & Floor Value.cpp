#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
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
// enter data : 8 5 4 -1 -1 7 6 -1 -1 -1 12 10 -1 -1 14 13 -1 -1 -1 
// ----- Displaying Tree ------                     
//           8                            
//        /     \                
//       5       12          
//     /  \     /  \         
//    4    7   10   14         
//        /         /
//       6         13
// Enter value to find Ceil & Floor : 9
// Floor Value : 8
// Ceil Value : 10
// ----------------------------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(n) 
// ----------------------------------------------------------------------------------


int floorVal(node* root, int num){
    int floor = -1;
    while(root != NULL){
        if(root -> data == num)     return root -> data;
        if(num > root->data){
            floor = root -> data;
            root = root -> right;
        }   
        else    root = root -> left;
    }
  return floor;   
}

int ceilVal(node* root, int num){
    int ceil = -1;
    while(root != NULL){
        if(root -> data == num)     return root -> data;
        if(num > root->data)   root = root -> right;
        else {
            ceil = root -> data;
            root = root -> left;
        }
    }
  return ceil;  
}


int main()
{
    int num;
    node* root = NULL;
    root = buildTree(root);
    cout<<endl<<"----- Displaying Tree ------"<<endl;
    displayTree(root);

    cout<<"-------------------"<<endl;
    cout<<"Enter value to find Ceil & Floor : ";
    cin>>num;

    int floor = floorVal(root, num);
    cout<<"Floor Value : "<<floor<<endl;
    int ceil = ceilVal(root, num);
    cout<<"Ceil Value : "<<ceil<<endl;
    
  return 0;
}
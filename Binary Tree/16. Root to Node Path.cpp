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
// enter data : 1 2 4 -1 -1 5 6 -1 -1 7 -1 -1 3 -1 -1
// ----- Displaying Tree ------                     
//          1                              
//        /   \            
//       2     3          
//     /  \                 
//    4    5        
//       /   \
//      6     7
// Enter node value to find path : 7
// Root to Node Path : 1 2 5 7
// ----------------------------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(height of tree) 
// ----------------------------------------------------------------------------------

bool findNode(node* root, vector<int> &arr, int nodeVal){
    if(!root)   return false;
    arr.push_back(root -> data);

    if(root -> data == nodeVal) return true;
    if(findNode(root -> left, arr, nodeVal) || findNode(root -> right, arr, nodeVal))   return true;

    arr.pop_back();
    return false;
}

vector<int> rootToNodePath(node* root, int nodeVal){  
    vector<int> arr;
    if(root == NULL)    return arr;
    findNode(root, arr, nodeVal);
  return arr;  
}



int main()
{
    int nodeVal;
    node* root = NULL;
    root = buildTree(root);
    cout<<endl<<"----- Displaying Tree ------"<<endl;
    displayTree(root);
    cout<<"Enter node value to find path : ";
    cin>>nodeVal;

    vector<int> arr = rootToNodePath(root, nodeVal);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    
  return 0;
}
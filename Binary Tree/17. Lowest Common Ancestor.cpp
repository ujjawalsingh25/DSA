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
// enter data : 1 2 4 -1 -1 5 6 -1 -1 7 -1 -1 3 8 -1 -1 9 -1 -1
// enter data2 : 1 2 -1 -1 3 4 8 -1 -1 -1 5 6 -1 -1 7 -1 -1
// ----- Displaying Tree ------                     
//            1                          1                              
//        /      \                    /    \            
//       2        3                  2      3          
//     /  \      / \                      /   \           
//    4    5    8   9                    4     5               
//       /   \                         /     /   \              
//      6     7                       8     6     7            
//Enter node1 : 4
// Enter node2 : 7
// Lowest Common Ancestor for both node : 2

// **************************** Brute Force ******************************************************
// Time Complexity: O(n) + O(n)
// Space Complexity: O(n) + O(n)
// ----------------------------------------------------------------------------------
bool findNode(node* root, vector<int> &arr, int nodeVal){
    if(root == NULL)    return false;
    arr.push_back(root -> data);
    
    if(root -> data == nodeVal)     return true;
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

int brute_lowestCommonAncestor(node* root, int node1, int node2){
    vector<int> arrNode1 = rootToNodePath(root, node1);
    vector<int> arrNode2 = rootToNodePath(root, node2);
    int arrSize = min(arrNode1.size(), arrNode2.size());
    int storeAns = -1;
    for(int i=0;i<arrSize;i++){
        if(arrNode1[i] == arrNode2[i]){
           storeAns = arrNode1[i]; 
        }  
        else    return storeAns;
    } 
  return storeAns;
}
// ****************************************************************************************************



// // **************************** Optimised ******************************************************
// Time Complexity: O(n)
// Space Complexity: O(n) 
// ----------------------------------------------------------------------------------
node* lowestCommonAncestor(node* root, int node1, int node2){
    if(root == NULL || root -> data == node1 || root -> data == node2)  return root;

    node* leftCheck = lowestCommonAncestor(root -> left, node1, node2);
    node* rightCheck = lowestCommonAncestor(root -> right, node1, node2);

    if(leftCheck == NULL)   return rightCheck;          // none of the node1 or node2 is not on left side
    else if(rightCheck == NULL)   return leftCheck;      // none of the node1 or node2 is not on right side
    else  return root;                       // both left and right are not NULL so the common Ancestor node.
}
// // ************************************************************************************************

int main()
{
    node* root = NULL;
    root = buildTree(root);
    cout<<endl<<"----- Displaying Tree ------"<<endl;
    displayTree(root);
    int node1, node2;
    cout<<"Enter node1 : ";
    cin>>node1;
    cout<<"Enter node2 : ";
    cin>>node2;

    cout<<"Lowest Common Ancestor for both node (Brute): ";
    int lca = brute_lowestCommonAncestor(root, node1, node2); 
    cout<<lca<<endl;

    cout<<"Lowest Common Ancestor for both node (Optimal): ";
    node* lca2 = lowestCommonAncestor(root, node1, node2);
    cout<<lca2 -> data<<endl;


  return 0;
}  
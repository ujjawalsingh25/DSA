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
// enter data : 0 1 3 7 -1 -1 8 -1 -1 4 9 -1 -1 10 -1 -1 2 5 11 -1 -1 12 -1 -1 6 13 -1 -1 14 -1 -1
// ----- Displaying Tree ------                     
//                 0                                                     
//            /         \                              
//         1              2                          
//      /    \          /    \                                                                      
//     3      4       5        6                                                                           
//    / \    / \     / \      / \                                                                                  
//   7   8  9   10  11   12  13  14                                                                                   
//Maximum Width of Tree : 8
// ******************************************************************************************
// Time Complexity: O(n)
// Space Complexity: O(n) 
// ----------------------------------------------------------------------------------
int maxWidthOfTree(node* root){
   if(root == NULL)   return 0;
   int ans = 0;
   queue<pair<node*, int>>quu;
   quu.push({root, 0});
   while(!quu.empty()){
    int firstNode, lastNode;
    int size = quu.size();
    int mmin = quu.front().second;
    for(int i=0;i<size;i++){
      int currentIntVal = quu.front().second - mmin;
      node* currentNode = quu.front().first;
      quu.pop();
      if(i == 0)  firstNode = currentIntVal;
      if(i == size-1)   lastNode = currentIntVal;
      if(currentNode -> left != NULL)   quu.push({currentNode->left, currentIntVal * 2 + 1});
      if(currentNode -> right != NULL)   quu.push({currentNode->right, currentIntVal * 2 + 2});
    }
      ans = max(ans, lastNode - firstNode + 1); 
   }
  return ans;
}
// ************************************************************************************************

int main()
{
    node* root = NULL;
    root = buildTree(root);
    cout<<endl<<"----- Displaying Tree ------"<<endl;
    displayTree(root);

    cout<<"Width of Binary Tree : ";
    int width = maxWidthOfTree(root); 
    cout<<width<<endl;

  return 0;
}  
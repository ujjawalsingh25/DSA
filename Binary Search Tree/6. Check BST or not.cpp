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
// enter data : 13 10 7 -1 9 8 -1 -1 -1 12 -1 -1 15 14 -1 -1 17 16 -1 -1 -1
// enter data 2 : 13 10 7 -1 9 8 -1 -1 -1 14 -1 -1 15 14 -1 -1 17 16 -1 -1 -1
// ----- Displaying Tree ------                     
//           13          |              13                                                             
//        /     \        |           /     \          
//       10      15      |          10      15                                           
//     /   \    /  \     |        /   \    /  \                                          
//    7    12  14  17    |       7    14  14  17  
//     \           /     |        \           /                                    
//      9         16     |         9         16                                  
//     /                 |        /                                  
//    8                  |       8                                 
// Binary Search Tree    |           Not a BST
// ----------------------------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(n) 
// ----------------------------------------------------------------------------------

bool isValidBST(node* root, long minVal, long maxVal){
  if(root == NULL)  return true;
  if(root -> data >= maxVal || root -> data <= minVal)  return false;
  return isValidBST(root -> left, minVal, root -> data) &&        // move left & check range from minVal to prev root value
          isValidBST(root -> right, root -> data, maxVal);      // move right & check range from prev root value to maxVal
}

bool checkBST(node* root){
    return isValidBST(root, INT_MIN, INT_MAX);
}

int main()
{
    int place;
    node* root = NULL;
    root = buildTree(root);
    cout<<endl<<"----- Displaying Tree ------"<<endl;
    displayTree(root);

    cout<<"-------------------"<<endl;
    bool check = checkBST(root);
    if(check) cout<<"Binary Search Tree"<<endl;
    else  cout<<"Not a Binary Search Tree"<<endl;

  return 0;
}
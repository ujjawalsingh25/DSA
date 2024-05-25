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
// enter data : 9 8 5 3 2 1 -1 -1 -1 4 -1 -1 7 6 -1 -1 8 -1 -1 -1 12 10 -1 13 -1 -1 13 -1 -1  
// ----- Displaying Tree ------                     
//                    9                                                   9                                                                                               
//                /       \                                            /     \                                                                                   
//               8         12                                         8       12                                                                                         
//              /        /    \         ----------->>                /       /  \                                                                               
//            (5)       10    13      After Deletion                3       10   13                                                                                           
//         /      \      \                                         / \       \                                                                                 
//        3         7     13                                      2   4       13                              
//       / \      /   \                                          /     \                                                                                                    
//      2   4    6     8                                        1   (   7    )     --->> Attach to 4 to maintain BST rule                                                              
//     /                                                            (  /  \  )        (added to right most leaf of deleted left Node)                           
//    1                                                             ( 6    8 )      
//  Enter node value to delete : 5
// ----------------------------------------------------------------------------------
// Time Complexity: O(height of Tree)
// Space Complexity: NULL
// ----------------------------------------------------------------------------------

node* findLastRight(node* root){                    // find Right MOST leaf node in Left SIde of deleted node
    if(root -> right == NULL)   return root;        //  and attach the deleted part to right so as to maintain BST
  return findLastRight(root -> right);              // as deleted rightNodes will be higher value Eg. (7,6,8) nodes are higher and need
}                                          //  need to be in right to maintain BST so added to right most leaf of deleted left Node (eg 4)     
node* cutAndMerge(node* root){
    if(root -> left == NULL)    return root -> right;
    else if(root -> right == NULL)  return root -> left;        
    node* rightChild = root -> right;
    node* lastRight = findLastRight(root -> left);
    
    lastRight -> right = rightChild;            // added to right most leaf of deleted left Node
  return root -> left;
}

node* deleteNodeBST(node* root, int num){
    if(root == NULL)    return NULL;
    if(root->data == num)   return cutAndMerge(root);

    node* savedRoot = root;         // save current main root to return as further change will treverse through
    while(root != NULL){                            // root so at last it will point to root before deleted node.
        if(root -> data > num){
            if(root -> left != NULL && root->left->data == num){
                root -> left = cutAndMerge(root -> left);
                break;
            }
            else  root = root -> left;
        } else {
            if(root -> right != NULL && root->right->data == num){
                root -> right == cutAndMerge(root -> right);
                break;
            }
            else  root = root -> right; 
        }
    }

  return savedRoot;  
}

int main()
{
    int num;
    node* root = NULL;
    root = buildTree(root);
    cout<<endl<<"----- Displaying Tree ------"<<endl;
    displayTree(root);

    cout<<"-------------------"<<endl;
    cout<<"Enter node value to delete : ";
    cin>>num;
    node* inserted = deleteNodeBST(root, num);
    cout<<endl<<"----- After Deletion Tree ------"<<endl;
    displayTree(inserted);

  return 0;
}
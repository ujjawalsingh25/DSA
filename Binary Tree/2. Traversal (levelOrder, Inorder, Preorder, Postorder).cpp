#include<iostream>
#include<queue>
using namespace std;

class node{
  public:
    int data;
    node* left;
    node* right;

    // node(int data): data(data), left(NULL), right(NULL) {}
    node(int data){
        this->data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root){
    int data;
    cout<<"Enter root data: ";
    cin>>data;

    root = new node(data);
    if(data == -1)  return NULL;

    cout<<"Enter data for left insertion of "<<data<<endl;
    root -> left = buildTree(root -> left);
    cout<<"Enter data for right insertion of "<<data<<endl;
    root -> right = buildTree(root -> right);

    return root;
}

// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1 
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

// -------------------------------------------------------------------------------------------------
// Enter root data: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// Enter data for left insertion of 1
// Enter data for left insertion of 3
// Enter data for left insertion of 7
// Enter data for right insertion of 7
// Enter data for right insertion of 3
// Enter data for left insertion of 11
// Enter data for right insertion of 11
// Enter data for right insertion of 1
// Enter data for left insertion of 5
// Enter data for left insertion of 17
// Enter data for right insertion of 17
// Enter data for right insertion of 5

// ----- Displaying Tree (Level Order Traversal)------
//     1
//    3 5
//  7 11 17
// Inorder Traversal: 7 3 11 1 17 5
// Preorder Traversal: 1 3 7 11 5 17
// Postorder Traversal: 7 11 3 17 5 1
// -------------------------------------------------------------------------------------------------

void levelOrderTraversal(node* root){
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


void inOrderTraversal(node* root){
    if(root == NULL)  return;

    inOrderTraversal(root -> left);
    cout<< root -> data <<" ";
    inOrderTraversal(root -> right);
}


void preOrderTraversal(node* root){
    if(root == NULL)  return;
    
    cout<< root -> data <<" ";
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);
}


void postOrderTraversal(node* root){
    if(root == NULL)  return;
    
    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);
    cout<< root -> data <<" ";
}


int main()
{
    node* root = NULL;

    // Creating Tree
    root = buildTree(root);

    // traversal in tree
    cout<<endl<<"----- Displaying Tree (Level Order Traversal)------"<<endl;
    levelOrderTraversal(root);

    cout<<"Inorder Traversal: ";
    inOrderTraversal(root);
    
    cout<<"\nPreorder Traversal: ";
    preOrderTraversal(root);

    cout<<"\nPostorder Traversal: ";
    postOrderTraversal(root);

    return 0;
}
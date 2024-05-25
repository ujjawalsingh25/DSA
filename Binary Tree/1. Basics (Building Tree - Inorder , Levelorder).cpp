#include<iostream>
#include<queue>
using namespace std;

// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1 
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

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


void level_Order_Traversal(node* root){
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


// --------------------------------------------------------------------------
// Enter root data: 1
// Enter left node data of 1 : 3
// Enter right node Data of 1 : 5
// Enter left node data of 3 : 7
// Enter right node Data of 3 : 11
// Enter left node data of 5 : 17
// Enter right node Data of 5 : -1
// Enter left node data of 7 : -1
// Enter right node Data of 7 : -1
// Enter left node data of 11 : -1
// Enter right node Data of 11 : -1
// Enter left node data of 17 : -1
// Enter right node Data of 17 : -1

// ----- Displaying Tree ------
// 1
// 3 5
// 7 11 17 
// --------------------------------------------------------------------------

void buildFrom_LevelOrder(node* &root){
    int data, leftData, rightData;
    queue<node*> quu;
    cout<<"Enter root data: ";
    cin>>data;
    root = new node(data);
    quu.push(root);

    while(!quu.empty()){
        node* temp = quu.front();
        quu.pop();

        cout<<"Enter left node data of "<<temp -> data<<" : ";
        cin>>leftData;
        if(leftData != -1){
           temp -> left = new node(leftData);
           quu.push(temp -> left);
        }
    
        cout<<"Enter right node Data of "<<temp -> data<<" : ";
        cin>>rightData;
        if(rightData != -1){
           temp -> right = new node(rightData);
           quu.push(temp -> right);
        }

    }
}


int main()
{
    node* root = NULL;

    // Creating Tree
    
    // 1. Inorder wise
    // root = buildTree(root);
    
    // 2. level Order Wise
    buildFrom_LevelOrder(root);


    // traversal in tree
    cout<<endl<<"----- Displaying Tree ------"<<endl;
    level_Order_Traversal(root);

    return 0;
}
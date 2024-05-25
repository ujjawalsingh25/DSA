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
// enter data : 8 5 4 -1 -1 7 -1 -1 12 -1 -1 
// ----- Displaying Tree ------                     
//          8                            
//        /   \                
//       5    12          
//     /  \               
//    4    7              
// InOrder Traversal : 4 5 7 8 12
// The next value in BST : 4
// The next value in BST : 5
// The next value in BST : 7
// BST have more nodes
// The next value in BST : 8
// The next value in BST : 12
// The next value in BST : -1
// BST have no nodes                
// ----------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------

class BST_iterator{
private:
    stack<node*> stk;
    void pushAll(node* root){
        for( ; root != NULL; stk.push(root), root = root -> left);
    }

public:
    BST_iterator(node* root){
        pushAll(root);
    }

    bool hasNext(){
       return !stk.empty();
    }

    int next() {
        if(!hasNext())  return -1; 
        node* tempNode = stk.top();
        stk.pop();
        pushAll(tempNode -> right);
      return tempNode -> data;
    }
};



int main()
{
    int num;
    node* root = NULL;
    root = buildTree(root);
    cout<<endl<<"----- Displaying Tree ------"<<endl;
    displayTree(root);

    cout<<"-------------------"<<endl;
    BST_iterator iter(root);
    cout<<"The next value in BST : "<<iter.next()<<endl;
    cout<<"The next value in BST : "<<iter.next()<<endl;
    cout<<"The next value in BST : "<<iter.next()<<endl;
    if(iter.hasNext())  cout<<"BST have more nodes"<<endl;
    else    cout<<"BST have no nodes"<<endl;

    cout<<"The next value in BST : "<<iter.next()<<endl;
    cout<<"The next value in BST : "<<iter.next()<<endl;
    cout<<"The next value in BST : "<<iter.next()<<endl;
    if(iter.hasNext())  cout<<"BST have more nodes"<<endl;
    else    cout<<"BST have no nodes"<<endl;

  return 0;
}
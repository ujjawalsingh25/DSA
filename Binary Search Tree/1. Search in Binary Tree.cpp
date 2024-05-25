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
// ----------------------------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(n) 
// ----------------------------------------------------------------------------------

node* searchInTree(node* root, int num){
    while(root != NULL && root -> data != num){
        if(root->data < num)    root = root -> right;
        else root = root -> left;
    }
  return root;  
}

int main()
{
    int num;
    node* root = NULL;
    root = buildTree(root);
    cout<<endl<<"----- Displaying Tree ------"<<endl;
    displayTree(root);

    cout<<"-------------------"<<endl;
    cout<<"Enter value to search : ";
    cin>>num;
    node* search = searchInTree(root, num);
    if(search)
        cout<<"Searched Value in Tree : "<<search -> data<<endl;
    else
        cout<<"Value not found in Tree"<<endl;

  return 0;
}
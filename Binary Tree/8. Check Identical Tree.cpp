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

// ---------------------------------------------------
// enter root1 : 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
// enter root2 : 1 2 3 -1 -1 -1 5 6 -1 -1 7 -1 -1
// ----- Displaying Tree ------
//            1                          1                            
//          /    \                     /  \           
//        2       5                   2    5        
//       / \     /  \               /    /   \
//      3   4   6    7             3    6     7
// -------------------------------------------------------
// Time Complexity: O(n)   
// Space Complexity: O(n)
// -------------------------------------------------------

// ***** Checks the preOrder values ***** -->> checks root data if same move further Left then Right.
// bool isIdenticalTree(node* root1, node* root2){
//     if(root1 == NULL && root2 == NULL)  return true;
//     if(root1 == NULL || root2 == NULL)  return false;

//     if(root1 -> data != root2 -> data)  return false;
    
//     return isIdenticalTree(root1 -> left, root2 -> left)
//     && isIdenticalTree(root1 -> right, root2 -> right);
    
// }


// Same upper code with enhanced readibility
bool isIdenticalTree(node* root1, node* root2){
    if(root1 == NULL || root2 == NULL)  return (root1 == root2);      // if values same then true else false.

    return (root1 -> data == root2 -> data)                        // (2 == 5) -->> false OR (2 == 2) -->> true
        && isIdenticalTree(root1 -> left, root2 -> left)
        && isIdenticalTree(root1 -> right, root2 -> right);    
}



int main()
{
    node* root1 = NULL;
    node* root2 = NULL;

    root1 = buildTree(root1);
    cout<<endl;
    root2 = buildTree(root2);

    cout<<endl<<"----- Displaying Tree 1 ------"<<endl; 
    displayTree(root1);
    cout<<endl<<"----- Displaying Tree 2 ------"<<endl; 
    displayTree(root2);

    bool check = isIdenticalTree(root1, root2);
    if(check == true)   cout<<"Identical Tree"<<endl;
    else    cout<<"Not Identical Tree"<<endl;

  return 0;
}
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
// enter data : 1 2 3 -1 -1 4 -1 -1 2 4 -1 -1 3 -1 -1
// enter data2 : 1 2 -1 3 -1 -1 2 -1 3 -1 -1
// ----- Displaying Tree ------                     
//           1                    1                 
//        /     \               /   \      
//       2       2             2     2
//     /  \     /  \            \     \
//    3    4   4    3            3     3
//         Symmetry             Not-Symmertry
// ----------------------------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(n) 
// ----------------------------------------------------------------------------------

bool isSymmetry(node* left, node* right){
    if(left == NULL || right == NULL)   return left == right;    // if both null return true else false
    if(left -> data != right -> data)   return false;

  return isSymmetry(left -> left, right -> right)              
              && isSymmetry(left -> right, right -> left);
    // for symmetric we go left's -> right && right's -> left (say 2 -> right (4) && 2 -> left(4)).
    // same for RIGHT NODE, we go left's -> right && right's -> left (say 3 -> left (3) && 2 -> right (3))
}

bool isSymmetricTree(node* root){  
    return root == NULL || isSymmetry(root -> left, root -> right);     // any true then true if both false then only false.
}



int main()
{
    node* root = NULL;
    root = buildTree(root);
    cout<<endl<<"----- Displaying Tree ------"<<endl;
    displayTree(root);

    bool check = isSymmetricTree(root);
    if(check)   cout<<"Symmetric Tree"<<endl;
    else    cout<<"Not Symmetric Tree"<<endl;
  return 0;
}
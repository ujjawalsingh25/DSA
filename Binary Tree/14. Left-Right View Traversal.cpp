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
// enter data : 1 2 4 -1 -1 5 6 -1 -1 -1 3 -1 7 -1 -1
// ----- Displaying Tree ------                     
//               (1)                 ---> level 0                           
//            /       \                             
//         (2)         (3)           ---> level 1      
//       /     \           \               
//    (4)      (5)        (7)        ---> level 2                                                          
//            /                                  
//          (6)                      ---> level 3       
// LeftView Traversal : 1 2 4 6               
// RightView Traversal : 1 3 7 6               
// ----------------------------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(height of tree) 
// ----------------------------------------------------------------------------------

void recursiveLeftRightView(node* root, int level, vector<int> &arr,int left){       
    if(root == NULL)    return;
    if(arr.size() == level) arr.push_back(root -> data);
    if(left){
        recursiveLeftRightView(root -> left, level+1, arr, 1);               
        recursiveLeftRightView(root -> right, level+1, arr, 1);              // JUST CHANGE LEFT-RIGHT ORDER            
    } else {                                                                // for left or right view.                  
        recursiveLeftRightView(root -> right, level+1, arr, 0);
        recursiveLeftRightView(root -> left, level+1, arr, 0);
    }
}

vector<int> leftViewTraversal(node* root){
    vector<int> arr;
    recursiveLeftRightView(root, 0, arr, 1);
  return arr;
}
vector<int> rightViewTraversal(node* root){
    vector<int> arr;
    recursiveLeftRightView(root, 0, arr, 0);
  return arr;
}


int main()
{
    node* root = NULL;
    root = buildTree(root);
    cout<<endl<<"----- Displaying Tree ------"<<endl;
    displayTree(root);

    cout<<"LeftView Travesal Nodes : "<<endl;
    vector<int> arrLeft = leftViewTraversal(root);
    for(int i=0;i<arrLeft.size();i++){
        cout<<arrLeft[i]<<" ";
    }

    cout<<"\nRightView Travesal Nodes : "<<endl;
    vector<int> arrRight = rightViewTraversal(root);
    for(int i=0;i<arrRight.size();i++){
        cout<<arrRight[i]<<" ";
    }

  return 0;
}
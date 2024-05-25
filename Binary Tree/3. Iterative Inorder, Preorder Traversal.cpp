#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

class node {
    public:
    int data;
    node *left;
    node *right;

    node(int data) : data(data), left(NULL), right(NULL) {}
};

node * buildTree(node * root){
    int data;
    cout<<"enter data : ";
    cin>>data;
    cout<<endl;

    root = new node(data);
    if(data == -1)  return NULL;

    cout<<"For left insertion of "<<data<<" ";
    root -> left = buildTree(root -> left);
    cout<<"For right insertion of "<<data<<" ";
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
// enter data : 1 2 4 -1 -1 5 6 -1 -1 7 -1 -1 3 -1 -1
// ----- Displaying Tree ------
//        1
//    2       3
// 4     5
//     6   7
// -------------------------------------------------------


// ******** Inorder Traversal: 4 2 6 5 7 1 3
// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> iterative_inorderTraversal(node* root){
    vector<int> ans;
    stack<node*> stk;
    node* nodeRoot = root;
    
    while(true){
        if(nodeRoot != NULL){
            stk.push(nodeRoot);
            nodeRoot = nodeRoot -> left;
        } else{
            if(stk.empty()) break;
            nodeRoot = stk.top();
            stk.pop();
            ans.push_back(nodeRoot -> data);
            nodeRoot = nodeRoot -> right;
        }
    }
  return ans;
}


// ***** PreOrder Traversal: 1 2 4 5 6 7 3
// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> iterative_preOrderTraversal(node* root){
    vector<int> ans;
    stack<node*> stk;
    if(root == NULL)    return ans;
    
    stk.push(root);
    while(!stk.empty()){
        root = stk.top();
        stk.pop();
        ans.push_back(root -> data);
        if(root -> right != NULL)   stk.push(root->right);
        if(root -> left != NULL)    stk.push(root->left);
    }
  return ans;
}



int main()
{
    node* root = NULL;
    root = buildTree(root);

    cout<<endl<<"----- Displaying Tree ------"<<endl;
    displayTree(root);

    vector<int> arrInorder = iterative_inorderTraversal(root);
    cout<<"Inorder Traversal: ";
    for(int i=0;i<arrInorder.size();i++){
        cout<<arrInorder[i]<<" ";
    }

    vector<int> arrPreorder = iterative_preOrderTraversal(root);
    cout<<"\nPreOrder Traversal: ";
    for(int i=0;i<arrPreorder.size();i++){
        cout<<arrPreorder[i]<<" ";
    }

    return 0;
}

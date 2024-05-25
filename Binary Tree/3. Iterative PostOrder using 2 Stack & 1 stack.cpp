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

// ******  USING TWO STACK *************************
// ******** postOrder Traversal: 4 6 7 5 2 3 1 
// Time Complexity: O(n)
// Space Complexity: O(2n)
vector<int> iterative_postOrderTraversal_2Stack(node* root){
    vector<int> ans;
    stack<node*> stk1, stk2;
    if(root == NULL)    return ans;

    stk1.push(root);
    while(!stk1.empty()){
        root = stk1.top();
        stk1.pop();
        stk2.push(root);
        if(root -> left != NULL)    stk1.push(root -> left);
        if(root -> right != NULL)    stk1.push(root -> right);
    }
    while(!stk2.empty()){
        ans.push_back(stk2.top() -> data);
        stk2.pop();
    }
  return ans;
}


// ---------------------------------------------------
// enter data : 1 2 4 -1 -1 5 6 -1 -1 7 -1 -1 3 -1 -1
// ----- Displaying Tree ------
//        1
//    2       3
// 4     5
//     6   7
// -------------------------------------------------------
// ******  USING One STACK *************************
// ******** postOrder Traversal: 4 6 7 5 2 3 1 
// Time Complexity: O(2n)
// Space Complexity: O(n)
vector<int> iterative_postOrderTraversal_1Stack(node* root){
    vector<int> ans;
    stack<node*> stk;
    node* current = root;
    node* tempCurrent = root;

    while(current != NULL || !stk.empty()){
        if(current != NULL){
            stk.push(current);
            current = current -> left;
        } else{
            tempCurrent = stk.top() -> right;
            if(tempCurrent == NULL){
                tempCurrent = stk.top();
                stk.pop();
                ans.push_back(tempCurrent -> data);
                
                while(!stk.empty() && tempCurrent == stk.top() -> right){
                    tempCurrent = stk.top();
                    stk.pop();
                    ans.push_back(tempCurrent -> data);
                }
            } 
            else  current = tempCurrent;
        }
    }
  return ans;
} 


int main()
{
    node* root = NULL;
    root = buildTree(root);

    cout<<endl<<"----- Displaying Tree ------"<<endl;
    displayTree(root);

    vector<int> arrPostOrder_2Stack = iterative_postOrderTraversal_2Stack(root);
    cout<<"\nPreOrder Traversal using 2 stack: ";
    for(int i=0;i<arrPostOrder_2Stack.size();i++){
        cout<<arrPostOrder_2Stack[i]<<" ";
    }

    vector<int> arrPostOrder_1Stack = iterative_postOrderTraversal_1Stack(root);
    cout<<"\nPreOrder Traversal using 1 stack: ";
    for(int i=0;i<arrPostOrder_1Stack.size();i++){
        cout<<arrPostOrder_1Stack[i]<<" ";
    }

    return 0;
}

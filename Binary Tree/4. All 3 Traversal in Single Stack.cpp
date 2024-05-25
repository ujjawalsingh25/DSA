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
    cout<<endl;

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
// enter data : 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
// ----- Displaying Tree ------
//               1
//          /        \
//        2            5
//      /   \        /   \
//    3      4     6      7
// -------------------------------------------------------
// Time Complexity: O(4n)      without 3 printing for loop.
// Space Complexity: O(4n)


void allTraversal_in1Stack(node* root){
    vector<int> inOrderArr, preOrderArr, postOrderArr;
    stack < pair<node*,int> > stk;
    if(root == NULL)    return;

    stk.push({root, 1});
    while(!stk.empty()){
        auto iter = stk.top();
        stk.pop();

        //preOrder --- increment 1 to 2 --- push left node
        if(iter.second == 1){
            preOrderArr.push_back(iter.first -> data);
            iter.second++;
            stk.push(iter);            
            if(iter.first -> left != NULL)  stk.push({iter.first -> left, 1});
        }

        // inOrder --- increment 2 to 3 --- push right node
        else if(iter.second == 2){
            inOrderArr.push_back(iter.first -> data);
            iter.second++;
            stk.push(iter);
            if(iter.first -> right != NULL)  stk.push({iter.first -> right, 1});
        }

        //postOrder --- already incremented to 3  --- no node to push
        else{
            postOrderArr.push_back(iter.first -> data);
        }
    }

    // Printing the Traversals
    cout<<"InOrder : ";
    for(int i=0;i<inOrderArr.size();i++){
        cout<<inOrderArr[i]<<" ";
    }
    cout<<"\nPreOrder : ";
    for(int i=0;i<preOrderArr.size();i++){
        cout<<preOrderArr[i]<<" ";
    }
    cout<<"\nPostOrder : ";
    for(int i=0;i<postOrderArr.size();i++){
        cout<<postOrderArr[i]<<" ";
    }
}



int main()
{
    node* root = NULL;
    root = buildTree(root);

    cout<<endl<<"----- Displaying Tree ------"<<endl;
    displayTree(root);


    allTraversal_in1Stack(root);

  return 0;
}
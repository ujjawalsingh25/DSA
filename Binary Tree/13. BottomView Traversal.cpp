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
// enter data : 1 2 4 -1 -1 5 8 -1 -1 9 -1 -1 3 6 -1 -1 7 -1 -1
// ----- Displaying Tree ------                     
//               (1)                  ************************************************************************                                  
//            /       \               ************************************************************************                       
//        (2)         (3)             **    CANNOT USE RECURSSION DIRECTLY                                  **                               
//      /     \      /    \           **      as eg->> suppose 9 have left node also say 10, then 10  will  **    
//    (4)      (5) (6)     (7)        **       visit first and ADD later 6 will visit and overwrite         **                                         
//            /   \                   **      SO TO USE RECURSSION                                          **                                       
//        (8)     (9)                 **           we need iterrate through HEIGHT as well                  **                                       
//    |    |      |     |    |        ************************************************************************                               
//    |    |      |     |    |        ************************************************************************                                               
//    -2   -1     0     1    2          -->>> axisLine         
// BottomView Traversal : 4 8 6 9 7       (5 & 6 have same node axisLine ->>> So Right have more priority)         
// ----------------------------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(n) 
// ----------------------------------------------------------------------------------

vector<int> bottomViewTraversal(node* root){
    map<int, int> mppNodes;             //-->> mpp <vertical(X) , level(Y), Nodes >
    queue<pair<node*, int>> quuNodes;

    quuNodes.push({root, 0});
    while(!quuNodes.empty()){
        auto iter = quuNodes.front();
        quuNodes.pop();
        node* currentNode = iter.first;
        
        int axisLine = iter.second;
        mppNodes[axisLine] = currentNode -> data;    // in axisLine update previous data with new bottom data. eg (-1,0) --> -1 axisLine

        if(currentNode -> left != NULL)     quuNodes.push({currentNode -> left , axisLine - 1});
        if(currentNode -> right != NULL)    quuNodes.push({currentNode -> right ,  axisLine + 1});
    }
    vector<int> arr;
    for(auto iter : mppNodes){
        arr.push_back(iter.second);
    }

  return arr;
}


int main()
{
    node* root = NULL;
    root = buildTree(root);
    cout<<endl<<"----- Displaying Tree ------"<<endl;
    displayTree(root);

    cout<<"TopView Travesal Nodes : "<<endl;
    vector<int> arr = bottomViewTraversal(root);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

  return 0;
}
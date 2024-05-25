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
// 1 2 3 -1 4 -1 5 -1 6 -1 -1 -1 7 8 -1 -1 -1
// enter data : 1 2 3 8 -1 -1 -1 4 -1 9 -1 -1 5 6 -1 -1 7 -1 10 -1 -1
// ----- Displaying Tree ------
//             1                                       
//          /     \                    
//        2        5                 
//       / \      /  \          
//      3   4    6    7   
//     /     \         \
//    8       9        10 
// -------------------------------------------------------
// Time Complexity: O(n)  
// Space Complexity: O(n)

vector<vector<int>> zigzagTraversal(node* root){
    vector<vector<int>> arr;
    queue<node*> nodeQuu;
    int flag_leftToRight = 1;
    if(root == NULL)  return arr;

    nodeQuu.push(root);
    while(!nodeQuu.empty()){
      int size = nodeQuu.size();
      vector<int> row(size);

      for(int i=0;i<size;i++){
        node* currentNode = nodeQuu.front();
        nodeQuu.pop();

        int index = (flag_leftToRight) ? i : (size-1-i);
        row[index] = currentNode -> data;
        if(currentNode -> left)  nodeQuu.push(currentNode -> left);
        if(currentNode -> right)  nodeQuu.push(currentNode -> right);
      }

      flag_leftToRight = !flag_leftToRight;
      arr.push_back(row);
    }
 return arr;
}


int main()
{
  node* root = NULL;
  root = buildTree(root);
  cout<<endl<<"----- Displaying Tree ------"<<endl;
  displayTree(root);

  cout<<endl<<"----- ZigZag Traversal Displaying Tree ------"<<endl;
  vector<vector<int>> arr = zigzagTraversal(root);
  for(int i=0;i<arr.size();i++){
    for(int j=0;j<arr[i].size();j++){
      cout<<arr[i][j]<<" ";
    } cout<<endl;
  }

  return 0;
}
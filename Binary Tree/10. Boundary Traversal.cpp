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

// ----------------------------------------------------------------------------------
// 1 2 3 -1 4 5 -1 -1 6 -1 -1 12 -1 -1 11 -1 10 9 7 -1 -1 8 -1 -1 -1
// enter data : 1 2 3 -1 4 5 -1 -1 6 -1 -1 -1 11 -1 10 9 7 -1 -1 8 -1 -1 -1
// ----- Displaying Tree ------
//            1                          ||          1                                          
//          /   \                        ||        /   \                       
//        2      11                      ||      2      11                    
//       /         \                     ||     / \       \             
//      3          10                    ||    3  12       10      
//       \         /                     ||     \         /       
//        4       9                      ||      4       9        
//       / \     / \                     ||     / \     / \       
//      5   6   7   8                    ||    5   6   7   8        
// Travesal : 1 2 3 4 5 6 7 8 9 10 11    ||  1 2 3 4 5 6 12 7 8 9 10 11 
// ----------------------------------------------------------------------------------
// Time Complexity: O(n) -->> O(n) + O(leftHeight_ofTree) + O(rightHeight_ofTree) 
// Space Complexity: O(n)
// ----------------------------------------------------------------------------------

bool isLeaf(node* root){
    if(root -> left == NULL && root -> right == NULL)   return true;
    else return false;
}
void addLeftBoundary(node* root, vector<int> &arr){
    node* currentNode = root -> left;
    while(currentNode){
        if(!isLeaf(currentNode))    arr.push_back(currentNode -> data);
        if(currentNode -> left)     currentNode = currentNode -> left;
        else    currentNode = currentNode -> right;
    }
}
void addRightBoundary(node* root, vector<int> &arr){
    vector<int> tempArr;
    node* currentNode = root -> right;
    while(currentNode){
        if(!isLeaf(currentNode))    tempArr.push_back(currentNode -> data);
        if(currentNode -> right)     currentNode = currentNode -> right;
        else    currentNode = currentNode -> left;
    }
    for(int i=tempArr.size()-1; i>=0; i--){             // push the tempArr data to arr from back to achieve anticlock wise boundary
        arr.push_back(tempArr[i]);
    }
}
void addLeafNodes(node* root, vector<int> &arr){
    if(isLeaf(root)){
        arr.push_back(root -> data);
        return;
    }
    if(root -> left)    addLeafNodes(root -> left, arr);
    if(root -> right)   addLeafNodes(root -> right, arr);
}


vector<int> boundaryTraversal(node* root){
    vector<int> arr ;
    if(root == NULL)    return arr;                     // if root -> empty return empty arr.
    if(!isLeaf(root))   arr.push_back(root -> data);
    addLeftBoundary(root, arr);
    addLeafNodes(root, arr);    
    addRightBoundary(root, arr);

  return arr;
}


int main()
{
    node* root = NULL;
    root = buildTree(root);
    cout<<endl<<"----- Displaying Tree ------"<<endl;
    displayTree(root);

    cout<<endl<<"Boundary Travesal Nodes : ";
    vector<int> arr = boundaryTraversal(root);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

  return 0;
}
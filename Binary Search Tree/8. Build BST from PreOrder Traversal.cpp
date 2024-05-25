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
// Size : 6
// Enter Arary : 8 5 1 7 10 12
// ----- Displaying Tree ------    
//          8
//        /   \        
//       5     10     
//      / \     \        
//     1   7    12     
// --------------------------------------------------------------------------------------------------------------------
// Time Complexity: O(3n) worst case  (eg for 5 it first check left then right then up -->> O(3n))
// Time Complexity: ->> approx O(n)
// Space Complexity: O(1) 
// ----------------------------------------------------------------------------------

node* buildTree_UsingPreOrder(vector<int> &arr, int &i, int upperBound){
    if(i == arr.size() || arr[i] > upperBound)  return NULL;
    node* root = new node(arr[i]);
    i++;
    root -> left = buildTree_UsingPreOrder(arr, i, root -> data);
    root -> right = buildTree_UsingPreOrder(arr, i, upperBound);
  return root;  
}

node* BST_from_PreOrder(vector<int> &arr){
  int i = 0;
  return buildTree_UsingPreOrder(arr, i, INT_MAX);
}

int main()
{
    int n, data;
    vector<int> arr;
    cout<<"Size : ";
    cin>>n;
    cout<<"Enter Arary : ";
    for(int i=0;i<n;i++){
      cin>> data;
      arr.emplace_back(data);
    }
    node* tree = BST_from_PreOrder(arr);
    cout<<endl<<"----- Displaying Tree ------"<<endl;
    displayTree(tree);

  return 0;
}
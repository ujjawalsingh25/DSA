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
// enter data : 10 4 3 1 -1 2 -1 -1 -1 8 6 5 -1 -1 7 -1 -1 9 -1 -1 13 11 -1 -1 15 -1 -1
// ----- Displaying Tree ------                     
//                     10            
//                /          \        
//              4             13      
//           /     \         /    \    
//          3        8      11    15   
//         /        /  \         
//        1        6   9       
//         \     /  \            
//          2   5    7           
// Enter node1 value : 5
// Enter node2 value : 9
// Lowest Common Ancestor (5,9) : 8
// --------------------------------------------------------------------------------------------------------------------
//  Since in BST nodes data are already sorted so check for nodes where node1 and node2 are not lying on same side    |
//  LCA(5,9) ==>> 8 , starts from 10 since (5,9 < 10) so move left to 4                                               |
//  now (5,9 > 4) so move right now here AT (8) BOTH 5 and 9 SPLITS and not on same side so (8) is the ans            |  
//  For (1,2) , 1 is the node where both 1 and 2 are not on same side                                                 |
// --------------------------------------------------------------------------------------------------------------------
// Time Complexity: O(height of tree)
// Space Complexity: O(1) 
// ----------------------------------------------------------------------------------

int lowestCommonAncestor(node* root, int node1, int node2){
    if(root == NULL)  return -1;
    int currentNodeVal = root -> data;

    if(currentNodeVal < node1 && currentNodeVal < node2)   return lowestCommonAncestor(root -> right, node1, node2);   
    if(currentNodeVal > node1 && currentNodeVal > node2)   return lowestCommonAncestor(root -> left, node1, node2);   
  
  return root -> data;  
}


int main()
{
    int node1, node2;
    node* root = NULL;
    root = buildTree(root);
    cout<<endl<<"----- Displaying Tree ------"<<endl;
    displayTree(root);

    cout<<"-------------------"<<endl;
    cout<<"Enter node1 value : ";
    cin>>node1;
    cout<<"Enter node2 value : ";
    cin>>node2;

    int lca  = lowestCommonAncestor(root, node1, node2);
    cout<<"Lowest Common Ancestor ("<<node1<<","<<node2<<") : "<<lca<<endl;

  return 0;
}
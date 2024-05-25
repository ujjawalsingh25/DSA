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
// enter data : -10 9 -1 -1 20 15 -1 -1 7 -1 -1
// ----- Displaying Tree ------
//          -10
//          /  \
//         9    20
//            /   \
//          15     7                    Ans -->> 42.
// -------------------------------------------------------
// Time Complexity: O(n)  
// Space Complexity: O(n)

int maxPathSum(node* root, int &maxSum){
    if(root == NULL)    return 0;

    int leftSum = max(0 , maxPathSum(root -> left, maxSum));        // 0 to avoid negative values
    int rightSum = max(0 , maxPathSum(root -> right, maxSum));
    
    int currentNodeSum =  root -> data + leftSum + rightSum; 
    maxSum = max(maxSum, currentNodeSum);

  return root -> data + max(leftSum , rightSum);  
}

int maximumPathSum(node* root){
    int maxSum = INT_MIN;
    maxPathSum(root, maxSum);
  return maxSum;
}

// ****************************************************************************************************
// maxSum passed by referrence because pass by value doesn't correctly update maxSum across different recursive calls because it passes maxSum by value, resulting in the maximum sum not being properly updated and returned.

// int maxPathSum(node* root, int maxSum){....
// }                                                        //  CODE DO NOT WORK PROPERLY                
// int maximumPathSum(node* root){                          //      AS PASSED BY VALUE
//     int maxSum = maxPathSum(root, INT_MIN);            //    NEED TO PASS BY REFERRENCE
//   return maxSum;
// }
// ****************************************************************************************************


int main()
{
    node* root = NULL;
    root = buildTree(root);

    cout<<endl<<"----- Displaying Tree ------"<<endl;
    displayTree(root);

    int maxPathSum = maximumPathSum(root);
    cout<<"Maximum Path Sum : "<<maxPathSum<<endl;

  return 0;
}
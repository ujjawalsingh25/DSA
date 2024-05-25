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
// enter data : 1 2 -1 -1 3 4 5 -1 -1 -1 6 -1 -1
// ----- Displaying Tree ------
//            1
//          /   \
//         2     3
//             /   \
//           4      6
//          /  
//         5
// -------------------------------------------------------
// Time Complexity: O(n)   
// Space Complexity: O(n)

int maximumDepth_usingStack(node* root){
    int height = 0;
    stack < pair<node*,int> > stk;
    if(root == NULL)    return 0; 
    
    stk.push({root, 1});
    while(!stk.empty()){
        auto iter = stk.top();
        stk.pop();
        node* currentNode = iter.first;
        int currentHeight = iter.second;

        if(currentNode -> left != NULL)     stk.push({currentNode -> left, currentHeight + 1});
        if(currentNode -> right != NULL)    stk.push({currentNode -> right, currentHeight + 1});

        height = max(height, currentHeight);
    }
    
  return height;
}


int maximumDepth_recursive(node* root){
    if(root == NULL)    return 0;

    int leftCount = maximumDepth_recursive(root -> left);
    int rightCount = maximumDepth_recursive(root -> right);
    
    int ans = 1 + max(leftCount, rightCount);
    return ans;
}


int maximumDepth_levelOrder(node* root){
    queue<node*> quu;
    quu.push(root);
    quu.push(NULL);         // seperator in order to seperate parent and child in levels and count increment
    int count=1;

    while(!quu.empty()){
        node* temp = quu.front();
        quu.pop();

        if(temp == NULL){           // Last level completed line_Break for next level
            // cout<<endl;
            if(!quu.empty()){
                quu.push(NULL);         // Seperator for further nodes and count increment
                count++;
            }  
        }
        else{           
            // cout<<temp->data<<" ";
            if(temp-> left) quu.push(temp -> left);
            if(temp-> right) quu.push(temp -> right);
        }
    }    
    return count;
}



int main()
{
    node* root = NULL;
    root = buildTree(root);

    cout<<endl<<"----- Displaying Tree ------"<<endl;
    displayTree(root);


    int height = maximumDepth_usingStack(root);
    cout<<"Maximum Depth iterative through Stack : "<<height<<endl;

    int ans1 = maximumDepth_recursive(root);
    cout<<"Maximum Depth through Recursion : "<<ans1<<endl;

    int ans2 = maximumDepth_levelOrder(root);
    cout<<"Maximum Depth through Level-Order-Traversal : "<<ans2<<endl;

  return 0;
}
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
// enter data : 6 3 2 -1 -1 4 -1 -1 8 7 -1 -1 -1 
// ----- Displaying Tree ------                     
//           6                                     6                      
//        /     \                               /     \          
//       3        8                            3        8    
//     /  \      /        ----------->>      /  \      /    
//    2    4    7        After Insertion    2    4    7      
//                                                \ 
//                                  inserted -->> (5) 
// ----------------------------------------------------------------------------------
// Time Complexity: O(log 2n)
// Space Complexity: 
// ----------------------------------------------------------------------------------

node* insertNodeBST(node* root, int num){
    if(root == NULL)    return new node(num);
    node* currentNode = root;
    while(true){
        if(currentNode -> data <= num){
            if(currentNode -> right != NULL)    currentNode = currentNode -> right;     // keep moving right till num >= curr->data
            else {
                currentNode -> right = new node(num);       // if reached last so need to insert the node
                break;
            }
        } else {
            if(currentNode -> left != NULL)     currentNode = currentNode -> left;    // keep moving left till num < curr->data         
            else {
                currentNode -> left = new node(num);        // if reached last so need to insert the node
                break;
            }
        }
    }
  return root;  
}

int main()
{
    int num;
    node* root = NULL;
    root = buildTree(root);
    cout<<endl<<"----- Displaying Tree ------"<<endl;
    displayTree(root);

    cout<<"-------------------"<<endl;
    cout<<"Enter node value to insert : ";
    cin>>num;
    node* inserted = insertNodeBST(root, num);
    cout<<endl<<"----- After Insertion Tree ------"<<endl;
    displayTree(inserted);

  return 0;
}
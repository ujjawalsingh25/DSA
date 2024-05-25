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
// 1 2 3 -1 4 5 -1 -1 6 -1 -1 12 -1 -1 11 -1 10 9 7 -1 -1 8 -1 -1 -1
// enter data : 1 2 4 -1 5 -1 6 -1 -1 10 -1 -1 3 9 -1 -1 10 -1 -1
// ----- Displaying Tree ------
//                    1 (0,0)                                          Vertical Travesal Nodes :         
//                  /      \                                                  4    
//          (-1,1) 2        3 (1,1)                                           2 5      
//             /     \    /    \                                              1 9 10 6            
//     (-2,2) 4     10   9     10 (1,2)          10 & 9 both -->> (0,2)       3 
//             \      (0,2)                                                   10
//         (-1,3) 5                                                                                 
//                \                                                                                 
//             (0,4) 6                                                                  
// ----------------------------------------------------------------------------------
// Time Complexity: O(n)log(n)
// Space Complexity: O(n) + O(n)
// ----------------------------------------------------------------------------------

vector<vector<int>> verticalTraversal(node* root){
    map<int, map<int, multiset<int>>> mppNodes;             //-->> mpp <vertical(X) , level(Y), Nodes >
    queue<pair<node*, pair<int, int>>> quuNodesCoordinates;

    quuNodesCoordinates.push({root, {0,0}});
    while(!quuNodesCoordinates.empty()){
        auto iter = quuNodesCoordinates.front();
        quuNodesCoordinates.pop();
        node* currentNode = iter.first;
        int x = iter.second.first;
        int y = iter.second.second;

        mppNodes[x][y].insert(currentNode -> data);
        if(currentNode -> left) {
            quuNodesCoordinates.push({currentNode -> left , {x-1, y+1}});
        }
        if(currentNode -> right) {
            quuNodesCoordinates.push({currentNode -> right , {x+1, y+1}});
        }
    }
    vector<vector<int>> arr;
    for(auto outerIter : mppNodes){
        vector<int> col;
        for(auto innerIter : outerIter.second){
            col.insert(col.end(), innerIter.second.begin(), innerIter.second.end());
        }
        arr.push_back(col);
    }

  return arr;
}


int main()
{
    node* root = NULL;
    root = buildTree(root);
    cout<<endl<<"----- Displaying Tree ------"<<endl;
    displayTree(root);

    cout<<"Vertical Travesal Nodes : "<<endl;
    vector<vector<int>> arr = verticalTraversal(root);
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }

  return 0;
}
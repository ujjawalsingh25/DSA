#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Children Size : 5
// Greedy Children : 1 5 3 3 4
// Cookies Size : 6
// Cookies : 4 2 1 2 1 3
// ----------------------------------------------
// Maximum Number of Children assigned Cookies : 3
//        1 3 3 4 5  | 1 1 2 2 3 4
//      { (1->1) , (3->3) , (3->4) }
// ----------------------------------------------

// _______________________________________________________________________________________
// Time Complexity : O(n*log(n) + m*log(m) + m)       -->> O(m) for iterating + Two sort (n*log(n) + m*log(m))
// Space Complexity : O(1) 
// --------------------------------------------------------------
int maxChildrenAssignCookies(vector<int> &children, vector<int> &cookies, int n, int m){
    int childrenIter = 0, cookiesIter = 0;           
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());

    while(childrenIter < n && cookiesIter < m){
        if(children[childrenIter] <= cookies[cookiesIter])   childrenIter = childrenIter+1;
        cookiesIter = cookiesIter+1;
    }
    return childrenIter;
}
// _______________________________________________________________________________________

int main()
{
    int n, m, data;
    vector<int> children, cookies;

    cout<<"Children Size : ";
    cin>>n;
    cout<<"Greedy Children : ";
    for(int i=0;i<n;i++){
        cin>>data;
        children.push_back(data);
    }

    cout<<"Cookies Size : ";
    cin>>m;
    cout<<"Cookies : ";
    for(int j=0;j<m;j++){
        cin>>data;
        cookies.push_back(data);
    }

    int maxChild = maxChildrenAssignCookies(children, cookies, n, m);
    cout<<"Maximum Number of Children Assigned Cookies : "<<maxChild<<endl;

    return 0;
}
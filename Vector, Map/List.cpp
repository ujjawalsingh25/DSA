#include<iostream>
#include<list>
using namespace std;

void display(list<int> &lst){

    list<int> :: iterator iter;
    for(iter=lst.begin(); iter!=lst.end(); iter++){
        cout<<*iter<<" ";
    }
    cout<<endl;
}

int main()
{
    int a,n;
    cin>>n;
    list<int> l1;
    for(int i=0;i<n;i++){
        cin>>a;
        l1.push_back(a);
    }
    display(l1);

    cout<<"---- POP_BACK, POP_FRONT, REMOVE -----"<<endl;
    l1.pop_back();
    display(l1);
    l1.pop_front();
    display(l1);
    l1.remove(3);     // All '3' elements in the list will be removed
    display(l1);

    cout<<"----Values to list using iterator---"<<endl;
    list<int> l2(5);
    list<int> :: iterator iter;
    iter = l2.begin();
    *iter = 12;
    iter++;
    *iter = 13;
    iter++;
    display(l2);

    cout<<"---- SORT, MERGE ---"<<endl;
    l1.sort();
    list<int> l3;
    l1.swap(l2);          // Swapped l2 list will be swapped to l1.        
    display(l1);
    l1.merge(l2);          // Both list l1 and l2 will be merged.
    display(l1);
    l1.reverse();          // Merged list will be reverse.
    display(l1);

    return 0;
}
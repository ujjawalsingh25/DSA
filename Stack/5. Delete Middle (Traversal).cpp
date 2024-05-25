#include<iostream>
#include<stack>
using namespace std;


void display(stack<int> &stk){
    stack<int> temp = stk;      // Since stk will pe poped so need to store.
    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}


void delete_Middle(stack<int> &st, int count, int size){   // size need to be here to get real size as in every recursion it will change.
    if(count == size/2){
        st.pop();
        return;
    }
    int storeNUM = st.top();

    st.pop();
    delete_Middle(st, count+1, size);
    st.push(storeNUM);
}

int main()
{
    stack <int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    display(st);
    
    delete_Middle(st, 0, st.size());

    cout<<"-------"<<endl;
    display(st);
    
    return 0;
}
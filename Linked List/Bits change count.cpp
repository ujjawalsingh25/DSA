#include<iostream>
#include<bitset>
using namespace std;
int main()
{
    int n, m ,arr2[8], arr1[8], answer=0;
    cin>>n>>m;
    bitset<8> num1(n);
    bitset<8> num2(m);
 

    for(int i=0;i<8;i++){
        arr1[7-i] = num1[i];
    }
    for(int i=0;i<8;i++){
        arr2[7-i] = num2[i];
    }
    for(int i=0;i<8;i++){
        if(arr1[i] != arr2[i]) answer++;
    }
    cout<<answer<<endl;

    return 0;
}

int main()
{
    int n, m ,arr2[8], arr1[8], answer=0;
    cin>>n>>m;
    bitset<8> num1(n);
    bitset<8> num2(m);
     for(int i=0;i<8;i++){
        if(num1[i] != num2[i]) answer++;
    }
    cout<<answer<<endl;

    return 0;
}
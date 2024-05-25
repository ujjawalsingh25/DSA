
#include<iostream>
#include<cmath>
using namespace std;


int exponent(int mid, int n){
    int ans = 1;
    while (n>0){
        if(n%2 != 0){
        ans = ans*mid;
        n=n-1;
        }
        else{

            mid = mid*mid;
            n = n/2;
        }
    }
    return ans;
}

int main(){
    float m,n,ans;
    cin>>m>>n;
    ans = ceil(m/n);
    cout<<ans;

return 0;
}

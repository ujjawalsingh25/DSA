#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// Size: 4
// Petrol: 4 6 7 4
// Distance: 6 5 3 5
// Car should start from index to reach all destination: 1

int startPoint_petrolDistance(vector<int> &petrol, vector<int> &distance){
    int start = 0;
    int balance = 0;
    int deficit = 0;

    for(int i=0; i<petrol.size(); i++){
        balance = balance + petrol[i] - distance[i];
        if(balance < 0){
            deficit += balance;
            start = i+1;
            balance = 0;
        }
    }
    if(deficit + balance >= 0)  return start;
    else    return -1;
}


int main()
{
    int n, p, d;
    vector<int> petrol, distance;
    cout<<"Size: ";
    cin>>n;
    cout<<"Petrol: ";
    for(int i=0;i<n;i++){
        cin>>p;
        petrol.emplace_back(p);
    }
    cout<<"Distance: ";
    for(int i=0;i<n;i++){
        cin>>d;
        distance.emplace_back(d);
    }

    int ans = startPoint_petrolDistance(petrol, distance);
    cout<<"Car should start from index to reach all destination: "<<ans<<endl;

  return 0;  
}
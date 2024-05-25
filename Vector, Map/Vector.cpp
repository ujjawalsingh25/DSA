// Vector
// Array that is Dynamic in nature which can change the size if any index added or removed.

#include<iostream>
#include<string>
#include<vector>
using namespace std;

template<class T>
void display(vector<T> &v){
  for (int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }  
    cout<<endl;
}

int main()
{   
    int a,n;
    vector<int> v1;
    cout<<"Size : ";
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a;
        v1.push_back(a);
    }
    
    v1.emplace_back(55);
    v1.emplace_back(58);
    display(v1);
    v1.pop_back();
    display(v1);
    v1.pop_back();
    display(v1);

    vector<int> :: iterator iter = v1.begin();
    cout<<"Iterator : "<<*(iter)<<" "<<*(iter+1)<<endl;                                  //   [1 2 3 4 5]  ^
    // vector<int> :: iterator iter = v1.end();            // It will place after end of data. (Here) -->   |
    // vector<int> :: iterator iter = v1.rbegin();          // It will begin from last index. 


    v1.insert(iter+2,3,25);                     //(Pointer, Copy, Value)   -->>  // On 2 (iter=0/begin +2) insert 3 copy of 55 .
    display(v1);

    cout<<"---- Vectors"<<endl;
    vector <int> vect1(2);
    vector <string> vect2(5);
    vector <string> vect3(vect2);
    vector <char> vect4(5);
    vector <int> vect5(3,5);
    vector < pair< int, int> > vect6;

    vect1.push_back(6);
    vect1.push_back(7);
    vect1.push_back(8);
    display(vect1);

    vect2.push_back("Om");
    vect2.push_back("5");
    display(vect2);

    display(vect3);         // Empty since no input (Made of vector 2)

    vect4.push_back('5');
    vect4.push_back('U');
    display(vect4);
    
    display(vect5);

    vect6.push_back( {3,5} );
    vect6.emplace_back(25,52 );
    

 return 0;
}
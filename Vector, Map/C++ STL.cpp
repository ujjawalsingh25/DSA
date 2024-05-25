// C++ STL

#include<bits/stdc++.h>
using namespace std;

int main()
{

    // ------------- Pair
    cout<<"------Single Pair"<<endl;;
    pair <int, int> p1 = {3, 5};
    cout<<p1.first<<" "<<p1.second<<endl;
    
    cout<<"------Nested Pair"<<endl;;
    pair <int, pair<int, int> > p2 = {3, {5,25} };
    cout<<p2.first<<" "<<p2.second.first<<" "<<p2.second.second<<endl;
    
    cout<<"------ Array of Pair"<<endl;;
    pair <int, int> arr[] = { {1,2}, {3,4}, {5,6} };
    cout<<arr[0].first<<" "<<arr[1].second<<" "<<arr[2].second<<endl;


    // ------------ Vectors
    vector<int> :: iterator iter = v1.begin();
    cout<<"Iterator : "<<*(iter)<<" "<<*(iter+1)<<endl;                                  //   [1 2 3 4 5]  ^
    vector<int> :: iterator iter = v1.end();            // It will place after end of data. (Here) -->   |
    vector<int> :: iterator iter = v1.rbegin();          // It will begin from last index. 
    
    //For Loop
    for(vector<int> :: iterator iter = v.begin(); iter != v.end(); iter++){
        cout<<*(iter)<<" ";
    }
    for(auto iter = v.begin(); iter != v.end(); iter++){
        cout<<*(iter)<<" ";
    }
    for(auto iter : v){
        cout<<*(iter)<<" ";
    }

    // Erase/ Delete
    v.erase(v.begin() + 1);
    v.erase(v.begin()+1 , v.begin()+5 );         // Erase from [start, to end] --> from 1 to 5 will erase.
    v.clear();                                  // Erase the entire vector.

    // Swap
    v1.swap(v2);        // v1 and v2 data will be swapped.
    
    // Insert
    v.insert(v.begin(), 100);              // --> [100]
    v.insert(v.begin()+1, 2, 20);          // --> [100, 20, 20]
    v.insert(iter+2,3,25);   

    // ------------ Set
        // Sorted and Unique
    // ------------ Multi Set
        // Sorted 
    // ------------ Unordered Set
        // Unique 
   

    // ---------------- MAP
    //  Stores as Map < key, value >
    map <int, int> mp;          // --> map <key, value> mp; where key is unique for value identification.
    map <int , pair<int, int> >mp;
    map <pair<int, int>, int >mp;
    
    // Storing value
    mp[1] = 2;                      // --> (1, 2)       in container
    mp.emplace( {3, 4} );          //  -->  (3, 4)      in container
    mp.insert( {5, 6} );          //   -->  (5, 6)      in container
                             // So in container --> [ (1,2) , (3,4) , (5,6) ].
    cout<<map[1];                  // it will print 2 as FOR KEY '1' THE VALUE IS '2'. 

    auto iter = mp.find(3);         // It will find the value in key '3'
    cout<<*(iter).second;            //  and print '4'.


    // Loop of above container
    for(auto iter : mp){
        cout<<iter.first<<" "<<iter.second<<endl;       // It will first print (1 2) then iter increment
    }                                                    // and print (3 4) iter again inc and print (5 6).   

    // ---------------- Multi MAP
            // Sorted
    // ---------------- Unordered MAP        
            // Unique


    // -------------- Sort
    sort(a, a+n);           // --> sort (start, end);    
    sort (a+2, a+5)         // sort from 2 to 5 index.

    sort(a, a+n, greater<int>)      // Due to 'greater<int>' the data sort in descending order.    

    // sort on comparator (Own Way)
    // -- Sort it according to second element
    // -- if second element is same then sort it according to first element but descending.
    sort(a, a+n, comp);
    bool comp(pair <int , int> p1, pair<int, int>p2){
        if(p1.second < p2.second) return true;
        if(p1.second > p2.second) return false;
        if(p1.first > p2.first) return true;
        return false;
    }

    }

  return 0;
}
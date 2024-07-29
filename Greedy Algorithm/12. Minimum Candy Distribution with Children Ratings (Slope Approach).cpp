#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Constraints 
//  1. Each child -> at least one candy
//  2. Children with higher rating has candy > than neighbour
// -------------------------------------------------------------------------------
//  Size: 13
//  Array: 0 2 4 3 2 1 1 3 5 6 4 0 0
//  Minimum Candy Distribution with Children Ratings based on Constraints: 27
// -----------------------------------------------------------------
//         Ratings  :   0  2  4  3  2  1  1  3  5  6  4  0  0    
//                    -----------------------------------------
//       LeftToRight:   1  2  3  1  1  1  1  2  3  4  1  1  1     
//       RightToLeft:   1  1  4  3  2  1  1  1  1  3  2  1  1
//                    -----------------------------------------
//  max(Left, Right):   1  2  4  3  2  1  1  2  3  4  2  1  1    -->>  TotalCandy = 27
// _____________________________________________________________________________________________
// Time Complexity :  O(3*n)
// Space Complexity:  O(2*n) 
// -----------------------------------------------------
int minCandyDistribution_withRatings(vector<int> &ratings, int n){
    int totalCandy = 0;
    int leftToRight[n], rightToLeft[n]; 
    leftToRight[0] = 1, rightToLeft[n-1] = 1;
    for(int i=1; i<n; i++) {
        if(ratings[i] > ratings[i-1]) 
            leftToRight[i] = leftToRight[i-1] + 1;
        else 
            leftToRight[i] = 1;
    }
    for(int i=n-2; i>=0; i--) {
        if(ratings[i] > ratings[i+1])
            rightToLeft[i] = rightToLeft[i+1] + 1;
        else
            rightToLeft[i] = 1;
    } 
    for(int i=0; i<n; i++) {
        totalCandy = totalCandy + max(leftToRight[i], rightToLeft[i]);
    }
    return totalCandy;
}
// _____________________________________________________________________________________________


// _____________________________________________________________________________________________
// Time Complexity :  O(3*n)
// Space Complexity:  O(n) 
// -----------------------------------------------------
int minCandyDistribution_withRatingsOPTM(vector<int> &ratings, int n){
    int leftToRight[n]; 
    leftToRight[0] = 1;
    for(int i=1; i<n; i++) {
        if(ratings[i] > ratings[i-1]) 
            leftToRight[i] = leftToRight[i-1] + 1;
        else 
            leftToRight[i] = 1;
    }

    int current = 1, totalCandy = leftToRight[n-1];
    for(int i=n-2; i>=0; i--) {
        if(ratings[i] > ratings[i+1]) {
            current++;
        }
        else {
            current = 1;
        }
        totalCandy = totalCandy + max(leftToRight[i], current);
    }        
    return totalCandy;
}
// _____________________________________________________________________________________________


//  Size: 13
//  Array: 0 2 4 7 6 5 4 3 2 1 1 1 2 3 4 2 1 1 1 
//  Minimum Candy Distribution with Children Ratings based on Constraints: 50
// -----------------------------------------------------------------
//
//              (7) -> [4(peak) + { (6(down) + 1)- 4(peak)) ]     
//             /  \  
//        (3) /    \ (1)
//           /      \   
//      (2) /        \ (2)                   
//         /          \                             
//    (1) /            \ (3)                    (4) ->  max[ 4(peak), 3(upcomingDown) ]                                                     
//                      \                      /  \                                   
//                       \ (4)            (3) /    \ (1)                                              
//                        \                  /      \                              
//                         \ (5)        (2) /        \___  ___  ___                                                                            
//                          \___  ____  ___/          (2)  (1)  (1)                             
//                           (6)  (1)   (1)
//
// --------------------------------------------------------------------------------------------

// ______________________________  Slope Approach   _________________________________________
// Time Complexity :  O(n)
// Space Complexity:  O(1) 
// -----------------------------------------------------
int candyDistribution_withRatings_SlopeApproach(vector<int> &ratings, int n) {
    int totalCandy = 1, i = 1;
    while(i < n) {
        if(ratings[i] == ratings[i-1]) {
            totalCandy++;
            i++;
            continue;
        }
        int peak = 1;
        while(i < n && ratings[i] > ratings[i-1]) {
            peak++;
            totalCandy += peak;
            i++;
        }
        int down = 1;
        while(i < n && ratings[i] < ratings[i-1]) {
            totalCandy += down;
            down++;
            i++;
        }
        if(down > peak) 
            totalCandy += down-peak;
    }
    return totalCandy;
}
// _____________________________________________________________________________________________


int main() 
{
    int n, data;
    vector<int> ratings; 
    cout<<"Size: ";
    cin>>n;
    cout<<"Array: ";
    for(int i=0;i<n;i++) {
        cin>>data;
        ratings.push_back(data);
    }

    int minCandyREQ = minCandyDistribution_withRatings(ratings, n);
    cout<<"Minimum Candy Distribution with Children Ratings based on Constraints: "<<minCandyREQ<<endl;

    int minCandyReqOPTM = minCandyDistribution_withRatingsOPTM(ratings, n);
    cout<<"Minimum Candy Distribution with Children Ratings based on Constraints: "<<minCandyReqOPTM<<endl;

    int minCandyREQ_slope = candyDistribution_withRatings_SlopeApproach(ratings, n);
    cout<<"Minimum Candy Distribution with Children Ratings based on Constraints (Slope Approach): "<<minCandyREQ_slope<<endl;

    return 0;
}
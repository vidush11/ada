//
//  main.cpp
//  2d_knapsack
//
//  Created by Vidush Jindal on 07/04/25.
//


#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <map>
#include <string>

#define pb push_back
#define p pair<int,int>
#define tu tuple<int,int,int>
#define ll long long
using namespace std;

int main(int argc, const char * argv[]) {
    int n,v,w,W;
    cin>>n;
    cin>>W;
    vector<p> items;
    for (int i=0; i<n; i++){
        cin>>v>>w;
        items.pb({v,w});
    }

    vector<vector<int>>  dp(n+1,vector<int>(W+1,0)) ;
    
    for (int i=1; i<=n; i++){
        for (int w=1; w<=W; w++){
            if (w>=items[i-1].second){
                dp[i][w]=dp[i-1][w-items[i-1].second]+items[i-1].first;
            }
            dp[i][w]=max(dp[i][w], dp[i-1][w]);
        }
    }
        
    cout<<dp[n][W]<<endl;
    
}
//
//5
//11
//1 1
//6 2
//18 5
//22 6
//28 7

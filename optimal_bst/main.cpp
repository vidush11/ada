//
//  main.cpp
//  optimal_bst
//
//  Created by Vidush Jindal on 21/04/25.
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

int main(){
    int n;
    float x;
    cin>>n;
    vector<float> probs;
    for (int i=0; i<n; i++){
        cin>>x;
        probs.pb(x);
    }
    
    vector<vector<float>> dp(n,vector<float>(n,0));
    
    for (int i=0; i<n; i++){ // i represent the diagonal I am working on
        for (int r=0; r<n-i; r++){ //r represents the row of first index in [x,y]
            if (i==0) dp[r][r+i]=probs[r];
            else{
                for (int k=r; k<=r+i; k++) dp[r][r+i]+=probs[k];
                float mini=dp[r+1][r+i];
                for (int k=r; k<=r+i; k++){
                    mini=min(mini,((k!=r) ? dp[r][k-1] :0)+ ((k!=r+i) ? dp[k+1][r+i] : 0)); // If k==r then dp[r]r-1] would be 0, if k==r+i then dp[r+i+1][r+i] would be 0
                }
                dp[r][r+i]+=mini;
            }
        }
    }
    
    cout<<dp[0][n-1]<<endl;
}


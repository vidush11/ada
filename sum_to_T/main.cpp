//
//  main.cpp
//  sum_to_T
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
    int n,x,T;
    cin>>n;
    cin>>T;
    vector<int> numbers;
    for (int i=0; i<n; i++){
        cin>>x;
        numbers.pb(x);
    }

    vector<vector<int>>  dp(n+1,vector<int>(T+1,0)) ;
    
    for (int i=0; i<=n; i++){
        dp[i][0]=1;
    }
    for (int t=1; t<=T; t++){
        dp[0][t]=0;
    }
    
    for (int i=1; i<=n; i++){
        for (int t=1; t<=T; t++){
            dp[i][t]=dp[i-1][t];
            if (numbers[i-1]<=t){
                dp[i][t]=dp[i][t]||dp[i-1][t-numbers[i-1]];
            }
        }
    }
        
    cout<<dp[n][T]<<endl;
    
}

//
//  main.cpp
//  max_assigns_within_dead(O(n^2))
//
//  Created by Vidush Jindal on 04/04/25.
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

int n,a,b;
vector<p> assigns;



int main(int argc, const char * argv[]) {
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>a>>b; //deadline and length inclusive dead
        assigns.pb({a,b});
    }
    
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,INT_MAX));
    sort(assigns.begin(), assigns.end());
    if (assigns[0].second<=assigns[0].first) dp[1][1]=assigns[0].second;
    for (int i=0; i<=n; i++){
        dp[i][0]=0;
    }
    for (int j=1; j<=n; j++){
        for (int k=1; k<=n; k++){
            
            if (dp[j-1][k-1]+assigns[j-1].second<=assigns[j-1].first) dp[j][k]=dp[j-1][k-1]+assigns[j-1].second;
            dp[j][k]=min(dp[j][k], dp[j-1][k]);
            cout<<j<<' '<<k<<' '<<dp[j][k]<<endl;
        }
    }
    int maxy=0;
    for (int i=1; i<=n; i++){
        if (dp[n][i]!=INT_MAX) maxy=i;
    }
    cout<<maxy<<endl;
    
}

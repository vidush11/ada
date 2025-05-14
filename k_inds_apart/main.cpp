//
//  main.cpp
//  k_inds_apart
//
//  Created by Vidush Jindal on 08/04/25.
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
    int n,x,k;
    cin>>n>>k;
    
    vector<int> numbers;
    for (int i=0; i<n; i++){
        cin>>x;
        numbers.pb(x);
    }
    vector<int> dp(n,0);
    dp[0]=numbers[0];
    for (int i=1; i<n; i++){
        dp[i]=numbers[i];
        if (i-(k+1)>=0) dp[i]+=dp[i-(k+1)];
        dp[i]=max(dp[i], dp[i-1]);
    }
    cout<<dp[n-1]<<endl;
}

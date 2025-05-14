//
//  main.cpp
//  lcs
//
//  Created by Vidush Jindal on 25/03/25.
//


#include <iostream>
#include <queue>
#define pq priority_queue
#define pb push_back
#define p pair<int,int>
using namespace std;

int main(int argc, const char * argv[]) {
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    int l1=s1.size();
    int l2=s2.size();
    vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));
    for (int i=1; i<=l1; i++){
        for (int j=1; j<=l2; j++){
            int ans=0;
            if (s1[i-1]==s2[j-1]) ans++;
            dp[i][j]=max(ans+dp[i-1][j-1], dp[i][j-1]);
            dp[i][j]=max(dp[i][j], dp[i-1][j]);
        }
    }
//    for (int i=0; i<=l1; i++){
//        for (int j=0; j<=l2; j++){
//            cout<<dp[i][j]<<' ';
//        }
//        cout<<endl;
//    }
    return dp[l1][l2];
}



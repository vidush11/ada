//
//  main.cpp
//  max_loot
//
//  Created by Vidush Jindal on 18/03/25.
//

#include <iostream>

#define pb push_back
using namespace std;

void solve(vector<int> & nums, vector<int>& dp){
    int n=nums.size();
    if (n==1) {dp[0]=nums[0]; return;}
    dp[0]=nums[0];
    dp[1]=nums[1];
    dp[1]=max(dp[0],dp[1]);
    for (int i=2; i<n; i++){
        dp[i]=nums[i]+dp[i-2];
        dp[i]=max(dp[i], dp[i-1]);
    }
}
int main(int argc, const char * argv[]) {
    int n,x;
    cin>>n;
    vector<int> nums;
    for (int i=0; i<n; i++){
        cin>>x;
        nums.pb(x);
    }
    vector<int> dp(n,0);
    vector<int> sel(n,0);
    
    solve(nums, dp);
    for (int i=n-1; i>=0; i--){
        if (i!=0){
            if (dp[i]!=dp[i-1]) {sel[i]=1;i--;}
        }
        else{
            if (!sel[1]) sel[0]=1;
        }
    }
    
    if (sel[0]!=1 || sel[n-1]!=1) cout<<dp[n-1];
    else{
        vector<int> dp1(n-1,0);
        vector<int> dp2(n-1,0);
        
        vector<int> nums1=nums;
        vector<int> nums2=nums;
        nums1.erase(nums1.begin());
        nums2.pop_back();
        solve(nums1, dp1);
        solve(nums2, dp2);
        
        cout<<max(dp1[n-2], dp2[n-2]);
    }
}

//
//  main.cpp
//  lis
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
    vector<int> nums{10,9,2,5,3,7,101,18};
    int s=nums.size();
    vector<int> dp(s,0);
    vector<p> snums;
    for (int i=0; i<s; i++){
        snums.pb({nums[i],i});
    }
    sort(snums.begin(), snums.end());
    
    for (int i=0; i<s; i++){
        dp[i]=1;
        int maxy=0;
        int s=0;
        int e=s-1;
        int mid=0;
        while (true){
            cout<<i<<' '<<s<<' '<<e<<endl;
            mid=(s+e)/2;
            if (snums[mid].first<nums[i]) s=mid+1;
            else if (snums[mid].first>nums[i]) e=mid-1;
            else break;
        }
        for (int i_=0; i_<mid; i_++){
            int ind=snums[i_].second;
            if (ind<i && dp[ind]>maxy) maxy=dp[ind];
        }
        dp[i]+=maxy;
    }
    int maxy=dp[0];
    for (int i=0; i<s; i++){
        if (dp[i]>maxy) maxy=dp[i];
    }
    cout<< maxy<<endl;
    
}

//
//  main.cpp
//  max_non_overlapping_weight
//
//  Created by Vidush Jindal on 26/03/25.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>

#define pb push_back
#define p pair<int,int>
#define tu tuple<int,int,int>

using namespace std;

struct Comp{
    bool operator()(const tu &a, const tu &b) const{
        return (get<0>(a) >get<0>(b));
    }
};

int max(int &a, int &b){
    if (a>=b) return a;
    else return b;
}
int main(int argc, const char * argv[]) {
    int n,a,b,w;
    cin>>n;
    vector<tu> jobs;
    for (int i=0; i<n; i++){
        cin>>a>>b>>w; //job starts at a and ends at b (not inclusive)
        jobs.pb({a,b,w});
    }
    sort(jobs.begin(), jobs.end(), Comp());
    vector<int> dp(n,0);
    
    dp[0]=get<2>(jobs[0]);
    for (int i=1; i<n; i++){
        dp[i]=get<2>(jobs[i]);
        //binary search to find larget i_ such that it doesn't intersect with ith interval
        int dead=get<1>(jobs[i]);
        int start=0;
        int end=i-1;
        int mid;
        while (true){
            if (start>=end) break;
            mid=(start+end)/2;
            if (get<0>(jobs[mid]) < dead) end=mid-1;
            else start=mid;
        }
        if (get<0>(jobs[start]) >= dead) dp[i]+=dp[start];
        dp[i]=max(dp[i], dp[i-1]);
    }
    
    cout<<dp[n-1]<<endl;
}

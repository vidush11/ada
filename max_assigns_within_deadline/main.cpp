//
//  main.cpp
//  max_assigns_within_deadline
//
//  Created by Vidush Jindal on 31/03/25.
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
int max_deadline=0;
vector<p> assigns;



int main(int argc, const char * argv[]) {

    cin>>n;
    for (int i=0; i<n; i++){
        cin>>a>>b; //deadline and length inclusive dead
        assigns.pb({a,b});
        if (a>max_deadline) max_deadline=a;
    }
    sort(assigns.begin(), assigns.end());
//    vector<int> dp(n,0);
    vector<int> dp(max_deadline+1,0);
    for (int i=0; i<n; i++){
        int dead=assigns[i].first;
        int length=assigns[i].second;
//        cout<<dead<<' '<<length<<endl;
        vector<p> changes;
        for (int t=0; t<=max_deadline; t++){
            if (t+length>dead) break;
            if (t==0 or dp[t]) {
                changes.pb({t+length, dp[t]+1});
            }
        }
        for (p pa:changes){
            dp[pa.first]=max(dp[pa.first], pa.second);
        }
    }
    int answer=0;
    for (int t=0; t<=max_deadline; t++){
        if (dp[t]>answer) answer=dp[t];
    }
    cout<<answer<<endl;
}

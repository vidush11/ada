//
//  main.cpp
//  greedy_max_reward_deadline
//
//  Created by Vidush Jindal on 24/03/25.
//

#include <iostream>
#include <queue>
#define pq priority_queue
#define pb push_back
using namespace std;

int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    while (t--){
        int n,x,y;
        cin>>n;
        
        pq<int> rewards;
        vector<vector<int>> deadlines(2*100000+1, vector<int>());
        
        int max_dead=0;
        for (int i=0; i<n; i++){
            cin>>x>>y;
            deadlines[x].pb(y);
            if (x>max_dead) max_dead=x;
        }
        
        long long maxy=0;
        for (int i=max_dead; i>=1; i--){
            for (int r:deadlines[i]){
                rewards.push(r);
            }
            if (rewards.size()){
                maxy+=rewards.top();
                rewards.pop();
            }
        }
        
        cout<<maxy<<endl;
    }
}

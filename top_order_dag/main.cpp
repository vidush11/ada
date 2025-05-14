//
//  main.cpp
//  top_order_dag
//
//  Created by Vidush Jindal on 24/02/25.
//

#include <iostream>
#include <vector>
#define pb push_back

using namespace std;

int main(int argc, const char * argv[]) {
    int n=5;
    vector<vector<int>> adjlist;
    adjlist.push_back({1,2,3});
    adjlist.push_back({2});
    adjlist.push_back({});
    adjlist.push_back({4});
    adjlist.push_back({});
    
    vector<vector<int>> revgraph(n,vector<int>());
    vector<int> outdegrees(n,0);
    
    vector<int> sinks;
    for (int i=0; i<n; i++){
        outdegrees[i]+=adjlist[i].size();
        if (outdegrees[i]==0) sinks.pb(i);
        for (int j: adjlist[i]){
            revgraph[j].pb(i);
        }
    }
    int k=n;
    vector<int>top_sort(n,-1);
    
    while (sinks.size()){
        int x=sinks.back();
        sinks.pop_back();
        top_sort[x]=k;
        k--;
        for (int i: revgraph[x]){
            outdegrees[i]--;
            if (outdegrees[i]==0) sinks.push_back(i);
        }
    }
    
    for (int i=0; i<n; i++){
        cout<<top_sort[i]<<endl;
    }
}

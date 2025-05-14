//
//  main.cpp
//  bellman_ford
//
//  Created by Vidush Jindal on 22/04/25.
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
    int n,m,a,b,c,s;
    cin>>n>>m>>s;
    vector<vector<p>> graph;
    
    for (int i=0; i<m; i++){
        cin>>a>>b>>c;
        a--;
        b--;
        graph[a].pb({b,c});
    }
    
    s--;
    //bellman-ford
    vector<int> dists;
    for (int i=0; i<n; i++) dists.pb(INT_MAX);
    
    dists[s]=0;
    
    for (int e=1; e<n; e++){
        for (int i=0; i<n; i++){
            for (p pa:graph[i]){
                if (dists[i]==INT_MAX) break;
                int new_dist=dists[i]+pa.second;
                dists[pa.first]=min(dists[pa.first],new_dist);
            }
        }
        
    }
    
    vector<int> new_dists=dists;
    for (int i=0; i<n; i++){
        for (p pa:graph[i]){
            if (dists[i]==INT_MAX) break;
            int new_dist=dists[i]+pa.second;
            new_dists[pa.first]=min(new_dists[pa.first],new_dist);
        }
    }
    bool flag=false;
    for (int i=0; i<n; i++){
        if (new_dists[i]<dists[i]) flag=true;
    }
    
    if (flag) cout<<"Negative Cycle Detected\n";
    else{
        for (int i=0; i<n; i++){
            cout<<dists[i]<<' ';
        }
        cout<<endl;
    }
}

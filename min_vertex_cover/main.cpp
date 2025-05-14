//
//  main.cpp
//  min_vertex_cover
//
//  Created by Vidush Jindal on 22/02/25.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>

#define p pair<int,int>
#define nl endl
const int nmax = 2e5 + 5;
using namespace std;

struct compare
{
    bool operator()(const pair<int,int> & a, const pair<int,int> & b)
    {
        return a.second>b.second;
    }
};

vector<vector<int>> dp0(nmax, vector<int>());
vector<vector<int>> dp1(nmax, vector<int>());

vector<int> work(nmax,0);

//dfs traversal for a graph, you don't need a visited array
void dfs(vector<vector<int>> &graph, int s_){ //s-start, p-parent, graph- adj list of graph
    stack<p> st;
    st.push({s_,-1});
    while (!st.empty()){
        p pa=st.top();
        int s=pa.first;
        int par=pa.second;
        
        if (work[s]){
            for (int v: graph[s]){
                if (v==par) continue;
                //dp0[s]+=dp1[v]
                dp0[s].insert(dp0[s].end(), dp1[v].begin(), dp1[v].end());
                //dp1[s]+=min(dp0[v], dp1[v])
                if (dp0[v].size()<dp1[v].size()){
                    dp1[s].insert(dp1[s].end(), dp0[v].begin(), dp0[v].end());
                    
                }
                else{
                    dp1[s].insert(dp1[s].end(), dp1[v].begin(), dp1[v].end());
                }
            }
            st.pop();
        }
        else {
            work[s]=1;
            for (int v: graph[s]){
                if (v==par) continue; //traversing in the adj list and skipping if I reach parent
                st.push({v,s});
            }
        }
    }
    
}
int main(int argc, const char * argv[]) {
    int n,u,v;

//    adjlist.push_back({1,2});
//    adjlist.push_back({0});
//    adjlist.push_back({0,3,4,5});
//    adjlist.push_back({2});
//    adjlist.push_back({2});
//    adjlist.push_back({2});
    cin>>n;
    vector<vector<int>> adjlist(n,vector<int>());
    for (int i=0; i<n-1; i++){
        cin>>u>>v;
        adjlist[u-1].push_back(v-1);
        adjlist[v-1].push_back(u-1);
    }
    for (int i=0; i<n; i++){
        dp1[i].push_back(i);
    }
    
    dfs(adjlist, 0);
        
    cout<<"Size of min vertex cover: ";
    cout<<min(dp0[0].size(), dp1[0].size())<<nl;
    
}

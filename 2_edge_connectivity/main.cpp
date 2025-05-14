//
//  main.cpp
//  2_edge_connectivity
//
//  Created by Vidush Jindal on 24/02/25.
//

#include <iostream>
#include <vector>
#define p pair<int,int>
#include <set>
#include <stack>
#include <tuple>
#define pb push_back
#define tu tuple<int,int,int>
using namespace std;

set<p> bridge_edges;

void dfs(int s, vector<vector<int>> &adjlist){
    int n=adjlist.size();
    stack<tu> st;
    st.push({s,s,-1});
    int k=0;
    vector<int> ancestor(n,-1);
    ancestor[0]=0;
    while (!st.empty()){
        tu pa=st.top();
        st.pop();
        int u,p_,x;
        tie(u,p_,x)=pa;
        if (x==-1){ //unvisited
            st.push({u,p_,1});
            ancestor[u]=k++;
            for (int v :adjlist[u]){
                if (v==p_) continue;
                else if (ancestor[v]!=-1){
                    ancestor[u]=min(ancestor[u],ancestor[v]);
                }
                else{
                    st.push({v,u,-1});
                }
           
            }
        }
        else{
            for (int v :adjlist[u]){
                if (v==p_) continue;
                else{
                    ancestor[u]=min(ancestor[u],ancestor[v]);
                }
           
            }
            if (ancestor[u]>ancestor[p_]){
                bridge_edges.insert({u,p_});
                bridge_edges.insert({p_,u});
            }
        }
        
    }
    
}
int main(){
    vector<vector<int>> adjlist; //undirected graph
    adjlist.pb({1,2});
    adjlist.pb({0,3});
    adjlist.pb({0,3});
    adjlist.pb({1,2,4});
    adjlist.pb({3,5,6});
    adjlist.pb({4,6});
    adjlist.pb({4,5});
    
    dfs(0,adjlist);
    
}


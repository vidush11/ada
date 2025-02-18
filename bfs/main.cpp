//
//  main.cpp
//  bfs
//
//  Created by Vidush Jindal on 17/02/25.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> &graph, vector<int>& dist){
    int s=0;
    queue<int> q;
    q.push(s);
    vector<int> visit(graph.size(),0);
    visit[s]=1;
    dist[s]=0;
    while (! q.empty()){
        int u=q.front();
        q.pop();
        for (int v:graph[u]){
            if (visit[v]) continue;
            visit[v]=1;
            dist[v]=dist[u]+1;
            q.push(v);
        }
    }
    
}
int main(int argc, const char * argv[]) {
    vector<vector<int>> graph(6,vector<int>());
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(3);
    graph[2].push_back(4);
    graph[3].push_back(4);
    graph[3].push_back(5);
    graph[4].push_back(5);
    
    //add other side edges too for undirected graph
    
    vector<int> dist(6,-1);
    bfs(graph, dist);
    
    for (int i=0; i<dist.size(); i++){
        cout<<i<<"-> "<<dist[i]<<endl;
    }
}

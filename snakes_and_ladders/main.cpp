//
//  main.cpp
//  snakes_and_ladders
//
//  Created by Vidush Jindal on 22/02/25.
//

#include <iostream>
#include <vector>

using namespace std;

int bfs(vector<vector<int>> &graph, int n, vector<int> ladder){
    int s=1;
    queue<int> q;
    if (ladder[s]) s=ladder[s];
    q.push(s);
    vector<int> visit(graph.size(),0);
    visit[s]=1;
    
    while (!q.empty()){
        int u=q.front();
        q.pop();
    
        if (ladder[u]){
            int v=ladder[u];
            if (visit[v]) continue;
            visit[v]=visit[u]+1;
            q.push(v);
            if (v==n) return visit[v]-1;
        }
        for (int v:graph[u]){
            if (visit[v]!=0) continue;
            if (ladder[v]) v=ladder[v];
            if (visit[v]) continue;
            visit[v]=visit[u]+1;
            q.push(v);
            if (v==n) return visit[v]-1;
        }
        
    }
    
    return -1;
    
}

int main(){
    vector<vector<int>> board;
    board.push_back({-1,-1,-1,-1,-1,-1});
    board.push_back({-1,-1,-1,-1,-1,-1});
    board.push_back({-1,-1,-1,-1,-1,-1});
    board.push_back({-1,35,-1,-1,13,-1});
    board.push_back({-1,-1,-1,-1,-1,-1});
    board.push_back({-1,15,-1,-1,-1,-1});
    
    int n=board.size();
    vector<vector<int>> ajlist(n*n+1, vector<int>());
    vector<int> ladder(n*n+1,0);
    vector<int> snake(n*n+1,0);
    int x=0;
    for (int i=n-1; i>=0; i--){
        if ((n-1-i)%2==0){
            for (int j=0; j<n; j++){
                x++;
                
                
                for (int i_=0 ;i_<6; i_++){
                    if (x+i_+1>n*n) break;
                    ajlist[x].push_back(x+i_+1);
                }
                if (board[i][j] !=-1){
                    ladder[x]=board[i][j];
                }
            }
        }
        else{
            for (int j=n-1; j>=0; j--){
                x++;
                for (int i_=0 ;i_<6; i_++){
                    if (x+i_+1>n*n) break;
                    ajlist[x].push_back(x+i_+1);
                }
                
                if (board[i][j] !=-1){
                    ladder[x]=board[i][j];
                }
            }
        }
        
    }
    //    for (int i=1; i<=n*n; i++){
    //        for (int j:ajlist[i]){
    //            cout<<j<<' ';
    //        }
    //        cout<<endl;
    //    }
    cout<< bfs(ajlist, n*n, ladder)<<endl;
}




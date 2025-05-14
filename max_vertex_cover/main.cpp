//
//  main.cpp
//  max_vertex_cover
//
//  Created by Vidush Jindal on 23/02/25.
//

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {

    int n,u,v;
    cin>>n;
    vector<vector<int>> adjlist(n,vector<int>());
    for (int i=0; i<n-1; i++){
        cin>>u>>v;
    
        adjlist[u-1].push_back(v-1);
        adjlist[v-1].push_back(u-1);
    }
//    adjlist.push_back({1,2});
//    adjlist.push_back({0});
//    adjlist.push_back({0,3,4,5});
//    adjlist.push_back({2});
//    adjlist.push_back({2});
//    adjlist.push_back({2});
    
    vector<int> degrees(n,0);
    vector<int> min_degrees;
    vector<int> visit(n,0);
    vector<int> selected(n,0);
    
    for (int i=0; i<n; i++){
        degrees[i]+=adjlist[i].size();
        if (degrees[i]==1) {min_degrees.push_back(i); visit[i]=1;}
    }

    while (min_degrees.size()!=0){
        int x=min_degrees.back();
        min_degrees.pop_back();
        if (selected[x]!=0) continue;
        else {selected[x]=1;}
        visit[x]=1;
        int v=-1;
        for (int i: adjlist[x]){
            selected[i]=-1;
            if (visit[i]) continue;
            v=i;
            break;
        }
        if (v==-1) continue; //all work done

        visit[v]=1;
        for (int i:adjlist[v]){
            degrees[i]-=1;
            if (degrees[i]<=1 && visit[i]==0) {min_degrees.push_back(i); visit[i]=1;}
        }
        
    }
    int count=0;
    for (int i=0;i<n; i++ ){
        if (selected[i]==1) count++;
    }
    cout<<n-count<<endl;
    
}

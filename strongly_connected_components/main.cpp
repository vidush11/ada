////
////  main.cpp
////  strongly_connected_components
////
////  Created by Vidush Jindal on 10/02/25.
////
//
//#include <iostream>
//#include <stack>
//
//void dfs(vector<vector<int>>& list, int s){
//    
//}
//
//int main(int argc, const char * argv[]) {
//    vector<vector<int>> adj_list;
//    adj_list.push_back(vector<int>);
//    adj_list.push_back(vector<int>{2});
//    adj_list.push_back(vector<int>{3,6,7});
//    adj_list.push_back(vector<int>{4});
//    adj_list.push_back(vector<int>{3});
//    adj_list.push_back(vector<int>{3,4,6});
//    adj_list.push_back(vector<int>{5});
//    adj_list.push_back(vector<int>{1,6});
//    
//    
//}
vector<vector<int>> dp;
int recur(int node,int temp,vector<vector<int>>& adj,int parent){
    if(dp[node][temp]!=-1){
        return dp[node][temp];
    }
    int ans=0;
    for(auto it:adj[node]){
        if(it!=parent){
            ans+=recur(it,0,adj,node);
        }
    }
    int ans2=0;
    for(auto it:adj[node]){
        if(it!=parent){
            ans2+=recur(it,1,adj,node);
        }
    }
    if(temp==1){
        return dp[node][temp]=1+ans;
    }
    return dp[node][temp]=ans2;
}

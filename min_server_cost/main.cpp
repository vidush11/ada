//
//  main.cpp
//  min_server_cost
//
//  Created by Vidush Jindal on 31/03/25.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <map>

#define pb push_back
#define p pair<int,int>
#define tu tuple<int,int,int>

using namespace std;

int n,x;
vector<int> costs;
map<p, int> memo;

int min(int a, int b){
    if (a<=b) return a;
    return b;
}
int solution(int c, int s){
    if (memo.count({c,s})) return memo[{c,s}];
    
    if (c==n){
        int cost=0;
        cost+=(n-s)*(n-s+1);
        cost/=2;
        memo[{c,s}]=cost;
        return cost;
    }
    int cost=0;
    cost=min(costs[c]+((c-s)*(c-s+1))/2+solution(c+1,c+1), solution(c+1,s));
    memo[{c,s}]=cost;
    return cost;
}

int main(int argc, const char * argv[]) {

    cin>>n;
    costs.pb(0);
    for (int i=0; i<n-1; i++){
        cin>>x;
        costs.pb(x);
    }
    
    cout<<solution(1,1);
}

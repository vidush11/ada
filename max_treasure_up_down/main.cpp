//
//  main.cpp
//  max_treasure_up_down
//
//  Created by Vidush Jindal on 08/04/25.
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
    int n,m,x;
    cin>>n>>m;
    vector<vector<int>> grid;
    for (int i=0; i<n; i++){
        grid.pb(vector<int>());
        for (int j=0; j<m; j++){
            cin>>x;
            grid.pb(x);
        }
    }
    
    
}

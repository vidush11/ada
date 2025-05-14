//
//  main.cpp
//  4_row_max_non_consecutive_sum
//
//  Created by Vidush Jindal on 07/04/25.
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

bool not_adjacent(vector<int> a, vector<int> b){
    bool flag=true;
    for (int i=0; i<a.size(); i++){
        if (count(b.begin(), b.end(), a[i])) flag=false;
    }
    
    return flag;
}
int main(int argc, const char * argv[]) {
    int n,x;
    cin>>n;
    vector<vector<int>> grid;
    for (int i=0; i<4; i++){
        grid.pb(vector<int>());
        for (int j=0; j<n; j++){
            cin>>x;
            grid[i].pb(x);
        }
    }
    
    vector<vector<int>> possibs{{},{0},{1},{2},{3},{0,2},{0,3},{1,3}};
    vector<vector<int>> counter{};
    vector<int> prev;
    vector<int> new_prev;
    for (auto li:possibs){
        int sum=0;
        for (int i:li){
            sum+=grid[i][0];
        }
        prev.pb(sum);
    }
    for (int j=1; j<n; j++){
        for (auto li:possibs){
            int sum=0;
            for (int i:li){
                sum+=grid[i][j];
            }
            int prev_sum=0;
            for (int i=0; i<possibs.size(); i++){
                if (not_adjacent(possibs[i], li)) prev_sum=max(prev_sum, prev[i]);
            }
            
            sum+=prev_sum;
            new_prev.pb(sum);
        }
        prev=new_prev;
        new_prev.clear();
    }
    
    int maxy=0;
    for (int i=0; i<prev.size(); i++){
//        cout<<prev[i]<<endl;
        if (prev[i]>maxy) maxy=prev[i];
    }
    cout<<maxy<<endl;
}

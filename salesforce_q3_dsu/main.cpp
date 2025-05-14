//
//  main.cpp
//  salesforce_q3_dsu
//
//  Created by Vidush Jindal on 15/04/25.
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
    int n,m,q,a,b;
    cin>>n>>m>>q;
    vector<int> parent;
    vector<int> offline;
    
    for (int i=0; i<n; i++){
        parent.pb(i);
        offline.pb(0);
    }
    for (int i=0; i<m; i++){
        cin>>a>>b;
        a--;b--;
        int a_=a;
        int b_=b;
        
        int x=0;
        int y=0;
        
        while (parent[a_]!=a_){
            a_=parent[a_];
            x++;
        }
        
        while (parent[b_]!=b_){
            b_=parent[b_];
            y++;
        }
        if (x<=y){
            parent[a_]=b_;
        }
        else{
            parent[b_]=a_;
        }
        
    }
    
    for (int i=0; i<q; i++){
        cin>>a>>b;
        b--;
        if (a==1){
            if (!offline[b]) {cout<<b+1<<endl; continue;}
            int b_=b;
            while (b_!=parent[b_]){
                b_=parent[b_];
            }
            bool flag=false;
            for (int i=0; i<n; i++){
                if (offline[i]) continue;
                int i_=i;
                while (i_!=parent[i_]){
                    i_=parent[i_];
                }
                if (i_==b_) {cout<<i+1<<endl;flag=true; break; }
            }
            if (!flag) cout<<-1<<endl;
        }
        
        else{
            offline[b]=1;
        }
    }
    
}

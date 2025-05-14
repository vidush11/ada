//
//  main.cpp
//  disjoin_set_union
//
//  Created by Vidush Jindal on 05/04/25.
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

int main() {
    int n,q,a,b,c;
    cin>>n>>q;
    vector<int> parent;
    for (int i=0; i<n; i++){
        parent.pb(i);
    }
    
    for (int i=0; i<q; i++){
        cin>>a>>b>>c;
      
        if (a==0){
            int pb=b;
            int pc=c;
            int lb=0;
            int lc=0;
            while (pb!=parent[pb]){
                pb=parent[pb];
                lb++;
            }
            while (pc!=parent[pc]){
                pc=parent[pc];
                lc++;
            }
            if (lb<lc){
                parent[pb]=pc;
            }
            else{
                parent[pc]=pb;
            }
        }
        else{
//            for (int i=0; i<n; i++){
//                cout<<parent[i]<<' ';
//            }
            int pb=b;
            int pc=c;
            while (pb!=parent[pb]){
                pb=parent[pb];
            }
            while (pc!=parent[pc]){
                pc=parent[pc];
            }
            if (pb==pc) cout<<"1\n";
            else cout<<"0\n";
        }
        
    }
}

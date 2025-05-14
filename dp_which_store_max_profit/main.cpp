//
//  main.cpp
//  dp_which_store_max_profit
//
//  Created by Vidush Jindal on 25/03/25.
//


#include <iostream>
#include <queue>
#define pq priority_queue
#define pb push_back
#define p pair<int,int>
using namespace std;

int main(int argc, const char * argv[]) {
    int t,n,x,c;
    cin>>t;
    while (t--){
        cin>>n>>c;
        vector<int> storeA;
        vector<int> storeB;
        for (int i=0; i<n; i++){
            cin>>x;
            storeA.pb(x);
        }
        for (int i=0; i<n; i++){
            cin>>x;
            storeB.pb(x);
        }
        vector<int> dpA(n,0);
        vector<int> dpB(n,0);
        
        dpA[0]=storeA[0];
        dpB[0]=storeB[0];
        for (int i=1; i<n; i++){
            dpA[i]=max(dpA[i-1], dpB[i-1]-c)+storeA[i];
            dpB[i]=max(dpB[i-1], dpA[i-1]-c)+storeB[i];
        }
        
        cout<<max(dpA[n-1], dpB[n-1])<<endl;
    }
}

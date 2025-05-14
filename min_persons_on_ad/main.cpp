//
//  main.cpp
//  min_persons_on_ad
//
//  Created by Vidush Jindal on 25/03/25.
//

#include <iostream>
#include <queue>
#define pq priority_queue
#define pb push_back
#define p pair<int,int>
using namespace std;

bool comp(p& a, p& b){
    if (a.second==b.second) return a.first<b.first;
    else return (a.second<b.second);
    
}
int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    while (t--){
        int n,x,y;
        cin>>n;
        
        vector<p> arrivals;
       
        for (int i=0; i<n; i++){
            cin>>x>>y;
            arrivals.pb({x,y});
        }
        
        sort(arrivals.begin(), arrivals.end());
        vector<p> departure=arrivals;
        sort(departure.begin(), departure.end(), comp);
        
        int i=0;
        int curra=INT_MAX;
        int currd=-1;
        vector<p> selected;
        for (p pa: departure){
            
            int thisd=pa.second;
            if (currd>pa.first){
                continue;
            }
            while (i<n){
                if (arrivals[i].first>=thisd) break;
                if (arrivals[i].second>currd) {curra=arrivals[i].first;currd=arrivals[i].second;}
                i++;
            }
//            cout<<pa.first<<' '<<pa.second<<endl;
            selected.pb({curra, currd});
        }
        
        cout<<selected.size()<<endl;
        for (p pa:selected){
            cout<<pa.first<<' '<<pa.second<<endl;
        }
       
    }
}


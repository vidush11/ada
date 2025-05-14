//
//  main.cpp
//  max_stacking_height
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
    int t,n,h,w,l;
    cin>>t;
    while (t--){
        cin>>n;
        int boxes[1000][1000];
        for (int i=0; i<1000; i++){
            for (int j=0; j<1000; j++){
                boxes[i][j]=0;
            }
        }
        for (int i=0; i<n; i++){
            cin>>h>>w>>l;
            boxes[w][l]=h;
        }
        int dp[1001][1001];
        for (int i=1; i<1001; i++){
            for (int j=1; j<1001; j++){
                dp[i][j]+=dp[i-1]+dp[j-1]+boxes[i][j];
            }
        }
        cout<<dp[1000][1000]<<endl;
    }
}


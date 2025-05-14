//
//  main.cpp
//  inversions
//
//  Created by Vidush Jindal on 14/05/25.
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

ll answer;

void merge(vector<int>&arr, int a_, int b_, int c_, int d_){
    int a=a_;
    int b=b_;
    int c=c_;
    int d=d_;
    vector<int> new_arr;
    while (a<=b && c<=d){
        if (arr[a]<=arr[c]){
            new_arr.pb(arr[a]);
            a++;
        }
        else{
            new_arr.pb(arr[c]);
            c++;
            answer+=(b-a)+1;
        }
    }
    while (a<=b){
        new_arr.pb(arr[a]);
        a++;
    }
    while (c<=d){
        new_arr.pb(arr[c]);
        c++;
    }
    
    for (int i=a_; i<=d_; i++){
        arr[i]=new_arr[i-a_];
    }
}

void recurse(vector<int>&arr, int a, int b){
    if (b-a==0) return;
    else if (b-a==1){
        if (arr[a]>arr[b]){
            arr[a]^=arr[b];
            arr[b]^=arr[a];
            arr[a]^=arr[b];
            answer++;
        }
    }
    else{
        recurse(arr, a, a+(b-a)/2 );
        recurse(arr,a+(b-a)/2+1,b);
        merge(arr,a, a+(b-a)/2, a+(b-a)/2+1,b);
       
    }
}

ll inversions(vector<int> arr){
    int n=arr.size();
    answer=0;
    recurse(arr,0,n-1);
    return answer;
}
int main(int argc, const char * argv[]) {
    vector<int> arr{5,4,3,2,1};
    cout<<inversions(arr);
}

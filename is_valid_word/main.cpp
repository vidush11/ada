//
//  main.cpp
//  is_valid_word
//
//  Created by Vidush Jindal on 31/03/25.
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

map<string, bool> dictionary;
map<string, bool> memo;

ll total=0;
bool check_good(string s){
    total++;
    if (memo.count(s)) return memo[s];
    if (dictionary.count(s)) {
        memo[s]=dictionary[s];
        return memo[s];
    }
    if (s.size()==1){
        memo[s]=0;
        return memo[s];
    }
    
    bool flag=false;
    for (int i=0; i<s.size()-1; i++){
        flag=flag || (check_good(s.substr(0,i+1)) && check_good(s.substr(i+1,s.size()-(i+1))) );
    }
    memo[s]=flag;
    return flag;
}
int main(int argc, const char * argv[]) {
    dictionary["it"]=1;
    dictionary["was"]=1;
    dictionary["the"]=1;
    dictionary["best"]=1;
    dictionary["of"]=1;
    dictionary["times"]=1;

    memo[""]=1;
    
    string s="itwasthebesttimesof";
//    for (int i=0; i<100; i++){
//        s.pb('a');
//    }
    int n=s.size();
    
    cout<<check_good(s)<<endl;
    cout<<n<<' '<<total<<endl;
}

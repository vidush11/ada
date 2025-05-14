//
//  main.cpp
//  coin_change
//
//  Created by Vidush Jindal on 18/03/25.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    int money=28;
    vector<int> coins={1,5,10};
    sort(coins.begin(), coins.end());
    
    reverse(coins.begin(), coins.end());
    int answer=0;
    for (int i:coins){
        answer+=money/i;
        money=money%i;
    }
    cout<<answer<<endl;
}

//
//  main.cpp
//  i_th_smallest_element
//
//  Created by Vidush Jindal on 10/02/25.
//

#include <iostream>
#include "quicksort.h"
#include <algorithm>
#include <random>
#include <time.h>

int random(int m){
    static mt19937 x(chrono::steady_clock::now().time_since_epoch().count());
    return x()%m+1;
}

int find_i(vector<int>& array, int i, int s, int e){//returns i'th smallest element's index
    if (i<1 || i>e-s+1) {cout<<"ERROR"<<i<<' '<<s<<' '<<e<<endl;return -1;}
    if (s==e) return s;
    if (e-s+1<=5){ //if size of vector is less than 5 base case
        sort(array.begin()+s, array.begin()+e+1); //in sort add 1 to last index
        return i-1+s; //return the ith smallest number's index
    } //ok
    
    vector<int> medians; //ok
    for (int _=s; _<=e; _+=5){
        int mid=(e-_)/2; //middle element starting from 0
        int x=array[find_i(array,min(3,mid+1),_, min(e,_+4))];
        medians.push_back(x);
    }
    
    int p=find_i(medians,(medians.size()+1)/2, 0,medians.size()-1);
    bool flag=false;
    for (int _=s; _<=e; _++){
        if (array[_]==medians[p]){
            p=_;
            p=quicksort(p, array, s, e);
            flag=true;
            break;
        }
    }
    
    if (not flag) {cout<<"ERROR"; return -1;}
    int curr=p-s+1;
    if (curr==i) return p;
    else if (curr<i){
        return find_i(array, i-curr, p+1, e);
    }
    else {
        return find_i(array, i, s, p-1);
    }
}


int main(int argc, const char * argv[]) {
    int size=10000000;
    vector<int> numbers;
    for (int i=0; i<size; i++){
        numbers.push_back(random(10000));
    }
    clock_t start= clock();

    int k=random(size);
    
    //    vector<int> numbers={9,8,7,3,1,0,19,18,38,40,10,29,39,89,0};
    numbers[find_i(numbers, k, 0, numbers.size()-1)];
    
    clock_t end=clock();
    cout<<double(end - start) / double(CLOCKS_PER_SEC);
}




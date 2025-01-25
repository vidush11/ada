//
//  main.cpp
//  majiority_element
//
//  Created by Vidush Jindal on 24/01/25.
//

#include <iostream>
#define cl(x) count(array, start, end/2, x)
#define cr(x) count(array, end/2+1, end, x)

using namespace std;

int majiority(int n){
    return n/2+1; //number of elements required for majority in an array of size n
}

int count(vector<int> &array, int start, int end, int x){
    int c=0;
    for (int i=start; i<=end; i++) {if (array[i]==x) c++;}
    return c;
    
}
int recursive_majiority(vector<int> &array, int start, int end){

    if (start==end){

        return array[start];
    }

    

    int m1=recursive_majiority(array, start, (start+end)/2);
    int m2=recursive_majiority(array, (start+end)/2+1, end);
    

    if (m1==-1 && m2==-1) return -1;
    if (m1==m2) return m1;
    if (m1!=-1){
        if (cl(m1)+ cr(m1)>=majiority(end-start+1))  return m1;
    }
    if (m2!=-1){
        if (cl(m2)+ cr(m2)>=majiority(end-start+1)) return m2;
    }
    
    return -1;
}

int main(){
    vector<int> arr={1,2,3,4,2,2,2,4,4,5,5,5,5,5,5,5,5,5,5,5};

    cout<< recursive_majiority(arr, 0, arr.size()-1);
}

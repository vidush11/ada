//
//  quicksort.h
//  ada
//
//  Created by Vidush Jindal on 10/02/25.
//

#include <vector>

using namespace std;

void swap(vector<int>&arr, int p, int q){
    int x=arr[p];
    arr[p]=arr[q];
    arr[q]=x;
}

int quicksort(int p, vector<int>&arr, int s, int e){
    if (p<s || p>e) return -1;
    int k=s-1;
    for (int i=s; i<=e; i++){
        if (arr[i]<arr[p]){
            k++;
            if (k==p){
                p=i;
            }
            swap(arr,k,i);
        }
    }
    k++;
    swap(arr, k,p);
    return k;
}

void sort(vector<int>& array, int s, int e){
    int k=quicksort(s,array,s,e);
    if (k==-1) {cout<<"ERROR";return;}
    if (k!=s){
        sort(array,s,k-1);
    }
    if (k!=e){
        sort(array,k+1,e);
    }
}



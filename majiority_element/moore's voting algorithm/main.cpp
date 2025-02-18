//
//  main.cpp
//  moore's voting algorithm
//
//  Created by Vidush Jindal on 26/01/25.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> array{1,2,3,0,0,0,0,0,2,3,1};
    int curr_index=0;
    int count=1;
    for (int i=1; i< array.size(); i++){
        if (array[i]==array[curr_index]) count++;
        else count--;
        if (count<0) {curr_index=i; count=1;}
    }
    
    printf("Majiority Element: %d\n", array[curr_index]);
}

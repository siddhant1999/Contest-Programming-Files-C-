//
//  main.cpp
//  Above the Median
//
//  Created by Siddhant Jain on 2014-10-27.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <set>
#include <map>
using namespace std;
vector<int> heights;
vector<double> sums;
int med, answer = 0;

bool ifmed(int i, int j){
    //if (<#condition#>) {
       // <#statements#>
    //}
    return false;
}

void median(){
    long hsize =heights.size();
    for (int i = 1; i < hsize; i++) {
        for (int j = 0; j < hsize; j++) {
            int end = j + i -1;
            if (ifmed(j, end) == true) {
                answer++;
            }
        }
    }
}

int main(void)
{
    
    int num;
    
    cin >> num >> med;
    int cursum = 0;
    
    while (num--) {
        int temp;
        cin >> temp;
        heights.push_back(temp);
        cursum+= temp;
        sums.push_back(cursum);
    }
    
}


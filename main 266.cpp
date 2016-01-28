//
//  main.cpp
//  LIS
//
//  Created by Siddhant Jain on 2014-07-23.
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

vector<int> nums;
vector<int> cache(1000000, -1);

int maxsum = 0;

int getbest(int k){
    if (k < 0) {
        return 0;
    }
    if (cache[k] != -1) {
        return cache[k];
    }
    vector<int> list;
    for (int i = k-1; i >=0; i--) {
        
        if (nums[i] < nums[k]) {
            list.push_back(1+getbest(i));
        }
    }
    
    if (list.size() > 0) {
        sort(list.begin(), list.end());
        return cache[k] = list[list.size() - 1];
    }
    
    return 0;
}

int main(void)
{
    int n, temp;
    cin >> n;
    
    while (n--) {
        cin >> temp;
        nums.push_back(temp);
    }
    
    for (int m = nums.size()-1; m > 0 ; m--) {
        int var = getbest(m);
        
        if (var > maxsum)
            maxsum = var;
        
    }
    cout << maxsum + 1;
}

// 1 2 5 4 3 6
//
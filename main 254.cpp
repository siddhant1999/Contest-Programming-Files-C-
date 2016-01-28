//
//  main.cpp
//  Hay Bales
//
//  Created by Siddhant Jain on 2014-10-13.
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

int main(void)
{
    vector<int> nums;
    int cases;
    cin >> cases;
    int orig = cases;
    
    while (cases--) {
        int temp;
        cin >> temp;
        
        nums.push_back(temp);
    }
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
        sum += nums[i];
    
    int average = sum / orig;
    
    int ans = 0;
    for (int j = 0; j < nums.size(); j++)
        if (nums[j] > average)
            ans += nums[j] - average;
    
    cout << ans;
}


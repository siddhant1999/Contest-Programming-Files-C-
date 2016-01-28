//
//  main.cpp
//  Maximum Sum
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

int getbest(int k){
    if (k < 0) {
        return 0;
    }
    if (cache[k] != -1) {
        return cache[k];
    }
    int curnum = nums[k] + getbest(k-2); // choice 1: take the k'th number
    
    if (curnum > getbest(k-1)) { // choice 2: do NOT take the k'th number
        return cache[k]=curnum;
    }
    else
        return cache[k]=getbest(k-1);
}

int main(void)
{
    int n, temp;
    cin >> n;
    
    while (n--) {
        cin >> temp;
        nums.push_back(temp);
    }
    
    

    cout << getbest(nums.size() - 1);
}

/*
 Given an array of (positive) integers, find a subset with the maximal sum.
 However, there is the additional restriction that no two numbers in the subset may be adjacent.
 
 For example, for the array

ind=  0 1 2 3 4
nums= 4 5 6 9 10
 
 best(k) = max( nums[k]+best(k-2), best(k-1) )

 
 4 6 10 is valid, while 5 9 10 is invalid since 9 and 10 are next to each other.
 4 6 10 happens to be the optimal sum in this case, so 20 is the answer.
*/
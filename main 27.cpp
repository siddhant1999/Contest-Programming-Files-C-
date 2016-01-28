//
//  main.cpp
//  Candy Lake
//
//  Created by Siddhant Jain on 2014-03-02.
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
vector<long> mountain;
vector<long> branch;
long lake = 0;
long candy;

char recurse() {
    cout << "Hello";
    while (1) {
        if (mountain[mountain.size() - 1] == lake + 1) {
            lake = mountain[mountain.size() - 1];
            mountain.pop_back();
            mountain.pop_back();
        }
        else if (branch.size() > 0 && branch[branch.size() - 1] == lake + 1) {
            lake = branch[branch.size() - 1];
            branch.pop_back();
            branch.pop_back();
        }
        else if (mountain.size() == 0 && branch[branch.size() -1] != lake + 1)
            return 'N';
        else if (lake == candy)
            return 'Y';
    }
    cout << "HELLO";
    return 'J';
}

int main(void)
{
    
    long testcases, cars;
    
    cin >> testcases;
    while (testcases--) {
        cin >> cars;
        candy = cars;
        while (cars--) {
            long temp;
            cin >> temp;
            mountain.push_back(temp);
        }
        cout << recurse();
    }
}
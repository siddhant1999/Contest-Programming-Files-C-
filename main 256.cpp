//
//  main.cpp
//  Acidic
//
//  Created by Siddhant Jain on 2014-10-12.
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

vector<int> states (1001, 0);

int main(void)
{
    int testcases;
    cin >> testcases;
    
    int big = 0;
    int small = 1000000000;
    
    while (testcases--) {
        int temp;
        cin >> temp;
        
        states[temp]++;
        
        for (int i = 1; i <= 1000; i++) {
            max(big, states[i]);
            
            
        }
    }
}

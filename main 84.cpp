//
//  main.cpp
//  Bridge Transport
//
//  Created by Siddhant Jain on 2014-06-13.
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

vector<int> mass;

bool bridge(int index, int capacity){
    if (mass[index] + mass[index - 1] + mass[index - 2] + mass[index - 3] > capacity) {
        return 0;
    }
    return 1;
}

int main(void)
{
    int max;
    cin >> max;
    
    int num;
    cin >> num;
    
    if (num < 4) {
        cout << 0;
        return 0;
    }
    int placeholder = 0;
    while (num--) {
        
        int curin;
        cin >> curin;
        mass.push_back(curin);
        
        //if (bridge(placeholder, max) == 0)
            //break;
        
        placeholder++;
    }
    if (mass.size() > 4)
        cout << mass.size() - 1;
    else
        cout << 0;
    
    return 0;
}
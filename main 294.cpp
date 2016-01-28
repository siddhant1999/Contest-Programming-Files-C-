//
//  main.cpp
//  Bowling
//
//  Created by Siddhant Jain on 1/18/2014.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;

vector<int> pins;

int main(void)
{
    int testcases, numpins, balls, adjac, input, greatest = 0, sum;

    cin >> testcases >> numpins >> balls >> adjac;
    int num = numpins;
    while (num--) {
        cin >> input;
        pins.push_back(input);
    }
    
    for (int i = 0; i < numpins; i++) {
        sum = 0;
        for (int j = 0; j < adjac; j++) {
            sum +=pins[i + j];
        }
        if (sum > greatest)
            greatest = sum;
    }
}
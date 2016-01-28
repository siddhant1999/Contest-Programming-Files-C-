//
//  main.cpp
//  Rolling A Dice
//
//  Created by Siddhant Jain on 1/21/2014.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    int numone, numtwo;
    cin >> numone >> numtwo;
    int sum = 0;
    for (int i = 1; i <= numone && i < 10; i++) {
        for (int j = 1; j <= numtwo && j < 10; j++) {
            if (i + j == 10)
                sum++;
        }
    }
    if (sum == 1) {
        cout << "There is "<< sum <<" way to get the sum 10.";
    }
    cout << "There are " << sum << " ways to get the sum 10.";
}
//
//  main.cpp
//  What is n, Daddy?
//
//  Created by Siddhant Jain on 2/1/2014.
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
    vector<int> number(11);
    int n;
    cin >> n;
    for (int i=0; i <= 5; i++) {
        for (int j=0; j <= 5; j++) {
            number[i+j] += 1;
        }
    }
    if (number[n]%2) {
        number[n] = number[n] / 2 + 1;
    }
    else
        number[n] /= 2;
    
    cout << number[n];
}
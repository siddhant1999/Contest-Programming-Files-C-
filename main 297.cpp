//
//  main.cpp
//  GenerateNum
//
//  Created by Siddhant Jain on 12/22/2013.
//  Copyright (c) 2013 Siddhant Jain. All rights reserved.
//


#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    while (n != 1) {
        if (n%2 != 1) {
            n /= 2;
        cout << n << " ";
        }
        else {
            n = (n * 3) + 1;
            cout << n << " ";
        }
    }
}
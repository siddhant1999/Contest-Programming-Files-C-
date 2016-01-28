//
//  main.cpp
//  RSA
//
//  Created by Siddhant Jain on 1/20/2014.
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
    int small, big, rsa = 0;
    cin >> small >> big;
    
    for (int i = 0; i < (big - small + 1); i++) {
        int num = small + i;
        int div = 0;
        for (int j = 1; j <= num; j++) {
            if ((num%j) == 0) {
                div++;
            }
        }
        if (div == 4) {
            rsa++;
        }
    }
    cout << "The number of RSA numbers between " << small <<" and "<< big << " is "<< rsa;
}
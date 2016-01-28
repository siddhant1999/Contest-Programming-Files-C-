//
//  main.cpp
//  3n+1
//
//  Created by Siddhant Jain on 2014-03-12.
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
    long n;
    cin >> n;
    
    for (int i = 0; i == i; i++) {
        if (n == 1) {
            cout << i;
            return 0;
        }
        if (n%2 == 1) {
            n = 3 * n + 1;
        }
        else n /= 2;
    }
}
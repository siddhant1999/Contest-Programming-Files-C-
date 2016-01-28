//
//  main.cpp
//  COMC
//
//  Created by Siddhant Jain on 2014-11-06.
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
    long double num = 503.0/2014.0;
    cout << num;
    long double done = 0;
    long double first_largest = 0;
    long double sum = 0;
    cout << endl;
    bool count = false;
    for (long double i = 1; i < 50; i++) {
        sum += 1.0/((i*i*i) +(3*i*i) + (2 * i));
        
            //cout << "last " << done << endl;
            cout  << "current number: "<<i << endl;
        cout << "sum " << sum << endl << endl;
        if (sum > num && count != true) {
            done = i;
            first_largest = sum;
            count = true;
        }
    }
    cout << "The answer is: " << done << " since " << first_largest << " is > than " << num;
}


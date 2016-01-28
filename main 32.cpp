//
//  main.cpp
//  Sum
//
//  Created by Siddhant Jain on 2014-03-11.
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
    int n, sum = 0;
    cin >> n;
    int num = n;
    while (num--) {
        sum += n * n;
        n--;
    }
    cout << sum;
}
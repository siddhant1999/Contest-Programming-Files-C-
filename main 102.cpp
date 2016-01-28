//
//  main.cpp
//  Times Table
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
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << n << " X " << i << " = " << i * n << endl;
    }
}
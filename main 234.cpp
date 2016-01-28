//
//  main.cpp
//  Task SKOCIMIS
//
//  Created by Siddhant Jain on 2014-11-08.
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
    int a, b, c;
    cin >> a >> b >> c;
    if (b - a >= c - b) {
        cout << b-a-1;
    }
    else
        cout << c-b-1;
}


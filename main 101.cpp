//
//  main.cpp
//  Multiple
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
    int n, m;
    cin >> n >> m;
    if (n%m == 0) {
        cout << "yes";
    }
    else cout << "no";
}
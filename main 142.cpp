//
//  main.cpp
//  USACO Cow Revised
//
//  Created by Siddhant Jain on 2015-02-24.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
#include <fstream>
#include <set>
#include <map>
#include <ctime>
using namespace std;


int main(void)
{
    freopen("cow.in", "r", stdin);
    freopen("cow.out", "w", stdout);
    
    long long num, c = 0, co = 0, cow = 0;
    cin >> num;
    
    for (long long i = 0; i < num; i++) {
        char temp;
        cin >> temp;
        if (temp == 'C') c++;
        if (temp == 'O') co += c;
        if (temp == 'W') cow += co;
    }
    cout << cow;
}
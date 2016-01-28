//
//  main.cpp
//  Compute
//
//  Created by Siddhant Jain on 2015-02-11.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
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

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;

int main(void)
{
    while (1) {
        double a, b;
        cin >> a >> b;
        double y = log(a)+0.3744;
        y /= b;
        cout << y <<endl;
    }
}


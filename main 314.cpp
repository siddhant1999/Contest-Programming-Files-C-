//
//  main.cpp
//  Sum of Products
//
//  Created by Siddhant Jain on 2/9/2014.
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
using namespace std;

int main(void)
{
    vector<char> vec;
    vec[0] = 'b';
    vec[1] = 'a';
    sort(vec.begin(), vec.end());
    cout << vec[0] << " " << vec[1];
}
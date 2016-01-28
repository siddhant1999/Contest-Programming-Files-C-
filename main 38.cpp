//
//  main.cpp
//  ISBN
//
//  Created by Siddhant Jain on 2014-03-10.
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
    int sum = 91;
    int in;
    cin >> in;
    sum += in;
    cin >> in;
    sum += in * 3;
    cin >> in;
    sum += in;
    
    cout << "The 1-3-sum is "<< sum;
}
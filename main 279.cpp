//
//  main.cpp
//  Fish
//
//  Created by Siddhant Jain on 1/22/2014.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    int in1, in2, in3, in4;
    cin >> in1 >> in2 >> in3 >> in4;
    if (in1 < in2 && in2 < in3 && in3 < in4)
        cout << "Fish Rising";
    else if (in1 > in2 && in2 > in3 && in3 > in4)
        cout << "Fish Diving";
    else if (in1 == in2 && in2 == in3 && in3 == in4)
        cout << "Fish At Constant Depth";
    else
        cout << "No Fish";
}
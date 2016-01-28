//
//  main.cpp
//  Squares
//
//  Created by Siddhant Jain on 1/20/2014.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

int main(void)
{
    double input, hello;
    cin >> input;
    hello = sqrt (input);
    int hel = hello;
    cout << "The largest square has side length " << hel << ".";
}
//
//  main.cpp
//  Cold
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
int mini = 201;
string city;

int main(void)
{
    string temp;
    int num;
    while (temp != "Waterloo") {
        cin >> temp >> num;
        if (num < mini) {
            mini = num;
            city = temp;
        }
    }
    cout << city;
}
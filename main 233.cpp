//
//  main.cpp
//  Task MODULO
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
    bool array[42]= {false};
    int temp;
    int ten = 10;
    int thing = 0;
    while (ten--) {
        cin >> temp;
        int cur = temp%42;
        if (array[cur] == false) {
            array[cur] = true;
            thing++;
        }
    }
    cout << thing;
}


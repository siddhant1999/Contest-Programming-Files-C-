//
//  main.cpp
//  j2
//
//  Created by Siddhant Jain on 2/25/2014.
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
    int num;
    cin >> num;
    int a = 0;
    int b = 0;
    char vote;
    
    while (num--) {
        cin >> vote;
        if (vote == 'A')
            a++;
        if (vote == 'B')
            b++;
    }
    if (a > b)
        cout << 'A';
    if (a < b)
        cout << 'B';
    if (a == b)
        cout << "Tie";
}
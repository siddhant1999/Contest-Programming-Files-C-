//
//  main.cpp
//  Speeding Fines
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
    int limit, speed, result;
    cin >> limit >> speed;
    result = speed - limit;
    if (speed > limit) {
        if (result >= 1 && result <= 20)
            cout << "You are speeding and your fine is $100.";
        if (result >= 21 && result <= 30)
            cout << "You are speeding and your fine is $270.";
        if (result >= 31)
            cout << "You are speeding and your fine is $500.";
    }
    else
        cout << "Congratulations, you are within the speed limit!";
}
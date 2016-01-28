//
//  main.cpp
//  Phone Plans
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
using namespace std;

int A(int day, int eve, int week){
    int cost = 0;
    day -= 100;
    if (day > 0) {
        cost = day * 25;
    }
    cost += eve * 15 + week * 20;
    return cost;
}

int B(int day, int eve, int week){
    int cost = 0;
    day -= 250;
    if (day > 0) {
        cost = day * 45;
    }
    cost += (eve * 35) + (week * 25);
    return cost;
}

int main(void)
{
    int day, eve, week;
    cin >> day >> eve >> week;
    double aaa = A(day, eve, week);
    double bbb =  B(day, eve, week);
    double asum = aaa / 100;
    double bsum = bbb / 100;
    cout << "Plan A costs " << asum << endl;
    cout << "Plan B costs " << bsum << endl;
    
    
    if (A(day, eve, week) < B(day, eve, week))
        cout << "Plan A is cheapest.";
    if (B(day, eve, week) < A(day, eve, week))
        cout << "Plan B is cheapest.";
    if (B(day, eve, week) == A(day, eve, week))
        cout << "Plan A and B are the same price.";
}
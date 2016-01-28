//
//  main.cpp
//  Calorie Counting
//
//  Created by Siddhant Jain on 1/21/2014.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

int calories = 0;

void burgers(int burg){
    if (burg == 1)
        calories += 461;
    if (burg == 2)
        calories += 431;
    if (burg == 3)
        calories += 420;
}

void thirst(int burg){
    if (burg == 1)
        calories += 130;
    if (burg == 2)
        calories += 160;
    if (burg == 3)
        calories += 118;
}

void sides(int burg){
    if (burg == 1)
        calories += 100;
    if (burg == 2)
        calories += 57;
    if (burg == 3)
        calories += 70;
}
void dessert(int burg){
    if (burg == 1)
        calories += 167;
    if (burg == 2)
        calories += 266;
    if (burg == 3)
        calories += 75;
}
int main(void)
{
    int burg, drink, side, dest;
    cin >> burg >> side >> drink >> dest;
    burgers(burg);
    thirst(drink);
    sides(side);
    dessert(dest);
    
    cout << "Your total Calorie count is " << calories;
}









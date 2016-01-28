//
//  main.cpp
//  BMI
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

int main(void)
{
    double weight, height, bmi;
    cin >> weight >> height;
    bmi = weight / (height * height);
    if(bmi > 25)
        cout << "Overweight";
    else
    if (bmi >= 18.5 && bmi <= 25)
        cout << "Normal weight";
    else
    if (bmi < 18.5)
        cout << "Underweight";
}
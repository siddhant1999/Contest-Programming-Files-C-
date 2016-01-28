//
//  main.cpp
//  j1
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
    int ang1, ang2, ang3;
    cin >> ang1 >> ang2 >> ang3;
    
    if ((ang1 + ang2 + ang3) != 180) {
        cout << "Error";
        return 0;
    }
    else if (ang1 == 60 && ang2 == 60 && ang3 == 60){
        cout << "Equilateral";
        return 0;
    }
    else if (ang1 != ang2 && ang1 != ang3 && ang2 != ang3){
        cout << "Scalene";
        return 0;
    }
    else {
        cout << "Isosceles";
        return 0;
    }
}
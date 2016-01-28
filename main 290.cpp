//
//  main.cpp
//  Alien
//
//  Created by Siddhant Jain on 1/19/2014.
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
    int ant, eyes;
    cin >> ant >> eyes;
    
    if (ant >= 3 && eyes <= 4) {
        cout << "TroyMartian" << endl;
    }
    if (eyes >= 2 && ant <= 6) {
        cout << "VladSaturnian" << endl;
    }
    if (eyes <= 3 && ant <= 2) {
        cout << "GraemeMercurian" << endl;
    }
}
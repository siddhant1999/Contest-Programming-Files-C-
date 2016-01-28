//
//  main.cpp
//  Slot Machines
//
//  Created by Siddhant Jain on 2014-07-13.
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
    int money;
    cin >> money;
    
    vector<int> lastwin(3);
    vector<int> reward(3);
    vector<int> point(3);
    
    reward[0] = 30;
    reward[1] = 60;
    reward[2] = 9;
    
    point[0] = 35;
    point[1] = 100;
    point[2] = 10;
    
    for (int i = 0; i < 3; i++) {
        cin >> lastwin[i];
    }
    int numplay = 0;
    for (int i = money; i > 0;) {
        for (int j= 0; j<3; j++) {
            i--;
            
            //cout << "i: " << i<< endl;
            numplay++;
            //cout << "   numplay: " << numplay << endl;
            lastwin[j]++;
            if (lastwin[j] == point[j]) {
                lastwin[j] = 0;
                i += reward[j];
            }
            if (i <= 0)
                break;
        }
    }
    cout << "Martha plays " << numplay << " times before going broke.";
}
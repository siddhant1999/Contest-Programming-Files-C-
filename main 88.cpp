//
//  main.cpp
//  Picture Perfect
//
//  Created by Siddhant Jain on 2014-06-09.
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
    /*float hh = sqrt(48);
    int gg = sqrt(48);
    cout << hh << "    " << gg;*/
    
    while (1) {
        int minperi = 100000000;
        int ar;
        cin >> ar;
        //cout << ar << " ";
        float area = ar;
        if (ar == 0)
            break;
        
        float sqf = sqrt(area);
        int sqi = sqrt(area);
        int besti = 0;
        int bestw = 0;
        if (sqf == sqi) {
            int peri = 4 * sqi;
            cout << "Minimum perimeter is "<< peri <<" with dimensions "<< sqi<< " x " << sqi << endl;
        }
        
        else {
            float i = 1;
            int qoui = 0;
        for (; i < area; i= i+1) {
            float quof = area / i;
            qoui = area / i;
           // cout << "i: " << i << " quof: " << quof << " qoui: " << qoui << endl;
            if (qoui == quof) {
                //cout << "YES" << endl;
                int tempperi = (i + qoui) * 2;
                //cout << "tempperi: " << tempperi << endl;
                if (tempperi < minperi) {
                    minperi = tempperi;
                    besti = i;
                    bestw = qoui;
                    //cout << "minperi: " << minperi << endl;
                }
            }
        }
            cout << "Minimum perimeter is "<< minperi <<" with dimensions "<< besti << " x " << bestw << endl;
        }
    }
}
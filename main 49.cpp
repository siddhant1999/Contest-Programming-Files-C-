//
//  main.cpp
//  Shifts
//
//  Created by Siddhant Jain on 2/23/2014.
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
    string bnoonst, bnoonen;
    char colon;
    int bobsthr, bobstmin, bobenhr, bobenmin;
    int k = 0;
    double bstar, bend;
    
    cin >> bobsthr >> colon >> bobstmin >> bnoonst >> bobenhr >> colon >> bobenmin >> bnoonen;
    
    bstar = bobsthr + bobstmin / 60;
    bend = bobenhr + bobenmin / 60;
    
    int num;
    cin >> num;
    vector<int> sthr(num);
    vector<int> stmin(num);
    vector<int> enhr(num);
    vector<int> enmin(num);
    vector<string> stnoon(num);
    vector<string> ennoon(num);
    vector<double> dstar(num);
    vector<double> dend(num);
    
    while (num--) {
        cin >> sthr[k] >> colon >> stmin[k] >>stnoon[k] >> enhr[k] >> colon >> enmin[k] >> ennoon[k];
        dstar[k] = sthr[k] + stmin[k] / 60;
        dend[k] = enhr[k] + enmin[k] / 60;
        k++;
    }
    
    
}









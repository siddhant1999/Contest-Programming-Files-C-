//
//  main.cpp
//  Candy
//
//  Created by Siddhant Jain on 2014-03-20.
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



/*
 can( N, V ) == can you make a value of V using only the first N candies ?
 totalSum = sum of all candies
 if can(N,V)==true
    one team has V, other team has totalSum-V calories
 */

vector<int> calor;
double smallestdiff = 1000111222312332;
double done = 0;
void diff(vector<char> myvec){
    done++;
    double onesum = 0;
    double twosum = 0;
    
    for (int i = 0; i < myvec.size(); i++) {
        if (myvec[i] == '1')
            onesum += calor[i];
        if (myvec[i] == '2')
            twosum += calor[i];
        
    }
    double differ = onesum - twosum;
    //cout << "*****" << "1: " << onesum <<  " 2: "<< twosum << " "<<differ << endl;
    
    if (differ < 0)
        differ *= -1;
    
    smallestdiff = min(differ, smallestdiff);
}



void seperate(vector<char> whichteam, int index) {
    if (whichteam.size() == calor.size()) {
        diff(whichteam);
        return;
    }
    whichteam.push_back('1');
    seperate(whichteam, index + 1);
    whichteam.pop_back();
    
    whichteam.push_back('2');
    seperate(whichteam, index + 1);
    whichteam.pop_back();
    
}

int main(void)
{
    int cases;
    cin >> cases;
    //time_t start = time(0);
    
    
    while (cases--) {
        int num, cal;
        cin >> num >> cal;
        
        for (int i = 0; i < num; i++)
            calor.push_back(cal);
    }
    vector<char> team;
    
    seperate(team, 0);
    cout << smallestdiff << endl;
    //cout << done << endl;
    //double seconds_since_start = difftime( time(0), start);
    //cout << seconds_since_start;
}


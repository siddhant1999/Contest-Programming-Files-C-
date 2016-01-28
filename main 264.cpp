//
//  main.cpp
//  Bridge Crossing
//
//  Created by Siddhant Jain on 2014-08-01.
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

int people_at_once, num_people, temp;

vector<int> times;
vector<string> names;

int cache[101];
int group[101];

void printname(int n){
    if (n < 0) {
        return;
    }
    int g = group[n];
    int left_side = n-g+1;
    cout <<"N: "<< n << " G: " << g << " Left: " << left_side << endl;
    printname(left_side-1);
    
    for (int i = left_side; i <= n; i++) {
        cout << names[i] << " ";
    }
    cout << endl;
}

int getslowest(int i, int j){
    int curmax = 0;
    
    for (int k = i; k <= j; k++) {
        if (times[k] > curmax) {
            curmax = times[k];
        }
    }
    return curmax;
}

int best(int n){
    if (n < 0)
        return 0;
    
    if (cache[n] != -1) {
        return cache[n];
    }
    
    int curmin = 2147483647;
    int curg = 0;
    for (int g = 1; g <= people_at_once ; g++) {
        int left_side = n-g+1;
        int currentcost = getslowest(left_side, n) + best(left_side - 1);
        
        if (currentcost < curmin){
            curmin = currentcost;
            curg = g;
        }
    }
    group[n] = curg;
    return cache[n] = curmin;
}

int main(void)
{
    
    string curname;
    cin >> people_at_once >> num_people;
    
    int ran = num_people;
    
    for (int q = 0; q <= 100; q++) {
        cache[q] = -1;
    }
    
    while (ran--) {
        cin >> curname;
        names.push_back(curname);
        cin >> temp;
        times.push_back(temp);
    }
    
    cout << "Total Time: "<<best(num_people - 1) << endl;
    printname(num_people-1);
}


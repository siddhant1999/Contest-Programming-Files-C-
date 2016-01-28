//
//  main.cpp
//  USACO 1
//
//  Created by Siddhant Jain on 2014-12-13.
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
vector<pair<int, int> > dests;
//z is being omited
int sum = 0;
int mini = 1000000000;
bool stop = false;
int abs(int x){
    if(x < 0) return -x;
    return x;
}
int omit(int z, int i){
    if(stop == true) return 0;
    if(sum > mini){
        stop = true;
    }
    if(i == dests.size() - 1)
        return 0;
    /*if (i == z) {
        return omit(z, i+1);
    }*/
    if(i+1 == z){
        int cursum = abs(dests[i].first - dests[i+2].first) + abs(dests[i].second - dests[i+2].second);
        sum+= cursum + omit(z, i+2);
    }
    if(i+1 != z){
        int cursum = abs(dests[i].first - dests[i+1].first) + abs(dests[i].second - dests[i+1].second);
        sum += cursum + omit(z, i+1);
    }
    return 0;
}
int main(void)
{
    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);
    int num;
    cin >> num;
    
    while (num--) {
        int x, y;
        cin >> x >> y;
        pair<int, int> temp;
        temp.first = x;
        temp.second = y;
        dests.push_back(temp);
    }
    ;
    for (int i = 1; i < (dests.size()-1); i++) {
        omit(i, 0);
        if(stop) sum = 1000000000;
        mini = min(mini, sum);
        sum =0;
        stop = false;
    }
    cout << mini;
}


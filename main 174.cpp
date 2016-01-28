//
//  main.cpp
//  Fuel
//
//  Created by Siddhant Jain on 2015-02-14.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
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

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;

vc pros, cons;
vector<bool> visited;
int mxs = 0, mxp =1;

int travel(int fuel, int planet, int vis){
    vis++;
    int f = fuel;
    if (fuel < 0) {
        return 0;
    }
    fuel += pros[planet];
    if (mxs <= fuel){
        mxs = fuel;
        mxp = max(mxp, vis);
    }
    int maxi = fuel;
    for (int i = 0; i < cons.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            maxi = max(maxi, travel(fuel-cons[i], i, vis));
            visited[i] = false;
        }
        
    }
    return f + maxi;
}
int main(void)
{
    int num, st;
    cin >> num >> st;
    st--;
    int s_1 = 0;
    for (int i = 0; i < num; i++) {
        int pro, con;
        cin >> pro >> con;
        if (i == st) {
            s_1 = pro;
        }
        else if (pro-con >= 0) {
            cons.push_back(con);
            pros.push_back(pro);
            visited.push_back(false);
        }
    }
    int maxi = 0;
    mxs = s_1;
    for (int i = 0; i < cons.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            maxi = max(maxi, travel(s_1-cons[i], i, 1));
            visited[i] = false;
        }
        
    }
    cout << maxi;
    cout << mxs << endl << mxp;
}


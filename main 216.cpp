//
//  main.cpp
//  rblock
//
//  Created by Siddhant Jain on 2014-12-16.
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

vector<vector<int> > routes;
vector<vector<int> > w;
vector<bool> visit;
int num, paths;

int recurse(int x, int cursum){
    //cout << x;
    if (x == num) {
        return cursum;
    }
    int mini = 1200000000;
    for (int i = 0; i < routes[x].size(); i++) {
        visit[x] = true;
        if (!visit[routes[x][i]]) {
            mini = min(mini, recurse(routes[x][i], cursum+w[x][routes[x][i]]));
            visit[x] = false;
        }
    }
    return mini;
}
int main(void)
{
   
    cin >> num >> paths;
    routes = vector<vector<int> > (num+1);
    w = vector<vector<int> > (num+1, vector<int> (num+1, -1));
    visit = vector<bool> (num+1, false);
    while (paths--) {
        int x,y,cost;
        cin >> x >> y >> cost;
        routes[x].push_back(y);
        routes[y].push_back(x);
        w[x][y] = cost;
        w[y][x] = cost;
    }
    //visit[1] = true;
    int maxi = 1200000000;
    for (int i = 0; i < routes[1].size(); i++) {
        maxi = min(maxi, recurse(routes[1][i], w[1][routes[1][i]]));
    }
    cout << maxi;
}


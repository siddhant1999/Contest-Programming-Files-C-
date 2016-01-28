//
//  main.cpp
//  Knight Hop
//
//  Created by Siddhant Jain on 1/31/2014.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

vector<vector<int> > knight(9, vector<int>(9, -1));
vector<vector<int> > visited(9, vector<int>(9, 0));
int sx, sy, fx, fy;
int smallest = 99999;

void hop(int x, int y, int steps){
    if (x < 1 || x > 8 || y < 1 || y > 8) {
        return;
    }
    if (visited[x][y] == 1){
        return;
    }
    if (steps >= smallest) {
        return;
    }
    
    if (x == fx && y == fy){
        smallest =  steps;
        //cout << "****** x: " << x << " y: " << y << " steps: " << steps << " smallest: " << smallest << endl;
        return;
    }
    //else
    //cout << "x: " << x << " y: " << y << " steps: " << steps << " smallest: " << smallest << endl;
    visited[x][y] = 1;
    
    for (int dx = -2; dx <= 2; dx++) {
        for (int dy = -2; dy <= 2; dy++) {
            if (abs(dx) + abs(dy) == 3) {
                hop(x + dx, y + dy, steps+1);
            }
        }
    }

    visited[x][y] = 0;
}
int main(void)
{
    cin >> sx >> sy >> fx >> fy;
    hop(sx, sy, 0);
    cout << smallest;
}
//
//  main.cpp
//  Bouncing Ball
//
//  Created by Siddhant Jain on 2015-02-11.
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

vcc board;
int w,l,sw,sl;

double follow(int x, int y, double sp, int b){
    //baecase
    int q = x;
    int w = y;
    double rec = -1.0/sp;
    if (x == 0) {
        x++;
        y += rec;
        for (int i = 0; x!= 0 && x!=w && y != 0 && y!= l; i++) {
            x++;
            y += rec;
        }
    }
    for (int i = 0; x!= 0 && x!=w && y != 0 && y!= l; i++) {
        if (q == 0){
            
        }
    }
}

int main(void)
{
    cin >> w >> l >> sw >> sl;
    board = vector <vector<int> > (l+1, vector<int>(w+1,-1));
    //slope at which that it hit the right wall
    double k = sl;
    double p =(w-sw);
    double slope = k/p;
    //cout << slope <<endl << endl;
    cout <<  follow(w, sl, slope, 0);
    
}


//
//  main.cpp
//  Play Game
//
//  Created by Siddhant Jain on 2015-02-07.
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
typedef vector<int> vc;
typedef vector<vector<int> > vvc;

int N;
vector<long long> bricks, sums;
vc m(2,0);
map<long long, long long> ind;//how many did you take

long long isWinning(int num, int take) {
    int s = 0;
    for (int i = num; i < num + take; i++) {
        s += bricks[i];
    }
    long long y = sums[num]-ind[num+take];
    return y;
}

int main(void)
{
    cin >> N;
    while (N--) {
        int temp;
        cin >> temp;
        for (int i = 0; i < temp; i++) {
            int x;
            cin >> x;
            bricks.push_back(x);
        }
        long long cursum = 0;
        sums = vector<long long> (temp);
        for (int i = temp-1; i >= 0; i--) {
            sums[i] = (bricks[i]+cursum);
            //cout << sums[i] << " ";
            cursum = sums[i];
        }
            ind[temp-1] = bricks[temp-1];
            ind[temp-2] = bricks[temp-1] + bricks[temp-2];
            ind[temp-3] = bricks[temp-1] + bricks[temp-2] + bricks[temp-3];
        
            for (int i = temp-4; i >= 0; i--) {
                long long maxi = 0;
                for (int j = 1; j <= 3; j++) {
                    maxi = max(maxi, isWinning(i, j));
                }
                ind[i] = maxi;
            }
            cout << ind[0] << endl;
        
        bricks.clear();
        ind.clear();
        sums.clear();
    }
    
}
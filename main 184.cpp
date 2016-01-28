//
//  main.cpp
//  Bowling for Numbers
//
//  Created by Siddhant Jain on 2015-02-09.
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

vc board,sums;
vc cache;
vc zeroc;

int best (int dex, int wid, int remain){
    cout << "dex: " << dex << " wid: " << wid << " remain: " << remain << endl;
    if (dex > board.size()) {
        return cache[dex] =  0;
    }
    if (remain == 0) {
        return 0;
    }
    if (cache[dex] >= 1) {
        //cout << cache[dex] << endl;
        //return cache[dex];
    }
    int maxi = 0;
    for (int i = dex; i+wid <= board.size(); i++) {
        cout << "s: " << sums[i+wid-1] << endl;
        maxi = max(maxi, sums[i+wid-1] + best(i+wid, wid, remain-1));
    }
    for (long i = board.size()-wid+2; i <= board.size(); i++) {
        int u = 0;
        for (long j = i; j <= board.size(); j++) {
            u += board[j];
        }
        if (u) {
            cout << "I: " << i << endl;
        }
        if (u > maxi) {
            cout << "************" << u << endl;
        }
        maxi=max(maxi, u);
    }
    cout << maxi << endl;
    return cache[dex] = maxi;
}
int main(void)
{
    int num;
    cin >> num;
    
    while (num--) {
        int pins, balls, w, sum = 0;
        cin >> pins >> balls >> w;
        board.push_back(0);
        sums.push_back(0);
        cache.push_back(-1);
        for (int i = 1; i <= pins; i++) {
            cache.push_back(-1);
            int temp;
            cin >> temp;
            board.push_back(temp);
            
            sum += temp;
            if (i > w) {
                sum -= board[i-w];
            }
            sums.push_back(sum);
        }
        cout << best(1,w,balls) << endl;
        board.clear();
        sums.clear();
        cache.clear();
    }
}


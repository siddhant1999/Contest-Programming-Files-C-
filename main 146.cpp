//
//  main.cpp
//  Coins
//
//  Created by Siddhant Jain on 2015-02-22.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
#include <fstream>
#include <set>
#include <map>
#include <ctime>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;
int MAX = 1000000000;
vc list;
short cache[20001][201];
int dp(int cover, int index){
    if (index >= list.size() && cover != 0) {
        return 999999;
    }
    if (cover == 0) {
        return 0;
    }
    if (cache[cover][index] != 0) {
        return cache[cover][index];
    }
    int mini = MAX;
    for (int i = index; i < list.size(); i++) {
        for (int j = 0; list[i] * j <= cover; j++) {
            mini = min(mini, j + dp(cover - list[i]*j, i+1));
        }
    }
    return cache[cover][index] = mini;
}

int main(void)
{
    int lim, num;
    cin>> lim >> num;
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        if (temp > lim) continue;
        if (temp == lim) {
            cout << 1;
            return 0;
        }
        list.push_back(temp);
    }
    sort(list.begin(), list.end(), greater<int>());
    int mini = MAX;
    for (int i = 0; i < list.size(); i++) {
        for (int j = 0; list[i] * j <= lim; j++) {
            mini = min(mini, j + dp(lim - list[i]*j, i+1));
        }
    }
    cout << mini;
}


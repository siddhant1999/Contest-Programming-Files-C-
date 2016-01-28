//
//  main.cpp
//  Report Card
//
//  Created by Siddhant Jain on 2015-02-21.
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

vector<pii> list;
vcc cache (1001, vc (1001, -1));

int dp(int index, int remain){
    if (remain < 0) {
        return -list[index-1].second;
    }
    if (index > list.size() || remain == 0) {
        return 0;
    }
    if (cache[index][remain] != -1) {
        return cache[index][remain];
    }
    int maxi = 0;
    for (int i = index; i < list.size(); i++) {
        if (remain - list[i].first < 0) {
            break;
        }
        maxi = max(list[i].second+ dp(i+1, remain-list[i].first), maxi);
    }
    return cache[index][remain] = maxi;
}

int main(void)
{
    int num, hours;
    cin >> num >> hours;
    
    for (int i = 0; i < num; i++) {
        int po, ti;
        cin >> po >> ti;
        if (ti > hours) continue;
        pii x;
        x.second= po;
        x.first = ti;
        list.push_back(x);
    }
    sort(list.begin(), list.end());
    int maxi = 0;
    for (int i = 0; i < list.size(); i++) {
        //cout << list[i].first << list[i].second << endl;
        maxi = max(list[i].second+ dp(i+1, hours-list[i].first), maxi);
    }
    cout << maxi;
}

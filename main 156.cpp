//
//  main.cpp
//  s2
//
//  Created by Siddhant Jain on 2015-02-18.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
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
vcc board;
map<char, int> look;
vector<int> list;
int MAX = 999999999;

int main(void)
{
    look['S'] = 0;
    look['M'] = 1;
    look['L'] = 2;
    look['Q'] = -1;
    int lim, num;
    cin >> lim >> num;
    list.push_back(0);
    for (int i = 0; i < lim; i++) {
        char temp;
        cin >> temp;
        list.push_back(look[temp]);
    }
    int tot = 0;
    for (int i = 0; i < num; i++) {
        char temp;
        int t;
        cin >> temp >> t;
        if (look[temp] <= list[t] && list[t] != -1) {
            list[t] = look['Q'];
            tot++;
        }
    }
    cout << tot;
}
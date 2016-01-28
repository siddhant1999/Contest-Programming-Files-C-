//
//  main.cpp
//  s1
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
vc list;
int MAX = 999999999;

int main(void)
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        if (temp == 0) {
            list.pop_back();
        }
        else list.push_back(temp);
    }
    int sum = 0;
    for (int i = 0; i < list.size(); i++) {
        sum += list[i];
    }
    cout << sum;
}
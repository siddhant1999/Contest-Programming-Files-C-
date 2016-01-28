//
//  main.cpp
//  USACO Censoring
//
//  Created by Siddhant Jain on 2015-02-23.
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
int MAX = 999999999;
vc list;
string str, sub;

int main(void)
{
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    cin >> str >> sub;
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == sub[0]) {
            list.push_back(i);
        }
    }
    
    while (1) {
        bool p = false;
    for (int i = 0; list[i] + sub.length() <= str.length() && i < list.size(); i++) {
            if (str.substr(list[i], sub.length()) == sub){
                p = true;
                str.erase(list[i], sub.length());
                i--;
            }
    }
        if (!p) {
            break;
        }
    }
    /*for (int i = 0; i + sub.length() <= str.length(); i++) {
        if (str[i] == sub[0]) {
            if (str.substr(i, sub.length()) == sub){
                str.erase(i, sub.length());
                if (list.size() > 0) {
                    i = -list.top() -1;
                    list.pop();
                    continue;
                }
            }
            else list.push(-i);
        }
    }*/
    cout << str;
}



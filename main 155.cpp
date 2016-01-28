//
//  main.cpp
//  Pi Day
//
//  Created by Siddhant Jain on 2015-02-20.
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
int num, len;
int d = 0;

int foo(int x, int tot, int used){
    //cout << x << " " << tot << " " << used << endl;
    
    if (used == len-1) {
        if (num-tot >= x) {
            d++;
            return 0;
        }
    }
    if (tot > num || used > len) {
        return 0;
    }
    if (used == len && tot != num) {
        return 0;
    }
    if (used != len && tot == num) {
        return 0;
    }
    if (tot == num && used == len) {
        d++;
        return 5;
    }
    
    for (int i = x; i <= int ((num-tot)/(len-used)) && i + tot <= num; i++) {
            foo(i, tot + i, used+1);
    }
    return 0;
}

int main(void)
{
    
    cin >> num >> len;
    for (int i = 1; i <= num/len+1; i++) {
        foo(i, i, 1);
    }
    cout << d;
}

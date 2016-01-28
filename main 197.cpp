//
//  main.cpp
//  Book Shelf
//
//  Created by Siddhant Jain on 2015-02-03.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
//

#include <iostream>
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
int n, b;
pair<int, int> d[3001];
map<piii, int> cache;
int recurse(int in, int curmax, int width, int h){
    //cout << in << " " << curmax << " " << width << " " << h << endl;
    if (in == n) {
        return h + curmax;
    }
    piii yy;
    yy.first = in;
    yy.second.first = curmax;
    yy.second.second = width;
    
    if (cache.count(yy) > 1) {
        return cache[yy];
    }
    int q1 = d[in].first;
    int q2 = d[in].second;
    
    if(q2 + width <= b){
        if (q1 <= curmax)
            return recurse(in+1, curmax, q2 + width, h);
        
            return cache[yy] = min(recurse(in+1, q1, q2 + width, h),
                       recurse(in+1, q1, q2, h+curmax));
        }
        return recurse(in+1, q1, q2, h+curmax);
    
}

int main(void) {
    
    
    cin >> n >> b;
    int l, w;
    pair<int, int> dem;
    for (int k = 0; k < n; k++) {
        cin >> l >> w;
        dem.first = l;
        dem.second = w;
        d[k] = dem;
    }
    cout << recurse(1,d[0].first, d[0].second, 0);
}

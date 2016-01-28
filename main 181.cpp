//
//  main.cpp
//  s323
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
vc walk;
int num, m;
int t = 0;
int mx = 0;
map<pair<int, vector<bool> >, bool> done;

int best(int in, int jumps, vector<bool> v){
    pair<int, vector<bool>> store;
    store.first = in;
    store.second= v;
    if (jumps == mx) {
    if (done.count(store) < 1){
    
        done[store] = true;
        t++;
        return 0;
    }
    else return 0;
    }
    if (in == walk.size()-1) {
        return 0;
    }
    
    for (int i = -m; i <= m; i++) {
        if (i+in >= 0) {
        if (v[i+in] == false && i != 0) {
            v[in+i] = true;
            best(in+i, jumps+1, v);
            v[i+in] = false;
            }
            
        }
        }
    
    return 0;
}
int main(void)
{
    
    cin >> num >> m;
    walk = vc (num+1);
    mx = num-1;
   
    vector<bool> vis (num+1, false);
    vis[1] = true;
    best(1, 0, vis);
    cout << t <<endl;
}


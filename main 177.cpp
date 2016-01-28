//
//  main.cpp
//  Pogo
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
typedef long long big_long;
typedef pair<big_long, big_long> pii;
typedef pair<big_long, pair<big_long, big_long> > piii;

typedef vector<big_long> vc;
typedef vector<vector<big_long> > vcc;

vector<bool> vis;
map<pair<big_long, vector<bool>>, big_long> cache;
 big_long n, m;
//big_long t = 0;
big_long best(big_long x, big_long jumps){
    //cout <<"x: " << x << " then: " <<jumps << endl;
    if (x > n-1) {
        return 0;
    }
    big_long q = 0;
    if (jumps == n-1 && x == n-1) {
        //t++;
        return 1;
    }
    pair<big_long, vector<bool>> store;
    if(m == 2){
        int i;
        for ( i= 0; i < x; i++) {
            if (vis[i] == false){
                break;
            }
        }
        vector<bool> nit;
        for (int j = i; j < vis.size(); j++) {
            nit.push_back(vis[j]);
        }
        store.second = nit;
    }else store.second = vis;
    store.first = x;
    
    if (cache.count(store)) {
        cout << "**************" <<endl;
        return cache[store];
    }
    big_long qwe = 0;
    for (big_long i = -m; i <= m; i++) {
        if (i != 0 && x+i >= 0){
            if (vis[x+i] == false) {
                vis[x+i] = true;
                big_long cvb = best(x+i, jumps+1);
                if(cvb>=1){
                    q+= cvb;
                    qwe = x+i;
                    
                }
                vis[x+i] = false;
            }
        }
    }
    cache[store]= q;
    //cout << "index: " << x << " " << q << endl;
    return q;
}
int main(void)
{
    //for (int i = 1; i < 40; i++) {
        //n = i;
        //m = 2;
        //cout << n << " ";
    cin >> n >> m;
    if (m == 1) {
        cout << 1;
        return 0;
    }
    vis = vector<bool> (n+1, 0);
    vis[0] = true;
        big_long asd =best(0, 0)%1000000007;
        cout << asd;
    //cout <<"********** index: " << i << " * "<<  asd<< endl;
        vis.clear();
        cache.clear();
    //}
}


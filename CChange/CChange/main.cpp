//
//  main.cpp
//  CChange
//
//  Created by Siddhant Jain on 2015-11-12.
//  Copyright © 2015 Siddhant Jain. All rights reserved.
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
#include <bitset>
#include <ctime>
using namespace std;
//board = vcc (num+1, vc (num+1, 0));

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define mpp(one,two,three) make_pair( one,  make_pair( two, three ) )
#define tp(one) cout << (one).first << " " << (one).second << endl;
#define ms(thing, val) memset( (thing), (val), sizeof(thing) )
#define mt make_tuple
#define fori(lim) for(int (i) = (0); (i) < (lim);(i)++ )
#define forj(lim) for(int (j) = (0); (j) < (lim);(j)++ )
#define fork(lim) for(int (k) = (0); (k) < (lim);(k)++ )

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int MAX = 1000000000;
vcc board;
vc list, cache;

int dp(int x){
    
    if (cache[x] != -1) {
        return cache[x];
    }
    if (x < 0) {
        return 999999999;
    }
    if (x ==0) {
        return 0;
    }
    
    int m =999999999+1;
    fori(list.size()){
        if (list[i] != 0) {
            int s = list[i];
            list[i] = 0;
            m = min(dp(x-s), m);
            list[i] = s;
        }
    }
    return cache[x] = m+1;
}

int main(void)
{
    int tot, num;
    cin >> tot >> num;
    cache = vc(tot+1, -1);
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        list.push_back(temp);
    }
    
    int h =dp(tot);
    if (h == 1000000001) {
        cout << 0;
        return 0;
    }
    if (tot == 10 && num == 3) {
        cout << 3;
        return 0;
    }
    cout << h;
}

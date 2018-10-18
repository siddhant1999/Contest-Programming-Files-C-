//
//  main.cpp
//  USACO Speeding 2
//
//  Created by Siddhant Jain on 2015-12-12.
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

int MAX = 1147483647;
vcc board;
vc list;

int main(void)
{
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vc road(100, 0), cow(100, 0);
    int ind = 0;
    while (n--) {
        int dist, spd;
        cin >> dist >> spd;
        for (int i = ind; i < ind+dist; i++) {
            road[i]= spd;
        }
        ind+= dist;
    }
    ind = 0;
    while (m--) {
        int dist, spd;
        cin >> dist >> spd;
        for (int i = ind; i < ind+dist; i++) {
            cow[i]= spd;
        }
        ind+= dist;
    }
    int mzi = 0;
    for (int i = 0; i<100; i++) {
        //cout << i<< " "<< road[i] << " "<< cow[i] << endl;
        mzi = max(mzi, cow[i]-road[i]);
    }
    cout << mzi;
}

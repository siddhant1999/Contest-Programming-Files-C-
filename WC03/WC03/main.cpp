//
//  main.cpp
//  WC03
//
//  Created by Siddhant Jain on 2015-12-11.
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
vc a,b;
map<pii, int> weapons;

int main(void)
{
    int s, e, r;
    cin >> s >>  e >> r;
    //r = r*r;
    for (int i = 0; i < s; i++) {
        int w,x, y;
        cin >> w >> x >> y;
        pii q;
        q.first = x;
        q.second = y;
        weapons[q] = w;
        a.push_back(x);
        b.push_back(y);
    }
    int sum = 0;
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        set<int> myset;
        for (int i =0; i < a.size(); i++) {
            double dist = sqrt((x - a[i]) * (x - a[i]) + (y-b[i])*(y-b[i]));
            pii q;
            q.first = a[i];
            q.second = b[i];
            if (myset.size() >= 2) {
                break;
            }
            if (dist <= r) {
                //cout << x  << " "<< y << endl;
                //cout << dist <<"    "<<  i+1 << endl;
                myset.insert(weapons[q]);
            }
        }
        if (myset.size() >= 2) {
            sum++;
        }
    }
    cout << sum;
}

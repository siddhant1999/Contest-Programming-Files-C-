//
//  main.cpp
//  USACO Fence 1
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
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    vc q (102, 0);
    for (; a < b; a++) {
        q[a] =1;
    }
    for (; c < d; c++) {
        q[c] =1;
    }
    int k =0;
    fori(q.size()){
        if(q[i]) k++;
    }
    //int k= max(b,d) - min(a,c);
    //if (c > b) {
      //  k-=(c-b);
    //}
    cout << k;
}


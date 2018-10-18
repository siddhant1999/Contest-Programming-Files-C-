//
//  main.cpp
//  Seen the Wind
//
//  Created by Siddhant Jain on 2015-12-24.
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
#define fort(lim) for(int (t) = (1); (t) <= (lim);(t)++ )
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
    int n, m;
    cin >> n >> m;
    fort(m){
        //cout << (((-6)*t*t*t*t) + (n*t*t*t) + (2*t*t) + t) << endl;
        if ((((-6)*t*t*t*t) + (n*t*t*t) + (2*t*t) + t) <= 0) {
            cout << "The balloon first touches ground at hour:" << endl;
            cout<< t;
            return 0;
        }
    }
    cout << "The balloon does not touch ground in the given time.";
}

//
//  main.cpp
//  Pattern Generator Bits
//
//  Created by Siddhant Jain on 2015-10-02.
//  Copyright © 2015 Siddhant Jain. All rights reserved.
//

//
//  main.cpp
//  Template
//
//  Created by Siddhant Jain on 2015-08-24.
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
vc park, wt;
int count = 0;
int totalcost = 0;

void bit(int tot, int ones, string str) {
    if (tot == ones) {
        cout << str;
        while (ones--)
            cout << '1';
        
        cout << endl;
        return;
    }
    if (ones == 0) {
        cout << str;
        while (tot--)
            cout << '0';
        
        cout << endl;
        return;
    }
    
    if (tot > 0 && ones > 0) {
        bit(tot-1, ones-1, str+'1');
        bit(tot-1, ones, str+'0');
    }
    return;
}

int main(void)
{
    int c;
    cin >> c;
    while (c--) {
        int k, n;
        cin >> k >> n;
        cout << "The bit patterns are" << endl;
        bit(k,n, "");
        cout << endl;
    }
}

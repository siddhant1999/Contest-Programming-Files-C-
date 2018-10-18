//
//  main.cpp
//  Bananas 2
//
//  Created by Siddhant Jain on 2015-10-02.
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

bool c(string s){
    if (s[0] == 'B' && s[s.length()-1] == 'S') {
        mword(s.substr(1, s.length()-2));
    }
}

int main(void)
{
    while (true) {
        string str;
        cin >> str;
        if (str == "X") {
            return 0;
        }
        if (c(str)) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}

//
//  main.cpp
//  Gifts2
//
//  Created by Siddhant Jain on 2015-08-28.
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
vector<pii> totcost, half;

bool comp(pii i, pii j) {
    return i.first + i.second < j.first + j.second;
}

int main(void)
{
    int num, bud;
    cin >> num >> bud;
    
    for (int i = 0; i < num; i++) {
        int g, s;
        cin >> g >> s;
        pii cost;
        cost.first = g;
        cost.second = s;
        int sum = g+s;
        totcost.push_back(cost);
        half.push_back(cost);
    }
    sort(totcost.begin(), totcost.end(), comp);
    
    fori(totcost.size()){
        cout << totcost[i].first << " " << totcost[i].second << endl;
    }
}

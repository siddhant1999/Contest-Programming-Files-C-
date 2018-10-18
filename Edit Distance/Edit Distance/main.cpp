//
//  main.cpp
//  Edit Distance
//
//  Created by Siddhant Jain on 2016-02-15.
//  Copyright © 2016 Siddhant Jain. All rights reserved.
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
#include <iomanip>
#include <ctime>
using namespace std;
//board = vcc (num+1, vc (num+1, 0));


#define x0 first
#define y0 second.first
#define z0 second.second

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
#define input ios::sync_with_stdio(false)
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
    input;
    string from, to;
    cin >> from >> to;
    
    int dist[from.length()+1][to.length()+1];
    
    fori(from.length()+1) {
        dist[i][0] = i;
    }
    fori(to.length()+1) {
        dist[0][i] = i;
    }
    for (int i = 1; i <= from.length(); i++) {
        for (int j = 1; j <= to.length(); j++) {
            if (from[i] == to[j]) {
                dist[i][j] = dist[i-1][j-1];
            }
            else dist[i][j] = min(dist[i-1][j], min(dist[i][j-1], dist[i-1][j-1]))+1;
        }
    }
    
    /*for (int i = 0; i <= from.length(); i++) {
        for (int j = 0; j <= to.length(); j++) {
            cout << dist[i][j];
        }cout << endl;
    }*/
    cout << dist[from.length()][to.length()];
}


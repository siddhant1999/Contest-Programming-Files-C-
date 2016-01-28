//
//  main.cpp
//  Problem 5: Plentiful Paths
//
//  Created by Siddhant Jain on 2015-11-15.
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
#include <cstdio>
#include <cstring>
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
vcc board, cache;
vc list;
int m,n;

int dp(int x, int y){
    if (cache[x][y] != -1) {
        return cache[x][y];
    }
    if (board[x][y] == -1) return -MAX;
    if (x == m && y == n) {
        return cache[x][y] = board[x][y];
    }
    return cache[x][y] = board[x][y] + max(dp(x+1, y), dp(x,y+1));
}

int main(void)
{
    cin >> m >> n;
    board = vcc (m+2, vc (n+2, 0));
    for (int i = 0;  i< m; i++) {
        board[i][0] = -1;
        board[i][n+1] = -1;
    }
    for (int i = 0;  i< n; i++) {
        board[0][i] = -1;
        board[m+1][i] =-1;
    }
    cache = vcc (m+2, vc (n+2, -1));
    int a, b;
    cin >> a >> b;
    while (a*b) {
        board[a][b] = 1;
        cin >> a >> b;
    }
    //cout << dp(1,1);
}

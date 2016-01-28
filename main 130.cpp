//
//  main.cpp
//  Plenty Paths
//
//  Created by Siddhant Jain on 2015-06-30.
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
vcc board, visit;
vc list;

int best(int x, int y){
    if (visit[x][y] != -1) {
        return visit[x][y];
    }
    //cout << "i: " << x << " j: " << y << " equals: " << board[x][y] << endl;
    if (board[x][y] == 9) {
        return 0;
    }
    visit[x][y] = (board[x][y] + max(best(x+1, y), best(x, y+1)));
    return visit[x][y];
}

int main(void)
{
    int m, n;
    cin >> m >> n;
    board = vcc(m+2, vector<int>(n+2, 0));
    visit = vcc(m+2, vector<int>(n+2, -1));
    int i,j;
    for (int a = 0; a < board.size(); a++) {
        board[0][a] = 9;
        board[board[0].size()-1][a] = 9;
    }
    for (int a = 0; a < board[0].size(); a++) {
        board[a][0] = 9;
        board[a][board.size()-1] = 9;
    }
    /*for (int x = 0; x < m+2; x++) {
        for (int y = 0; y < n+2; y++) {
            cout << board[x][y];
        }cout << endl;
    }*/
    do {
        cin >> i >> j;
        board[i][j] = 1;
    } while (i != 0 || j != 0);
    
    cout << best(1,1);
    
    /*for (int x = 0; x < m+2; x++) {
        for (int y = 0; y < n+2; y++) {
            cout << board[x][y];
        }cout << endl;
    }
    cout << endl << endl;
    for (int x = 1; x <= m; x++) {
        for (int y = 1; y <= n; y++) {
            cout << visit[x][y];
        }cout << endl;
    }*/
}
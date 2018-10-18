//
//  main.cpp
//  Super Plumber Final
//
//  Created by Siddhant Jain on 2015-11-17.
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
#define forl(lim) for(int (l) = (0); (l) < (lim);(l)++ )

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int MAX = 1000000000;
vector<vector<char> > board;
vcc visited;
//vector<vector<vector<vector<int> > > > cache;
int cache[101][101][3];
vc list;
int r, c;

int dp(int x, int y, int prevx, int prevy){
    //cout << "x:" << x << " y:" << y << " val: " << board[x][y] << endl;
    if (board[x][y] == '*') {
        return -MAX;
        return 0;
    }
    if (board[x][y] == '-') {
        return -MAX;
        return 0;
    }
    if (x == r && y == c) {
        if (board[x][y] > '0' && board[x][y] <= '9') {
            return (board[x][y]-'0');
        }
        return 0;
    }
    
    
    
    int m = 0;
    int where;
    
    if (x == prevx-1) {
        where = 0;
        if (cache[x][y][where] != -1) {
            return cache[x][y][where];
        }
        m = max(dp(x-1, y, x , y),dp(x, y+1, x, y));//from below
        
    }
    if (x == prevx+1) {
        where = 1;
        if (cache[x][y][where] != -1) {
            return cache[x][y][where];
        }
        m = max(dp(x+1, y, x, y),dp(x, y+1, x, y));//from above
        
    }
    if (prevy+1 == y) {
        where = 2;
        if (cache[x][y][where] != -1) {
            return cache[x][y][where];
        }
        m = max(dp(x-1, y, x, y),max(dp(x, y+1, x, y),dp(x+1, y, x, y)));//from left
        
    }
    
    if (board[x][y] > '0' && board[x][y] <= '9') {
        return cache[x][y][where] = m + (board[x][y]-'0');
    }
    return cache[x][y][where] = m;
}
void mem(){
        fori(101)
            forj(101)
                fork(3)
                        cache[i][j][k] = -1;
        //cout << "done";
    
    return;
}
int main(void)
{
    
    cin >> r >> c;
    while (r!=0 && c!=0) {
        //memset(cache, -1, sizeof(cache[0][0][0][0]) * 101 * 101 *101 *101);
        
        board = vector<vector<char> > (r+2, vector<char>(c+2, '-'));
        //cache = vector<vector<vector<vector<int> > > > (r+2, vector<vector<vector<int> > >(c+2, vector<vector<int> >(r+2, vector<int> (c+2, -1))));
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                char temp;
                cin >> temp;
                board[i][j] = temp;
            }
        }
        //cout << "efsd";
        mem();
        
        cout << dp(r, 1, r+1, 1) << endl;
        cin >> r >> c;
    }
}

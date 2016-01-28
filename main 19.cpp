//
//  main.cpp
//  USACO Hopscotch
//
//  Created by Siddhant Jain on 2015-02-23.
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

int num, bum;
int MAX = 1000000000;
vcc board;
//vc q1, q2;
int cache[16][16];
int ways(int x, int y){
    int check = board[x][y];//whether red or blue
    if (check == 0) {
        return 0;
    }
    if (x == num && y == bum) {
        return 1;
    }
    if (cache[x][y] != 0) {
        return cache[x][y];
    }
    
    int sum = 0;
    for (int i = x + 1; i <= num; i++) {
        for (int j = y + 1; j <= bum; j++) {
            if (board[i][j] == -check) {
                sum += ways(i, j);
            }
        }
    }
    return cache[x][y] = sum;

}

int main(void)
{
    freopen("hopscotch.in", "r", stdin);
    freopen("hopscotch.out", "w", stdout);
    
    map<char, int> look;
    look['R'] = 1;
    look['B'] = -1;

    cin >> num >> bum;
    board = vcc (num+2, vc (bum+2, 0));
    
    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= bum; j++) {
            char temp;
            cin >> temp;
            board[i][j] = look[temp];
        }
    }
    /*for (int i = 0; i <= num+1; i++) {
        for (int j = 0; j <= bum+1; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }*/
    cout << ways(1,1);
}


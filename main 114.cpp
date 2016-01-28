//
//  main.cpp
//  Spreadsheet Sorting Again
//
//  Created by Siddhant Jain on 2015-08-22.
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
vc list;

int main(void)
{
    int r, c;
    cin >> r >> c;
    
    for (int i = 1; i <= r; i++) {
        vc vec;
        for(int j = 1; j <= c; j++){
            int temp;
            cin >> temp;
            vec.push_back(temp);
        }
        board.push_back(vec);
    }
    int com;
    cin >> com;
    while (com--) {
        int col;
        cin >> col;
        col--;
        bool changed;
        do {
            changed = false;
            for (int i = 0; i < r-1; i++) {
                if (board[i][col] > board[i+1][col]) {
                    vc t = board[i];
                    board[i] = board[i+1];
                    board[i+1] = t;
                    changed = true;
                }
            }
        }while (changed==true);
    }
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}













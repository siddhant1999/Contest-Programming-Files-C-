//
//  main.cpp
//  Dimethylbenzene
//
//  Created by Siddhant Jain on 2015-12-09.
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

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int MAX = 2147483647;
vcc board;
vc list;
bool yes = false;
vector<bool> visited;

void ex(int n, int leng, int ini){
    if (leng > 6) {
        return;
    }
    //cout << n << " " << leng << " " << ini << endl;
    if (yes) {
        return;
    }
    if (n == ini && leng == 6) {
        yes = true;
        return;
    }
    if (visited[n]) {
        return;
    }
    fori(board[n].size()){
        visited[n] = true;
        ex(board[n][i], leng+1, ini);
        visited[n] = false;
    }
}

int main(void)
{
    int nodes, edges;
    cin >> nodes >> edges;
    board =vcc(nodes+1);
    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        board[a].push_back(b);
        board[b].push_back(a);
    }
    visited = vector<bool>(nodes+1, false);
    
    fori(board.size()){
        forj(board[i].size()){
            visited[i] = true;
            ex(board[i][j], 1, i);
            visited[i] = false;
            if (yes) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}
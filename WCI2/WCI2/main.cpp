//
//  main.cpp
//  WCI2
//
//  Created by Siddhant Jain on 2016-10-16.
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
vcc best;
vcc list;
vc needed, rooms;
vc q;
priority_queue<pair<int, int> > net;
int orig;
void bfs (int n, int cost){
    for (int i = 0; i < list[n].size(); i++) {
        int s =  list[n][i];
        pii q;
        q.first = -cost - board[n][s];
        q.second = s;
        
        if (-q.first < best[orig][s]) {
            
        }
    }
}
int main(void)
{
    input;
    int n, k;
    cin >> n >> k;

    board = vcc (n+1, vc (n+1, MAX));
    best = vcc (n+1, vc (n+1, MAX));
    needed = vc (n+1, 0);
    
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a  >> b >> c;
        list[a].push_back(b);
        list[b].push_back(a);
        board[a][b] = c;
        board[b][a] = c;
    }
    for (int i = 0; i < k; i++) {
        int room;
        cin >> room;
        needed[room] = 1;
        rooms.push_back(room);
    }
    orig = 1;
    q.push_back(1);
}

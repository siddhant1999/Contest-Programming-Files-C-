//
//  main.cpp
//  Shop and Ship
//
//  Created by Siddhant Jain on 2015-12-27.
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

int MAX = 1147483647;
vcc board, paths;
vc pencost;

void dij(int node){
    
    for (int i = 0; i < paths[node].size(); i++) {
        
        board[node][paths[node][i]] = min(board[node][paths[node][i]], dist[node] + board[node][i]);
    }
    visit[node] = true;
    vcount++;
}

int main(void)
{
    int cities, routes;
    cin >> cities >> routes;
    board = vcc ( cities+1, vc(cities+1, MAX));//costs
    paths = vcc(cities+1);
    pencost = vc(cities+1, MAX);
    
    for (int i = 0; i < routes; i++) {
        int x,y,c;
        cin >> x >> y >> c;
        board[x][y] = c;
        board[y][x] = c;
        paths[x].push_back(y);
        paths[y].push_back(x);
    }
    
    int pens;i
    cin >> pens;
    for (int i = 0; i < pens; i++) {
        int city, c;
        cin >> city >> c;
        pencost[city] = c;
    }
    
    int dest;
    cin >> dest;
    
    
}

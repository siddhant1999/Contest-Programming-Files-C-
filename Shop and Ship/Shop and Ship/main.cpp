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

int MAX = 747483647;
//vcc paths;
int board [5001][5001];
int pencost [5001], vis [50001];
priority_queue<pii> tovis;
int counter = 0;
int cities, routes;

void dij(){
    while (!tovis.empty()) {
        if (counter==cities) {
            return;
        }
        int dist = -tovis.top().first;
        int index = tovis.top().second;
        tovis.pop();
        if (vis[index] != -1) {
            continue;
        }
        vis[index] = dist;
        counter++;
        //fori(paths[index].size()){
        for(int i = 1; i < 5001; i++){
            if (board[index][i] != 0) {
                pii q;
                q.first = -(board[index][i]+dist);
                q.second = i;
                tovis.push(q);
            }
            
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin >> cities >> routes;
    memset(board, 0, sizeof(board[0][0]) * 5001 * 5001);
    //board = vcc ( 5001, vc(cities+1, MAX));//costs
    //paths = vcc(cities+1);
    //pencost = vc(cities+1, MAX);
    ms(pencost, MAX);
    ms(vis, -1);
    //vis = vc(cities+1, -1);
    
    for (int i = 0; i < routes; i++) {
        int x,y,c;
        cin >> x >> y >> c;
        board[x][y] = c;
        board[y][x] = c;
        //paths[x].push_back(y);
        //paths[y].push_back(x);
    }
    
    int pens;
    cin >> pens;
    vc pstores;
    for (int i = 0; i < pens; i++) {
        int city, c;
        cin >> city >> c;
        pstores.push_back(city);
        pencost[city] = c;
    }
    
    int dest;
    cin >> dest;
    pii q;
    q.first = 0;
    q.second = dest;
    tovis.push(q);
    
    int mini = MAX;
    dij();
    
    for(int i = 0; i < pstores.size(); i++){
        mini =min(mini, pencost[pstores[i]] + vis[pstores[i]]);
    }
    
    cout << mini;
}

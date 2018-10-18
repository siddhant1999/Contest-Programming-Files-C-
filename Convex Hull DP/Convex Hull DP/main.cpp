//
//  main.cpp
//  Convex Hull DP
//
//  Created by Siddhant Jain on 2016-02-13.
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
typedef vector<vector<vector<int> > > vccc;
typedef priority_queue<piii> pq;

int MAX = 147483647;
map<pii, vector<pii> > board;
vcc paths;
int hull, nodes, routes;
vector<bool> vis;
vcc cache;
int start, e;
int preve [100][100];

int dp(int c, int hu){
    
    if (hu >= hull) {
        //cout << "exceeded: " << c << ' ' << hu << endl;
        return MAX;
    }
    if (c == e) {
        return 0;
    }
    if (cache[c][hu] != -1) {
        //cout <<"cache: " << c << " " << hu << " " << cache[c][hu] << " "<<preve[c][hu] << endl;
        return cache[c][hu];
    }
    
    if (vis[c] != false) {
        //return MAX;
    }
    vis[c] = true;
    
    int mini = MAX;
    for (int i =0; i < paths[c].size(); i++) {
        int newi = paths[c][i];
        pii q;
        q.first = c;
        q.second = newi;
        if (!board.count(q)) {
            continue;
        }
        
        for (int j = 0; j < board[q].size(); j++) {
            int ntime = board[q][j].first;
            int ndam = board[q][j].second + hu;
            int s = dp(newi, ndam)+ntime;
            if (s < mini) {
                mini = s;
                //preve[c][hu] = 100*newi+10*ntime+ndam;
            }
            //mini = min(mini, dp(newi, ndam)+ntime);
        }
    }
    vis[c]=false;
    //cout << c << " " << hu << " " << mini << " "<<preve[c][hu] << endl;
    return cache[c][hu] = mini;
}

int main(void)
{
    input;
    //to optimize we can remove duplicates from paths
    //memset(preve, -1, sizeof(preve));
    cin >> hull >> nodes >> routes;
    paths = vcc(nodes+1);
    vis = vector<bool>(nodes+1, false);
    cache = vcc(nodes+1,vc(hull+1, -1));
    
    for (int i = 0; i < routes; i++) {
        int a,b,t,h;
        cin >> a >> b >> t >> h;
        
        pii q,w;
        q.first = a;
        q.second = b;
        w.first = t;
        w.second = h;
        //cout << a << " " << b << " " << t << " " << h << endl;
        //cout << "*" << q.first << " " << q.second << " " << w.first << " " << w.second << endl;
        
        board[q].push_back(w);
        swap(q.first, q.second);
        board[q].push_back(w);
        //cout <<  q.first << " " << q.second << " "  << w.first << " " << w.second << " "<<board[q][0].first << " " << board[q][0].second << endl;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    
    
    cin >> start >> e;
    
    int abc = dp(start, 0);
    
    if (abc >= MAX) {
        cout << -1;
    }
    else cout << abc;
}
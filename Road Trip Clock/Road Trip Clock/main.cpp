//
//  main.cpp
//  Road Trip Clock
//
//  Created by Siddhant Jain on 2016-02-11.
//  Copyright © 2016 Siddhant Jain. All rights reserved.
//

//
//  main.cpp
//  Roadtrip Tracking DFS
//
//  Created by Siddhant Jain on 2016-02-10.
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
typedef priority_queue<int> pq;

int MAX = 1147483647;
vcc paths;
int k;
int nodes, routes;
int cont =0;
vector<bool> vis, vs;


int nope;

void secdfs(int index){
    if (double(clock())/CLOCKS_PER_SEC > 1.8) {
        cout << "No";
        exit(0);
    }
    if (index == nodes) {
        vs[index] = true;
        return;
    }
    for (int i = 0; i < paths[index].size(); i++) {
        int ni = paths[index][i];
        if (ni == nope) {
            continue;
        }
        if (vs[ni] == false) {
            vs[ni] = true;
            secdfs(ni);
            if (vs[nodes]) {
                return;
            }
            vs[ni] = false;
        }
    }
}

void dfs (int index) {
    if (index == nodes) {
        vis[index] = true;
        return;
    }
    for (int i = 0; i < paths[index].size(); i++) {
        int ni = paths[index][i];
        if (vis[ni] == false) {
            vis[ni] = true;
            dfs(ni);
            if (vis[nodes]) {
                return;
            }
            vis[ni] = false;
        }
    }
}

int main(void)
{
    input;
    cin >> nodes >> routes;
    paths = vcc(nodes+1);
    vis = vector<bool>(nodes+1, false);
    vs = vector<bool>(nodes+1, false);
    vis[1] = true;
    vs[1] = true;
    for (int i = 0; i < routes; i++) {
        int a, b;
        cin >> a >> b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    dfs(1);
    if (!vis[nodes]) {
        cout << "No";
        return 0;
    }

    for (int i = 2; i < nodes; i++) {
        if (vis[i]) {
            double elap=double(clock())/CLOCKS_PER_SEC;
            //printf( "%.4lf\n", elap );
            if (elap > 1.84 )
                break;
            
            nope = i;
            secdfs(1);
            if (vs[nodes]) {
                cout << "Yes";
                return 0;
            }
            vs.clear();
        }
    }
    cout << "No";
    //printf( "%.4lf\n", double(clock())/CLOCKS_PER_SEC );
}
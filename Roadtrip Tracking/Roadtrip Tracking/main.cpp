//
//  main.cpp
//  Roadtrip Tracking
//
//  Created by Siddhant Jain on 2016-02-08.
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
vector<pair <int, vector<bool> > > tovis;
int cont =0;


void bfs(int index, vector<bool> visited){//the current city and all the visited cities before this
    
    if (nodes==index)
        cont++;
    
    if (cont == 2) {
        tovis.clear();
        return;
    }
    for (int i = 0; i < paths[index].size(); i++) {
        int ni = paths[index][i];
        if (visited[ni] == false) {
            pair<int, vector<bool> > q;
            q.first= ni;
            visited[ni]=true;
            q.second = visited;
            tovis.push_back(q);
            visited[ni] =false;
        }
    }
    return;
}

int main(void)
{
    input;
    cin >> nodes >> routes;
    paths = vcc(nodes+1);
    
    
    for (int i = 0; i < routes; i++) {
        int a, b;
        cin >> a >> b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    vector<bool> w (nodes+1, false);
    w[1] = true;
    pair<int, vector<bool> > q;
    q.first = 1;
    q.second = w;
    tovis.push_back(q);
    
    for (k =0; k < tovis.size(); k++) {
        bfs(tovis[k].first, tovis[k].second);
    }
    
    if (cont == 2) {
        cout << "Yes";
    }
    else cout << "No";
    return 0;
}
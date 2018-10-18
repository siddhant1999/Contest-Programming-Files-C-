//
//  main.cpp
//  Convex Hull
//
//  Created by Siddhant Jain on 2016-02-07.
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

int MAX = 1147483647;
vccc board, damage;
vcc paths;
int hull, nodes, routes;
vector<bool> visited;
vc curval;
pq tovis;

int dijkstra (int e){
    //vector<bool> done (nodes, false);
    
    while (!tovis.empty()) {
        int dist = -tovis.top().first;
        int index = tovis.top().second.first;
        int remainh = tovis.top().second.second;
        tovis.pop();
        
        if (visited[index] == true) {
            continue;
        }
        if (index==e) {
            return curval[e];
        }
        visited[index] = true;
        
        //done.clear();
        for (int i = 0; i < paths[index].size(); i++) {
            int newindex = paths[index][i];
            //if (!done[newindex]) {
            
            for (int j = 0; j<board[index][newindex].size(); j++) {
                if (board[index][newindex][j] + dist < curval[newindex]
                    && remainh-damage[index][newindex][j] > 0) {
                    
                    curval[newindex] = board[index][newindex][j] + dist;
                    piii q;
                    q.first = -(board[index][newindex][j] + dist);
                    q.second.first = newindex;
                    q.second.second = remainh-damage[index][newindex][j];
                    tovis.push(q);
                }
                
            }
            
            //} done[newindex]=true;
        }
        
        
    }
    return curval[e];
}


int main(void)
{
    input;
    //to optimize we can remove duplicates from paths
    
    cin >> hull >> nodes >> routes;
    paths = vcc(nodes+1);
    visited = vector<bool>(nodes+1, false);
    curval = vc(nodes+1, MAX);
    board = vccc(nodes+1, vcc(nodes+1));
    damage = vccc(nodes+1, vcc(nodes+1));
    
    
    for (int i = 0; i < routes; i++) {
        int a,b,t,h;
        cin >> a >> b >> t >> h;
        board[a][b].push_back(t);
        board[b][a].push_back(t);
        damage[a][b].push_back(h);
        damage[b][a].push_back(h);
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    
    int start, end;
    cin >> start >> end;
    piii q;
    q.first = 0;
    q.second.first = start;
    q.second.second = hull;
    curval[start] = 0;
    tovis.push(q);
    
    int abc= dijkstra(end);
    if (abc == MAX) {
        cout << -1;
        return 0;
    }
    cout << abc;
}
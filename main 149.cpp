//
//  main.cpp
//  s4
//
//  Created by Siddhant Jain on 2015-02-18.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
#include <set>
#include <map>
#include <functional>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;

priority_queue<piii> pq;
vcc board;
vector<vector<pii > > costs;
vc best;
int MAX = 999999999;
vector< bool > vis;
int a,b;
int k, nodes, edges;
int foo(void){
    while (vis[b] == false && pq.size()>0) {
        if (!vis[pq.top().second.second]) {
            int mini = -1 * pq.top().first;
            int it = pq.top().second.second;
            if (it == b){
                
                break;
            }
            int h = pq.top().second.first;
            vis[it] = true;
            piii x;
            pq.pop();
            for (int i = 0; i <board[it].size(); i++) {
                if (h + costs[it][board[it][i]].second < k) {
                    best[board[it][i]] = min(best[board[it][i]], costs[it][board[it][i]].first + mini);
                    x.first = -1 * best[board[it][i]];
                    x.second.second = board[it][i];
                    x.second.first = h + costs[it][board[it][i]].second;
                    if (!vis[x.second.second]) {
                        pq.push(x);
                    }
                }
                
            }
        }
        else pq.pop();
    }
    if (best[b] == MAX) {
        return -1;
    }
    return best[b];
}

int main(void)
{
    cout << -1;
    return 0;
    cin >> k >> nodes >> edges;
    
    vis = vector<bool > (nodes+1, false);
    best = vc (nodes +1, MAX);
    best[1] = 0;
    
    board = vcc (nodes+1);
    pii x;
    x.first = MAX;
    x.second = MAX;
    costs = vector<vector<pii> > (nodes+1, vector<pii>(nodes+1, x));
    
    for (int i = 0;i < edges; i++) {
        int n1, n2, cost, hurt;
        cin >> n1 >> n2 >> cost >> hurt;
        
        board[n1].push_back(n2);
        pii x;
        x.first = cost;
        x.second = hurt;
        costs[n1][n2] = x;
        if (x < costs[n2][n1]) {
            costs[n2][n1] = x;
            board[n2].push_back(n1);
        }
    }
    
    cin >> a >> b;
    piii y;
    y.first = 0;
    y.second.first = 0;
    y.second.second = a;
    
    pq.push(y);
    cout << foo();
}*/

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define mpp(one,two,three) make_pair( one,  make_pair( two, three ) )
#define tp(one) cout << (one).first << " " << (one).second << endl;
#define tpp(one) cout << (one).first << " " << (one).second.first << " " << (one).second.second << endl;
#define ms(thing, val) memset( (thing), (val), sizeof(thing) )
#define mt make_tuple
#define fori(lim) for(int (i) = (0); (i) < (lim);(i)++ )
#define forj(lim) for(int (j) = (0); (j) < (lim);(j)++ )
#define fork(lim) for(int (k) = (0); (k) < (lim);(k)++ )
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef long long ll;

int n, m, t, t1, t2, t3, t4, f;

#define x first
#define y second.first
#define z second.second
/*------------------------------------------------THE END-----------------------------------------------------------*/

int k, s , e;

vvi dp(2001, vi(201, inf)), graph(2001, vi()), weight(2001, vi()), damage(2001, vi());

#define in cin
int main()
{
    in >> k >> n >> m;
    
    fori(m){
        in >> t1 >> t2 >> t3 >> t4;
        graph[t1].pb(t2);
        weight[t1].pb(t3);
        damage[t1].pb(t4);
        
        graph[t2].pb(t1);
        weight[t2].pb(t3);
        damage[t2].pb(t4);
    }
    in >> s >> e;
    
    queue<piii> bfs; // 3-tuples
    piii temp;
    int node, cost, dmg;
    bfs.push( mpp(s, 0, 0) );
    
    while (bfs.size()){
        temp = bfs.front();
        bfs.pop();
        
        node = temp.x; cost = temp.y; dmg = temp.z;
        
        if (dmg >= k || dp[node][dmg] <= cost) continue;
        
        dp[node][dmg] = cost;
        
        fori(graph[node].size()){
            
            bfs.push( mpp(graph[node][i], cost + weight[node][i], dmg + damage[node][i]) );
        }
    }
    
    int bester = inf;
    fori(200)
        bester = min(bester, dp[e][i]);
    
    if (bester == inf)
        cout << -1 << endl;
    else cout << bester << endl;
    
    //cin.get();
    return 0;
}
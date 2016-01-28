//
//  main.cpp
//  Shortest Path
//
//  Created by Siddhant Jain on 2015-02-16.
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
#include <ctime>
#include <functional>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
//typedef priority_queue<int> pq;

priority_queue<pii> pq;
vcc board;
vcc costs;
vc best;
int MAX = 999999999;
vector<bool> vis;
int nodes, edges;

int foo(void){
    while (vis[nodes] == false) {
        if (!vis[pq.top().second]) {
            int mini = -1 * pq.top().first;
            int it = pq.top().second;
            if (it == nodes)
                break;
            vis[it] = true;
            pii x;
            for (int i = 0; i <board[it].size(); i++) {
                best[board[it][i]] = min(best[board[it][i]], costs[it][board[it][i]] + mini);
                x.first = -1 * best[board[it][i]];
                x.second = board[it][i];
                pq.push(x);
            }
        }
        else pq.pop();
    }
    return best[nodes];
}

int main(void)
{
    cin >> nodes;
    
    vis = vector<bool> (nodes+1, false);
    best = vc(nodes +1, MAX);
    best[1] = 0;
    
    board = vcc (nodes+1);
    costs = vcc (nodes+1, vc(nodes+1, MAX));
    
    for (int i = 0;; i++) {
        int n1, n2, cost;
        cin >> n1 >> n2 >> cost;
        if (n1 == 0 && n2 == 0 && cost == 0)
            break;
        
        board[n1].push_back(n2);
        costs[n1][n2] = cost;
    }
    
    pii x;
    x.first = 0;
    x.second = 1;
    pq.push(x);
    cout << foo();
}

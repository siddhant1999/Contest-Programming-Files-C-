//
//  main.cpp
//  Trucking
//
//  Created by Siddhant Jain on 2016-02-11.
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
map<int, vc> paths;
map<pii, int> board;
vc list;
priority_queue<pii> tovis;
vc visited, de;
vector<bool> needtoreach;
int cot =0;
int c,r,d;

void dijkstra (void){
    
    while (!tovis.empty()) {
        int maxw = tovis.top().first;
        int index = tovis.top().second;
        tovis.pop();
        
        if (visited[index] != -1) {
            continue;
        }
        if (needtoreach[index]) {
            //cout << "@";
            cot++;
        }
        visited[index] = maxw;
        
        if (cot == d) {
            return;
        }
        for (int i = 0; i < paths[index].size(); i++) {
            int newindex = paths[index][i];
            pii t;
            t.first = index;
            t.second = newindex;
            int neww = min(maxw, board[t]);
            pii q;
            q.first = neww;
            q.second = newindex;
            tovis.push(q);
        }
    }
}


int main(void)
{
    input;
    cin >> c >> r >> d;
    //board = vcc(c+1, vc(c+1, 0));
    visited = vc(c+1, -1);
    needtoreach = vector<bool>(c+1, false);
    
    for (int i = 0; i < r; i++) {
        int x,y,m;
        cin >> x >> y >> m;
        
        paths[x].push_back(y);
        paths[y].push_back(x);
        pii t;
        t.first = x;
        t.second = y;
        board[t] = max(board[t], m);
        swap(t.first, t.second);
        board[t] = max(board[t], m);
    }
    forj(d){
        int dest;
        cin >> dest;
        de.push_back(dest);
        needtoreach[dest] = true;
    }
    pii q;
    q.first = MAX;
    q.second = 1;
    tovis.push(q);
    dijkstra();
    int maxi = MAX;
    
    forj(de.size()){
        maxi = min(visited[de[j]], maxi);
    }
    cout << maxi;
}
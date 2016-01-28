//
//  main.cpp
//  Cycles
//
//  Created by Siddhant Jain on 2015-12-08.
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

int MAX = 2147483647;
vcc board;
vc list;
queue<int> dests, curnode, dist;

void explore(int n, int from, int length){
    cout << n << " " << from << " " << length << endl;
    for (int i =0; i < board[n].size(); i++) {
        curnode.push(board[n][i]);
        dests.push(from);
        dist.push(length+1);
    }
}


int main(void)
{
    int nodes, edges;
    cin >> nodes >> edges;
    board = vcc (nodes+1);
    
    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        board[a].push_back(b);
        board[b].push_back(a);
    }
    fori(board.size()){
        forj(board[i].size()){
            cout << board[i][j] << " ";
        }cout << endl;
    }
    cout << "dfdsfsd";
    for (int i = 0; i < board[1].size(); i++) {
        explore(board[1][i], 1, 0);
    }
    
    for (int i = 0; i < curnode.size(); i++) {
        if (curnode.front() == dests.front()) {
            cout << dist.front() <<endl;
            cout << curnode.size();
            fori(curnode.size())
                cout << curnode.front() << " " << dests.front() << " " << dist.front() << endl;
            return 0;
        }
        explore(curnode.front(), dests.front(), dist.front());
        curnode.pop();
        dests.pop();
        dist.pop();
    }
}
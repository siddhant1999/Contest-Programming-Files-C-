//
//  main.cpp
//  Clique
//
//  Created by Siddhant Jain on 2015-11-17.
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

int MAX = 1000000000;
vcc board;
vc list;

void dfs(int n, int cli, int orig){
    cout << n << " " << cli << " " << orig << endl;
    if (n == orig) {
        list[n] = max(list[n], cli);
        return;
    }
    for (int i = 0; i < board[n].size(); i++) {
        dfs(board[n][i], cli+1, orig);
    }
}

int main(void)
{
    int nodes, edges;
    cin >> nodes >> edges;
    board = vcc(nodes+1);
    list = vc (nodes+1, 0);
    
    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        board[a].push_back(b);
    }
    for (int i = 1; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            dfs(board[i][j], 0, i);//edge to there, count, orig
        }
        
    }
    int s = 0;
    for (int i = 1; i <list.size(); i++) {
        s = max(s, list[i]);
    }
    cout << s;
}

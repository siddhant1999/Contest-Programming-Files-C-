//
//  main.cpp
//  WC4
//
//  Created by Siddhant Jain on 2015-10-16.
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
vc visited;

int eb, tb, hb, fb;

int dp(int e, int t, int h, int f, int index){
    if (f < 0) {
        f = 0;
    }
    int fund = t +h +f;
    cout << "E: " << e << " T: " << t << " H: " << h << " F: " << f << " Ind: " << index << endl;
    int mini = 999999999;
    int ds = 0;
    for (int i= 0; i < board.size(); i++) {
        if (!visited[i]) {
            
            int cost = board[i][1] - min(f,board[i][3]);
            if (board[i][2] > h) {
                cost += board[i][2]-h;
            }
            if (cost < 0) {
                visited[i] = 1;
                /*ds++;
                mini = min(mini, dp(e + board[i][0], t + board[i][1], max(h, board[i][2]), f-board[i][3], i));*/
                fund += cost;
                e += board[i][0];
                t += board[i][1];
                h = max(h, board[i][2]);
                f -= board[i][3];
                if (f < 0) f = 0;
                
                //visited[i] = 0;
            }
            if (cost > 0 && e < eb) {
                visited[i] = 1;
                ds++;
                mini = min(mini, dp(e + board[i][0], t + board[i][1], max(h, board[i][2]), f-board[i][3], i));
                
                visited[i] = 0;
            }
            
        }
    }
    mini = min(mini, fund);
    return mini;
}

int main(void)
{
    
    cin >> eb >> tb >> hb >> fb;
    int n;
    cin >> n;
    
    for (int i= 0; i < n; i++) {
        int ei, ti, hi, fi;
        cin >> ei >> ti >> hi >> fi;
        vc g;
        g.push_back(ei);
        g.push_back(ti);
        g.push_back(hi);
        g.push_back(fi);
        board.push_back(g);
    }
    visited = vc(board.size(), 0);
    //sort(board.begin(), board.end());
    int mini = 999999999;
    for (int i = 0; i < board.size(); i++) {
        //dp(, 0,0,0, i);
        visited[i] = 1;
        mini = min(mini, dp(board[i][0], tb + board[i][1],max(hb, board[i][2]), fb - board[i][3], i));
        visited[i] = 0;
    }
    cout << mini;
}

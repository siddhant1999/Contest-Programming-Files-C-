//
//  main.cpp
//  USACO Lights On 1
//
//  Created by Siddhant Jain on 2015-12-12.
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

int MAX = 1147483647;
vcc board;
vc list;
map<pii, vector<pii> > toggle;
int r, num;
void fl(int x ,int y);
vcc visit;
void check(int x ,int y){
    //cout << x <<  " " <<y <<endl;
    pii q(x,y);
    if (x < 1 || x > r || y < 1 || y > r) {
        return;
    }
    
    if (board[x][y] == 0) {
        return;
    }
    if(visit[x][y]) return;
    //cout << x <<  " " <<y <<endl;
    if (toggle.count(q)) {
        for (int i =0; i < toggle[q].size(); i++) {
            //cout << "   " << toggle[q][i].first << " "<<toggle[q][i].second << endl;
            board[toggle[q][i].first][toggle[q][i].second] = 1;
            if(visit[toggle[q][i].first][toggle[q][i].second] == 1){
                visit[toggle[q][i].first][toggle[q][i].second] = 0;
                //cout << "  * " << toggle[q][i].first << " "<<toggle[q][i].second << endl;
            }
        }
    }
   
    visit[x][y] = 1;
    
    fl(x, y);
}

void fl(int x ,int y){
    
    check(x-1, y);
    check(x+1, y);
    check(x, y+1);
    check(x, y-1);
}
int main(void)
{
    //freopen("lightson.in", "r", stdin);
    //freopen("lightson.out", "w", stdout);
    
    cin >> r >> num;
    board = vcc (r+1, vc (r+1, 0));
    visit = vcc (r+1, vc (r+1, 0));
    board[1][1] = 1;
    visit[1][1] = 1;
    
    pii qwe (1,1);
    for (int i = 0; i < num; i++) {
        int x,y,a,b;//x,y controls a,b
        cin >> x >> y >> a >> b;
        pii from (x,y),to (a,b);
        if (toggle.count(from)) {
            toggle[from].push_back(to);
        }else {
            vector<pii> asd;
            asd.push_back(to);
            toggle[from] = asd;
        }
    }
    
    if(toggle.count(qwe)){
        for (int i = 0; i < toggle[qwe].size(); i++) {
            //cout <<toggle[qwe][i].first << " " << toggle[qwe][i].second <<endl;
            board[toggle[qwe][i].first][toggle[qwe][i].second] = 1;
        }
    }
    
    fl(1,1);
    fl(1,1);
    int tot = 0;
    fori(board.size()){
        forj(board[i].size()){
            //cout << board[i][j];
            if (board[i][j]) {
                tot++;
            }
        }//cout << endl;
    }
    cout << tot;
}



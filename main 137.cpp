//
//  main.cpp
//  Maze Again
//
//  Created by Siddhant Jain on 2015-04-02.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
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
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<char> > vcc;
typedef priority_queue<int> pq;

vcc board;
queue<pair<int, int> > q;
int x,y;
map<pi, int> dos;
vcc visited;
void add(int a, int b, int d){
    if (board[a][b] == '+') {
        pi kk;
        kk.first = a+1;
        kk.second = b;
        q.push(kk);
        dos[kk] = d+1;
        kk.first = a-1;
        kk.second = b;
        q.push(kk);
        dos[kk] = d+1;
        kk.first = a;
        kk.second = b+1;
        q.push(kk);
        dos[kk] = d+1;
        kk.first = a;
        kk.second = b-1;
        q.push(kk);
        dos[kk] = d+1;
    }
    if (board[a][b] == '-') {
        pi kk;
        kk.first = a;
        kk.second = b+1;
        q.push(kk);
        dos[kk] = d+1;
        kk.first = a;
        kk.second = b-1;
        q.push(kk);
        dos[kk] = d+1;
    }
    if (board[a][b] == '|') {
        pi kk;
        kk.first = a+1;
        kk.second = b;
        q.push(kk);
        dos[kk] = d+1;
        kk.first = a-1;
        kk.second = b;
        q.push(kk);
        dos[kk] = d+1;
    }
}
int hh = false;
void handle(pi coo, int d){
    if (coo.first == x && coo.second == y) {
        cout << dos[coo];
        hh = true;
        return;
    }
    if ( board[coo.first][coo.second] == 'k') return;
    if (coo.first < 1 || coo.second < 1) return;
    if (coo.first > x || coo.second > y) return;
    if (board[coo.first][coo.second] == '*') return;
    add(coo.first, coo.second, d);
}
int main()
{
    int testcases;
    cin >> testcases;
    
    while(testcases--){
        queue<pair<int, int> > q;
        hh = false;
        cin >> x >> y;
        board = vcc(x+2, vector<char>(y+2,'k'));
        visited = vcc(x+2, vector<char>(y+2, '1'));
        cout << endl;
        for (int i = 1; i <= x; ++i)
            for (int j = 1; j <= y; ++j) {
                char temp;
                cin >> temp;
                board[i][j] = temp;
            }
        
        /*for (int i = 0; i <= x +1; i++) {
            for (int j = 0; j <= y+1; j++) {
                cout << board[i][j];
            }cout << endl;
        }*/
        //cout << 111;
        pi p;
        p.first = 1;
        p.second = 1;
        dos[p] = 1;
        q.push(p);
        while (q.size()) {
            pi cord = q.front();
            if (visited[cord.first][cord.second] == '1'){
                visited[cord.first][cord.second] = '2';
                handle(cord, dos[cord]);
                if (hh == true) {
                    break;
                }
            }
            q.pop();
            
        }
        if (hh == false) {
            cout << -1;
        }
    }
}
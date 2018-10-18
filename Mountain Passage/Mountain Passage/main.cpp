//
//  main.cpp
//  Mountain Passage
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
#define fori(lim) for(int (i) = (1); (i) <= (lim);(i)++ )
#define forj(lim) for(int (j) = (1); (j) <= (lim);(j)++ )
#define fork(lim) for(int (k) = (0); (k) < (lim);(k)++ )
#define input ios::sync_with_stdio(false)
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int MAX = 1147483647;
vcc board, visited;
int orig;
vc r, c, o;
int temp, minox = MAX;
int previ = 0;

void add(int x, int y, int ox){
    if (board[x][y] == -1) {
        return;
    }
    if (abs(previ-board[x][y]) > 2) {
        return;
    }
    if (x==temp && y == temp) {
        minox = min(minox, ox);
        return;
    }
    
    r.push_back(x);
    c.push_back(y);
    o.push_back(ox);
}

void bfs(int x, int y, int ox){
    if (visited[x][y] <= ox) {
        return;
    }
    previ = board[x][y];
    visited[x][y] = ox;
    if (board[x][y] > orig || board[x+1][y] > orig) {
        add(x+1, y,ox+1);
    } else add(x+1, y,ox);
    
    if (board[x][y] > orig || board[x-1][y] > orig) {
        add(x-1, y,ox+1);
    }else add(x-1, y,ox);
    
    if (board[x][y] > orig || board[x][y+1] > orig) {
        add(x, y+1,ox+1);
    }else add(x, y+1,ox);
    
    if (board[x][y] > orig || board[x][y-1] > orig) {
        add(x, y-1,ox+1);
    }else add(x, y-1,ox);
    
    return;
}

int main(void)
{
    input;
    int num;
    cin >> num;
    
    
    while(num--) {
        cin >> temp;
        board = vcc(temp+2, vc(temp+2, -1));
        visited = vcc(temp+2, vc(temp+2, MAX));
        fori(temp){
            forj(temp){
                int x;
                cin >> x;
                board[i][j] = x;
            }
        }
        orig = board[1][1];
        r.push_back(1);
        c.push_back(1);
        o.push_back(0);
        
        for (int i = 0; i < r.size(); i++) {
            //cout << r[i] << "," << c[i] << "," << o[i] << endl;
            bfs(r[i], c[i], o[i]);
        }
        if (minox == MAX) {
            cout << "CANNOT MAKE THE TRIP" << endl;
        }
        else cout << minox << endl;
        
        r.clear();
        c.clear();
        o.clear();
        board.clear();
        visited.clear();
        minox = MAX;
        previ = 0;
        //return 0;
    }
    
}

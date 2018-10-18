//
//  main.cpp
//  WC04
//
//  Created by Siddhant Jain on 2015-12-11.
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
typedef vector<vector<char> > vcc;
typedef priority_queue<int> pq;

int MAX = 1147483647;
vcc board;
vc list;
bool help(int a, int b, int dir);
int x, y;
int sa, sb, sdir;
map<piii, set<pii> > full;
map<pair<piii,pii>, bool> ty;
vector<piii> chain;

bool dfs(int a, int b, int dir){
    //cout << "dfs: "<<a << b << dir << endl;
    
    if (board[a][b] == '.') {
        if (dir == 0) {
            if(help(a, b+1, dir)) return true;
        }
        if (dir == 1) {
            if(help(a+1, b, dir)) return true;
        }
        if (dir == 2) {
            if(help(a, b-1, dir)) return true;
        }
        if (dir == 3) {
            if(help(a-1, b, dir)) return true;
        }
    }
    if (board[a][b] == 'X') {
        if (dir == 0) {
            if(help(a, b-1, (dir + 2)%4)) return true;
        }
        if (dir == 1) {
            if(help(a-1, b, (dir + 2)%4)) return true;
        }
        if (dir == 2) {
            if(help(a, b+1, (dir + 2)%4)) return true;
        }
        if (dir == 3) {
            if(help(a+1, b, (dir + 2)%4)) return true;
        }
    }
    if (board[a][b] == '/') {
        if (dir == 0) {
            if(help(a-1, b, 3)) return true;
        }
        if (dir == 1) {
            if(help(a, b-1, 2)) return true;
        }
        if (dir == 2) {
            if(help(a+1, b, 1)) return true;
        }
        if (dir == 3) {
            if(help(a, b+1, 0)) return true;
        }
    }
    
    if (board[a][b] == '\\') {
        if (dir == 0) {
            if(help(a+1, b, 1)) return true;
        }
        if (dir == 1) {
            if(help(a, b+1, 0)) return true;
        }
        if (dir == 2) {
            if(help(a-1, b, 3)) return true;
        }
        if (dir == 3) {
            if(help(a, b-1, 2)) return true;
        }
    }
    return false;
}
bool help(int a, int b, int dir){
    //cout << "help: "<<a << b << dir << endl;
    if (a < 0 || a >= x || b < 0 || b >= y) {
        return false;
    }
    if (board[a][b] == '#') {
        return false;
    }
    if (sa == a && sb == b) {
        return true;
    }
    piii o;
    o.first =a;
    o.second.first = b;
    o.second.second = dir;
    
    pair<piii, pii> fulo;
    fulo.first = o;
    fulo.second.first = sa;
    fulo.second.second = sb;
    
    if (ty.count(fulo)) {
        return true;
    }
    piii q;
    q.first = a;
    q.second.first = b;
    q.second.second = dir;
    chain.push_back(q);
    set<pii> myset;
    
    if(dfs(a, b, dir)){
        /*
            piii qw;
            qw.first = sa;
            qw.second.first = sb;
            qw.second.second = sdir;
        
            if (full.count(o)) {
                myset = full[o];
                fori(chain.size()){
                    myset.insert(chain[i]);
                }
            }
            else {
                fori(chain.size()){
                    myset.insert(chain[i]);
                }
            }  full[qw] = myset;
        */
        for (int i = 0; i < chain.size()-1; i++) {
            for (int j = i+1; j < chain.size(); j++) {
                pair<piii, pii> sup;
                sup.first = chain[i];
                sup.second.first = chain[j].first;
                sup.second.second = chain[j].second.first;
                ty[sup] = true;
            }
            
        }
    
        return true;
    }
    return false;
    
}

int check(int a, int b){
    //cout << "check: "<<a << b << endl;
    sdir =1;
    if(help(a+1, b, 1)) return 1;
    sdir = 3;
    if(help(a-1, b, 3)) return 1;
    sdir = 0;
    if(help(a, b+1, 0))return 1;
    sdir = 2;
    if(help(a, b-1, 2)) return 1;
    
    return 0;
}

int main(void)
{
    cin >> x >> y;
    board = vcc (x, vector<char> (y, -MAX));
    fori(x) {
        forj(y){
            char temp;
            cin >> temp;
            board[i][j] = temp;
        }
    }
    int summ = 0;
    /*sa = 2;
     sb = 5;
     cout << check(2, 5, 3);*/
    fori(x) {
        forj(y){
            sa = i;
            sb = j;
            if(board[i][j] == '.') summ += check(i, j);
            
        }
    }cout << summ;
}
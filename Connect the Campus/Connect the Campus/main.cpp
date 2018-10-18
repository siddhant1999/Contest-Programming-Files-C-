//
//  main.cpp
//  Connect the Campus
//
//  Created by Siddhant Jain on 2016-02-12.
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
typedef pair<double, pair<double, double> > pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<double> > vcc;
typedef priority_queue<int> pq;

int MAX = 1147483647;
vcc board;
vc list;
vc x,y;
vector<int> f,t;
vector<double> vis;
priority_queue<pii> tovis;

void prims(void){
    while (!tovis.empty()) {
        double dist = -tovis.top().first;
        double to =tovis.top().second.first;
        double from = tovis.top().second.second;
        tovis.pop();
        if (vis[to] != -1) {
            continue;
        }
        if (dist!=0) {
            f.push_back(from);
            t.push_back(to);
        }
        
        //cout << to  << " *** " << dist << endl;
        vis[to] = dist;
        pii q;
        for (int i = 0; i < board.size(); i++) {
            
            q.first = -board[to][i];
            q.second.first = i;
            q.second.second = to;
            tovis.push(q);
            //tp(q);
        }
    }
}

int main(void)
{
    input;
    int num;
    cin >> num;
    board = vcc(num, vector<double>(num, MAX));
    vis = vector<double>(num, -1);
    
    for (int i = 0; i < num; i++) {
        int a, b;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }
    
    //0 indexed
    //find all dists
    for (int i =0; i < x.size(); i++) {
        for (int j = i; j<x.size(); j++) {
            double dist = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
            board[i][j] = dist;
            board[j][i] = dist;
        }
    }
    
    int cur;
    cin >> cur;
    forj(cur){
        int a, b;
        cin >> a >> b;
        board[a-1][b-1] = 0;
        board[b-1][a-1] = 0;
    }
    
    pii q;
    q.first = 0;
    q.second.first = 0;
    q.second.second = 0;
    
    tovis.push(q);
    prims();
    double sum = 0;
    for (int i = 1; i < vis.size(); i++) {
        //cout << vis[i] << " ";
        sum+= vis[i];
    }
    printf( "%.2f\n",sum);
    //cout << sum;
    for(int i = f.size()-1; i>=0;i--){
        //cout << f[i]+1 <<" " << t[i]+1 << endl;
    }
    
}

//
//  main.cpp
//  s3
//
//  Created by Siddhant Jain on 2016-02-17.
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


#define x0 first
#define y0 second.first
#define z0 second.second

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define mpp(one,two,three) make_pair( one,  make_pair( two, three ) )
#define tp(one) cout << (one).first << " " << (one).second << endl;
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
vcc paths;
//bool pho [100001];
vector<bool> pho (100001, false);
vector<int> vis (100001, -1);
//int vis [100001];
vc res;
int best = MAX;
//int counter = 0;
vc tovis, tocost;

int n, m;

void dfs(int index, int cost, int counter){
    if (double(clock())/CLOCKS_PER_SEC > 4.9) {
        cout << best;
        exit(0);
    }
    if (cost >= best) {
        return;
    }
    bool yep= false;
    if (vis[index] == -1) {
        vis[index] = counter;
        yep = true;
    }
    else if (counter <= vis[index]) {
        return;
    }
    //cout << index << " " << cost << " " << counter << endl;
    if (pho[index]&&yep ) {
        counter++;
        //pho[index] = false;
        if (counter == m) {
            best = min(best, cost);
        }
    }
    vis[index] = counter;
    /*if (vis[index]) {
        return;
    }
    cout << index << " " << cost << endl;
    if (pho[index]) {
        counter++;
        if (counter == m) {
            cout << cost;
            exit(0);
        }
    }*/
    
    //vis[index] = true;
    //int c= 0;
    //for (int i =rand()%paths[index].size(); c<paths[index].size(); c++) {
    for (int i = 0; i<paths[index].size(); i++) {
        dfs(paths[index][i], cost+1, counter);
    }
}

int main(void)
{
    input;
    //memset(pho, false, 100000);
    
    cin >> n >> m;
    paths = vcc(n+1);
    fori(m){
        int temp;
        cin >> temp;
        pho[temp] = true;
        res.push_back(temp);
    }
    
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    //tovis.push_back(res[0]);
    //tocost.push_back(0);
    /*for (int i =0; i < tovis.size(); i++) {
        bfs(tovis[i], tocost[i]);
    }*/
    fori(res.size()){
        //ms(vis, -1);
        //memset(vis, -1, sizeof(vis));
        dfs(res[i], 0, 0);
    }
    cout << best;
    //dfs(res[0], 0, 0);
}


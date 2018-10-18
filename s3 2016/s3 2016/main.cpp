//
//  main.cpp
//  s3 2016
//
//  Created by Siddhant Jain on 2016-02-19.
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
vector<bool> pho (100001, false), useful (100001, false), vis (100001, false);
vc res;
int best = MAX;
int farthest = 0, deepness = 0;
int n, m;

bool far(int index, int depth) {
    if (vis[index]) {
        return false;
    }
    //cout << index << " " << depth << endl;
    if (pho[index]) {
        if (depth > deepness) {
            deepness = depth;
            farthest = index;
        }
    }
    vis[index] = true;
    bool y= false;
    for (int i = 0; i<paths[index].size(); i++) {
        if(far(paths[index][i], depth+1)) y= true;
    }
    return useful[index] = useful[index] || pho[index] || y;
}

int dfs(int index, int depth){
    if (useful[index] == false || vis[index]) {
        return 0;
    }
    //cout << index << " " << depth << endl;
    if (pho[index]) {
        if (depth > deepness) {
            deepness = depth;
            farthest = index;
        }
    }
    vis[index] = true;
    int sum = 2;
    for (int i = 0; i<paths[index].size(); i++) {
        sum += dfs(paths[index][i], depth+1);
    }
    //cout << "index " << index << " depth: " << depth << " : " << sum << endl;
    return sum;
}

int main(void)
{
    input;
    
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
    far(res[0], 0);
    //cout << deepness << "    " << farthest << endl;
    deepness = 0;
    fill(vis.begin(), vis.end(), false);
    int val = dfs(farthest, 0);
    cout << (val-2) - deepness;
}

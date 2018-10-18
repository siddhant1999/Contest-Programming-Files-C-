//
//  main.cpp
//  Subsets
//
//  Created by Siddhant Jain on 2016-02-15.
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
#define ms(thing, val) memset( (thing), (val), sizeof(thing) )
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
vcc board;
vc list;
map<char, vector<char> > contains;
vector<char> c;

vector<bool> vis (26, false);

void dfs (char a){
    if (vis[a-'A']) {
        return;
    }
    vis[a-'A'] = true;
    for (int j = 0; j < contains[].size(); j++) {
        char l = contains[cars[i]][j];
        if (!isupper(l)) {
            c.push_back(l);
            continue;
        }
        dfs(c);
    }
}

int main(void)
{
    input;
    int num;
    cin >> num;
    
    vector<char > cars;
    for (int i = 0; i < num; i++) {
        char a, b;
        string str;
        cin >> a >> str >> b;
        cars.push_back(a);
        //if (isupper(b)) {
            contains[a].push_back(b);
        //}
    }
    sort(cars.begin(), cars.end());
    char cur=0;
    for (int i = 0; i < cars.size(); i++) {
        if (i == 0) {
            cur = cars[i];
            
            
            for (int j = 0; j < contains[cars[i]].size(); j++) {
                char l = contains[cars[i]][j];
                if (!isupper(l)) {
                    c.push_back(l);
                    continue;
                }
                dfs(l);
            }
        }
        if (cur == cars[i]) {
            continue;
        }
        cur = cars[i];
    }
    
}


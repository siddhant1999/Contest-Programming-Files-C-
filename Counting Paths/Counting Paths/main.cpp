//
//  main.cpp
//  Counting Paths
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
#define y0 second

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
vcc paths;
int bfsing;
int counting = 0;
int cache[101][101];
int num, k;

int getways (int node, int len){
    if (len == 0) {
        return 1;
    }
    if (cache[node][len] != -1) {
        return cache[node][len];
    }
    int sum= 0;
    fori(paths[node].size()){
        int a = paths[node][i];
        sum+= getways(a, len-1);
    }
    return cache[node][len] = sum;
}

int main(void)
{
    input;
    cin >> num >> k;
    memset(cache, -1, sizeof(cache));
    paths = vcc(num);
    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++) {
            bool a;
            cin >> a;
            if (a)
                paths[i].push_back(j);
            
        }
    int s =0;
    fori(paths.size()){
        s += getways(i, k);
    }
    cout << s;
}


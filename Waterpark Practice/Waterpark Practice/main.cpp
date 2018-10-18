//
//  main.cpp
//  Waterpark Practice
//
//  Created by Siddhant Jain on 2015-11-15.
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

int MAX = 10000;
vcc board;
vc list;
int num;
vc cache (MAX, -1);

int dp(int node){
    if (node == num) {
        return 1;
    }
    if (cache[node] != -1) {
        return cache[node];
    }
    int sum = 0;
    for (int i=0; i < board[node].size(); i++) {
        sum += dp(board[node][i]);
    }
    return cache[node] = sum;
}

int main(void)
{
    
    cin >> num;
    board = vcc (num+1);
    
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        board[a].push_back(b);
    }
    cout << dp(1);
}

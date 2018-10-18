//
//  main.cpp
//  Tower of Babylon
//
//  Created by Siddhant Jain on 2015-12-22.
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
map<pii, int> cache;

int dp(int wid, int len){
    //len is always >= wid
    pii q {wid, len};
    if(cache.count(q)){
        return cache[q];
    }
    int maxi = 0;
    for(int i = 0; i < board.size();i++){
        if(board[i][0] < wid && board[i][1] < len)
            maxi = max(dp(board[i][0], board[i][1])+board[i][2], maxi);
        
        if(board[i][1] < wid && board[i][2] < len)
            maxi = max(dp(board[i][1], board[i][2])+board[i][0], maxi);
        
        if(board[i][0] < wid && board[i][2] < len)
            maxi = max(dp(board[i][0], board[i][2])+board[i][1], maxi);
        
    }
    return cache[q] = maxi;
}

int main(void)
{
    int j = 0;
    while(true){
        int num;
        cin >> num;
        j++;
        if(!num) break;
        board = vcc(num);
        for (int i = 0; i < num; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            board[i] = {a,b,c};
            sort(board[i].begin(), board[i].end());
        }
        cache.clear();
        cout << "Case " << j << ": maximum height = " << dp(MAX, MAX) << endl;
    }
}

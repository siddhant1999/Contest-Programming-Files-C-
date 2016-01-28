//
//  main.cpp
//  Virtuoso
//
//  Created by Siddhant Jain on 2015-12-03.
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

int MAX = 2147483647;
vcc board;
vc list;
int minturns = 2147483647;

int dp(int node, int turns, int index){
    if (index >= board.size()) {
        return 0;
    }
    return 0;
}

int main(void)
{
    int num;
    cin >> num;
    board = vcc (num+1);
    
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        for (int j = 0;  j < temp; j++) {
            int t;
            cin >> t;
            board[i].push_back(t);
        }
    }
    int m = 2147483647;
    //for (int i = 0; i < board.size(); i++)
        for (int  j= 0; j < board[0].size(); j++) {
            m = min(m,dp(board[0][j], 0, 1));
        }
    
}

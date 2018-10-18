//
//  main.cpp
//  Gold 2
//
//  Created by Siddhant Jain on 2016-01-15.
//  Copyright © 2016 Siddhant Jain. All rights reserved.
//

//
//  main.cpp
//  USACO Gold 1
//
//  Created by Siddhant Jain on 2016-01-15.
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
#define input ios::sync_with_stdio(false);
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int MAX = 1147483647;
vcc board;
vc list;

int main(void)
{
    input;
   freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    
    int num;
    cin >> num;
    vc prefix;
    prefix.push_back(0);
    for (int i = 1; i <= num; i++) {
        int temp;
        cin >> temp;
        prefix.push_back((prefix[i-1] + temp)%7);
    }
    board = vcc (7, vc(2, -1));
    forj (prefix.size()) {
        if (board[prefix[j]][0] == -1) {
            board[prefix[j]][0] = j;
        }
        board[prefix[j]][1] = max(j, board[prefix[j]][1]);
    }
    int maxdiff = 0;
    fori(7){
        if (board[i][0] == -1) continue;
        maxdiff = max(maxdiff,board[i][1]-board[i][0]);
    }
    cout << maxdiff;
}
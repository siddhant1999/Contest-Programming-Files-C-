//
//  main.cpp
//  Shortest Path 5
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
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int MAX = 1147483647;
vcc board;
vc list;
int num;
vector<bool> visited;
vc cache;

int dfs(int index){
    if (index == num-1) {
        return 0;
    }
    if (visited[index]) {
        return MAX;
    }
    if (cache[index] != -1) {
        return cache[index];
    }
    int mini =MAX;
    visited[index] = true;
    for (int i =0; i < board[index].size(); i++) {
        mini = min(mini, dfs(board[index][i]));
    }
    visited[index] = false;
    
    return cache[index] = mini+1;
}

int main(void)
{
    input;
    cin >> num;
    board = vcc(num);
    visited = vector<bool>(num, false);
    cache = vector<int>(num, -1);
    for (int i = 0; i < num; i++) {
        forj(num){
            int a;
            cin >> a;
            if (a<0) {
                cout << -1;
                return 0;
            }
        }
    }
    /*for (int i = 0; i < board.size(); i++) {
        for (int j =0;j<board[i].size(); j++) {
            cout << board[i][j] << " ";
        }cout << endl;
    }*/
    cout << dfs(0);
}

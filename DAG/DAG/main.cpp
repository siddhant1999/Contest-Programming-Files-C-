//
//  main.cpp
//  DAG
//
//  Created by Siddhant Jain on 2016-02-14.
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
bool is = false;

void dfs(int index){
    if (visited[index]) {
        is = true;
    }
    
    visited[index] = true;
    for (int i =0; i < board[index].size(); i++) {
        dfs(board[index][i]);
        if (is) {
            return;
        }
    }
    visited[index] = false;
    
}

int main(void)
{
    input;
    cin >> num;
    board = vcc(num);
    visited = vector<bool>(num+1, false);
    
    for (int i = 0; i < num; i++) {
        forj(num){
            int a;
            cin >> a;
            if (a==1) {
                board[i].push_back(j);
            }
        }
    }
    fori(num){
        dfs(i);
        if (is) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
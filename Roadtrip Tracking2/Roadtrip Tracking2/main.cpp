//
//  main.cpp
//  Roadtrip Tracking2
//
//  Created by Siddhant Jain on 2016-12-15.
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
vector<bool> visited;
int done = 0;
int n, m;

void fin(void){
    cout << "Yes";
    exit(0);
}

void vis(int index){
    if (done == 2) return;
    
    if (index == n) {
        done++;
        if (done == 2) {
            fin();
        }
        return;
    }
    
        fori(board[index].size()){
            if (!visited[board[index][i]]) {
                //path.push_back(index);
                visited[index] = true;
                
                vis(board[index][i]);
            
                if (done == 2) return;
                visited[index] = false;
                //path.pop_back();
            }
        }
    
}

int main(void)
{
    input;
    
    cin >> n >> m;
    board = vcc (n+1);
    visited = vector<bool>(n+1, false);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        board[a].push_back(b);
        board[b].push_back(a);
    }
    
    vis(1);
    visited = vector<bool>(n+1, false);
    
    
    if (done == 2) {
        cout << "Yes";
    }
    else cout << "No";
    /*if (temp == path || path.empty() || temp.empty() || !done) {
        cout << "No";
    }
    else cout << "Yes";*/
    
    /*forj(path.size()){
        cout << path[j] << " ";
    }*/
}

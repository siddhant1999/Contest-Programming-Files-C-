//
//  main.cpp
//  Who is really taller?
//
//  Created by Siddhant Jain on 2016-01-30.
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
int tall, small;
vc need;
vector<bool> done;


void visit(int node){
    for (int i = 0; i < board[node].size(); i++) {
        if(!done[board[node][i]]){
            done[board[node][i]] = true;
            need.push_back(board[node][i]);
        }
    }
}

int main(void)
{
    input;
    int nodes, num;
    cin >> nodes >> num;
    board = vcc (nodes+1);
    done = vector<bool> (nodes+1, false);
    
    for (int i = 0; i < num; i++) {
        int a, b;
        cin >> a >> b;
        board[a].push_back(b);
    }
    
    cin >> tall >> small;
    need.push_back(tall);
    
    for (int i = 0; i < need.size(); i++) {
        if (need[i] == small) {
            cout << "yes";
            return 0;
        }
        visit(need[i]);
    }
    need.clear();
    need.push_back(small);
    done.clear();
    done = vector<bool> (nodes+1, false);
    
    for (int i = 0; i < need.size(); i++) {
        if (need[i] == tall) {
            cout << "no";
            return 0;
        }
        visit(need[i]);
    }
    cout << "unknown";
}
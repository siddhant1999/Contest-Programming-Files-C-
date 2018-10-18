//
//  main.cpp
//  USACO Milk 3
//
//  Created by Siddhant Jain on 2015-12-12.
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
map<pii, int> tim;
vc counter;
int main(void)
{
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);
    
    int n,m,d,s;
    cin >> n >> m >> d >> s;
    board = vcc(n+1);
    list = vc(m+1, 0);
    counter = vc(m+1, 0);
    vcc done (n+1, vc(m+1, 0));
    
    while (d--) {
        int p, m, t;
        cin >> p >> m >> t;
        board[p].push_back(m);
        if(!done[p][m])
            counter[m]++;
        pii q;
        q.first = p;
        q.second = m;
        if (tim.count(q)) {
            tim[q] = min(tim[q], t);
        }
        else tim[q] = t;
        done[p][m] = 1;
    }
    while (s--) {
        int p, w;
        cin >> p >> w;
        pii q;
        q.first = p;
        fori(board[p].size()){
            q.second = board[p][i];
            if (tim[q] < w) {
                list[board[p][i]]++;
            }
        }
    }
    int mz = 0;
    int ind = 0;
    fori(list.size()){
        if (list[i] > mz) {
            mz = list[i];
            ind = i;
        }
    }
    cout << counter[ind];
}
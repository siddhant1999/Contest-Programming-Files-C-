//
//  main.cpp
//  DMOJ 4
//
//  Created by Siddhant Jain on 2016-01-12.
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
map<int , vc> where;

int main(void)
{
    input;
    int num, kk, q;
    cin >> num >> kk >> q;
    vc prefix (num+1, 0);
    for (int i = 1; i <= num; i++) {
        int temp;
        cin >> temp;
        prefix[i] = prefix[i-1]+temp;
        if (where.count(temp)) {
            where[temp].push_back(i);
        }
        else {
            vc o = {i};
            where[temp] = o;
        }
    }
    
    for (int k =0 ; k < q; k++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        int sum = prefix[y] - prefix[x-1];
        if (sum <= kk) {
            cout<< "No" << endl;
            continue;
        }
        if (where.count(a) == 0 || where.count(b) == 0) {
            cout<< "No" << endl;
            continue;
        }
        bool c = false;
        fori(where[a].size()){
            if(c) break;
            if (where[a][i]>= x && where[a][i] <= y) {
                forj(where[b].size()){
                    if (where[b][j]>= x && where[b][j] <= y) {
                        cout << "Yes" << endl;
                        c=true;
                        break;
                    }
                }
            }
        }
        if(!c) cout << "No" << endl;
        
        
    }
}


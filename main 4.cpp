//
//  main.cpp
//  Boomerang
//
//  Created by Siddhant Jain on 2016-01-10.
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
vc x, y;

int main(void)
{
    //input;
    ifstream in("test.txt");
    
    freopen("out.txt", "w", stdout);
    
    int num;
    in >> num;
    
    
    for (int q = 1; q <= num; q++) {
        x.clear();
        y.clear();
        int n;
        in >> n;
        for (int j = 0; j < n; j++) {
            int a, b;
            in >> a >> b;
            x.push_back(a);
            y.push_back(b);
        }
        int tot = 0;
        board = vcc (n, vc(n, -1));
        
        fori(x.size()) {
            set<int> myset;
            map<int, int> occur;
            
            forj(x.size()) {
                int diff = (x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]);
                board[i][j] = diff;
                myset.insert(diff);
                if (occur.count(diff)) {
                    occur[diff]++;
                }
                else occur[diff] = 1;
            }
            for (set<int>::iterator o = myset.begin(); o != myset.end(); o++) {
                int element = *o;
                tot += ((occur[element] * occur[element]) - occur[element])/2;
            }
        }
        cout << "Case #" << q << ": " << tot << endl;
    }
}
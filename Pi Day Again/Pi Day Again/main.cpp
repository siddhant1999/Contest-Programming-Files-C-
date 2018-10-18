//
//  main.cpp
//  Pi Day Again
//
//  Created by Siddhant Jain on 2015-09-20.
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

int MAX = 1000000000;
vcc board;
vc list;
int k,n,q, sum=0;
vector<vector<vector<int > > > cache;

int pi(int left, int pos, int last){
    if (cache[left][pos][last] != -1) {
        return cache[left][pos][last];
    }
    if (left == 0 && pos == 0)
        return cache[left][pos][last] = 1;
    
    if (left == 0 || pos == 0) return cache[left][pos][last] = 0;
    
    int tot = 0;
    for (int i = last; i <= left/pos; i++) {
        tot += pi(left-i, pos-1, i);
    }
    return cache[left][pos][last] = tot;
}

int main(void)
{
   
    cin >> k >> n;
    q = k/n;
    cache = vector<vector<vector<int> > > (250, vcc(250, vc(250, -1)));
    
    for (int i = 1; i <= q; i++) {
        sum += pi(k-i, n-1, i);
    }
    cout << sum;
}

//3910071

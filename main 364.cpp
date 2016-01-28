//
//  main.cpp
//  K-based Numbers
//
//  Created by Siddhant Jain on 2015-11-15.
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

int MAX = 1000000000;
vcc board;
vc list;
int n, k;

// ways(n,z) is total of number of valid nums that have n digits, and end with z

int getways(int dig, bool zero){
    if (dig == 1 && zero) {
        return 0;
    }
    if (dig == 1 && !zero) {
        return k-1;
    }
    // x03453
    
    int total=0;
    // is zero,  xxxxx0
    if (zero) {
        total= getways(dig-1, false);
    }
    // is NOT zero,    xxxxx4
    else{
        total+= getways(dig-1, false) * (k-1);
        total+= getways(dig-1, true) * (k-1);
    }

    return total;
}

int main(void)
{
    cin >> n >> k;
    cout << getways(n, false) + getways(n, true);
    
}
    
/*
 N=4,   K=3
 
 way[18][2]
 ways(n,z) where n, d
 - - - 0
 xxx1
 xxx2
 
 xx0
 
 xx1
 
 xxx0 ->
 xx1
 xx2
 …
 
 xxx1 ->
 xx0
 xx1
 …
*/
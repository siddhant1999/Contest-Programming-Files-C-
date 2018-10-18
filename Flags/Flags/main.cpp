//
//  main.cpp
//  Flags
//
//  Created by Siddhant Jain on 2016-03-07.
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
vc list;

//1 white
//2 red
//3 blue

//  1 0 1 2 3 1



int combo(int n, int p, int pp){
    if (n==1 || n==2) {
        return 2;
    }
    if (p == 1) {
        return combo(n-1, 2, p) + combo(n-1, 3, p);
    }
    if (p == 2) {
        return combo(n-1, 1, p)+combo(n-1, 3, p);
    }
    if (p == 3) {
        if (pp == 1) {
            return combo(n-1, 2, p);
        }return combo(n-1, 1, p);
    }
    // ...
}


int main(void)
{
    input;
    int num;
    cin >> num;
    
    
    for (int i = 1; i <= num; i++) {
        combo(i);
    }
    
}


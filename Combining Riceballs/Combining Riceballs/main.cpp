//
//  main.cpp
//  Combining Riceballs
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

int bestval (int left, int right) {
    //if all of left and right can be collapsed return the greatest value
    //if it cannot return -1
    
    //lets start with equal adjacent riceballs
    
    int a, b, c, d,e;
    int curmax = 0;
    
    for (int i = left +1; i <= right; i++) {
        a = bestval(left, i-1);
        b = bestval(i, right);
        if (a == -1 || b == -1) {
            continue;
        }
        if (a == b) {
            curmax = a+b;
        }
    }
    for (int i = left; i < right-1; i++) {
        c = bestval(left, i);
        for (int j = i +2; j <= right; j++) {
            d= bestval(i+1, j-1);
            e= bestval(j, right);
            if (c==-1 || d == -1 || e ==-1) {
                continue;
            }
            if (c == e) {
                curmax = c+d+e;
            }
        }
    }
    
}

int main(void)
{
    input;
    int num;
    cin >> num;
    
    
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        list.push_back(temp);
    }
    
    
}


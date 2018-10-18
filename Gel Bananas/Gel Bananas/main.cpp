//
//  main.cpp
//  Gel Bananas
//
//  Created by Siddhant Jain on 2016-02-09.
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



int main(void)
{
    input;
    int a, b, x;
    cin >> a >> b >> x;
    int k=0;
    
    for (int i = 1; i < x; i++) {
        if (i*a > x) {
            break;
        }
        if ((a*i)%b == 0) {
            k=a*i;
            break;
        }
    }
    if (k == 0) {
        cout << 1;
        return 0;
    }
    
    int v = x/k+1;
    if (x%k == 0) {
        v--;
    }
    cout << v;
}
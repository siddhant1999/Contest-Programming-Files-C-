//
//  main.cpp
//  Sheeps and Coyotes
//
//  Created by Siddhant Jain on 2016-02-11.
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
typedef vector<double> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int MAX = 1147483647;
vcc board;
vc list;

vc x,y;

int main(void)
{
    input;
    int num;
    cin >> num;
    
    
    for (int i = 0; i < num; i++) {
        double a, b;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }
    set<int> uni;
    for (double i = 0.01; i <= 1000.00; i+= 0.01) {
        double mini = MAX;
        vector<int> minindex;
        for (int j = 0; j < num; j++) {
            double diff = (i-x[j])*(i-x[j]) + y[j]*y[j];
            if (diff < mini) {
                mini = diff;
                minindex.clear();
                minindex.push_back(j);
            }
            if (diff== mini) {
                minindex.push_back(j);
            }
        }
        fork(minindex.size())
            uni.insert(minindex[k]);
        minindex.clear();
    }
    for (set<int>::iterator i = uni.begin(); i != uni.end(); i++) {
        int element = *i;
        printf( "The sheep at (%.2f, %.2f) might be eaten.\n",x[element], y[element]);
        //cout << x[element] << " " << y[element] << endl;
    }
    //from 0,0 to 1000.00, 0
}

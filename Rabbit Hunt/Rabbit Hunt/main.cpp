//
//  main.cpp
//  Rabbit Hunt
//
//  Created by Siddhant Jain on 2016-02-06.
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
typedef vector<long double> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

#define MAX 1147483647;
vcc board;
vc x,y;


int eqline (long double a1, long double b1, long double a2, long double b2){
    
    if (a2-a1 == 0) {
        int count = 0;
        for (int i = 0; i < x.size(); i++) {
            if (x[i] == a1) {
                count++;
            }
        }
        return count;
    }
    long double m = (b2-b1)/(a2-a1);
    long double inter = b1-(m *a1);
    int count = 0;
    
    for (int i = 0; i < x.size(); i++) {
        if (x[i]*m + inter == y[i]) {
            count++;
        }
    }
    return count;
}

int main(void)
{
    input;
    int num;
    cin >> num;
    
    
    for (int i = 0; i < num; i++) {
        long double a, b;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }
    
    int totmax = 0;
    for (int i = 0; i < x.size()-1; i++) {
        int maxi = 0;
        for (int j = i+1; j < x.size(); j++) {
            maxi = max(maxi, eqline(x[i], y[i], x[j], y[j]));
        }
        totmax = max(maxi, totmax);
    }
    cout << totmax << endl;
}

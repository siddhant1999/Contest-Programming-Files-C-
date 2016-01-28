//
//  main.cpp
//  FireHydrant
//
//  Created by Siddhant Jain on 2015-07-18.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
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
int maxhy;
/*
 getHoses( d ) = min # hoses needed to cover all houses using exactly diameter d
 
 getHoses(0), getHoses(1), getHoses(2), ... getHoses( 1mill )
 7,7 ,6,6,6,6,5,5,5,4,4,4,3,3,3,3,3,3
 
 */
vc houses;

int getHoses(int d){
    int last = houses[0];
    int numhoses = 1;
    
    for (int i = 1; i < houses.size(); i++) {
        if (houses[i] - last > d) {
            last = houses[i];
            numhoses++;
        }
    }
    return numhoses;
}

// 500000/c   +   c <= 2*sqrt(500000)

int solve(void){
    int i;
    
    for (i = 0; i <= 500000; i+=500) {
        if ( getHoses(i+500) <= maxhy ){
            break;
        }
    }
    for (; i <= 500000; i+=1) {
        if ( getHoses(i) <= maxhy ){
            break;
        }
    }
    return (++i)/2;
}

int main(void)
{
    int num;
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        houses.push_back(temp);
    }
    sort(houses.begin(), houses.end());
    cin >> maxhy;
    cout << solve();
}
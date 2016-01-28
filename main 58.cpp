//
//  main.cpp
//  Feeding Frenzy
//
//  Created by Siddhant Jain on 2015-11-12.
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
vc q1,q2;
vcc cache;
int fox;
int dp(int tot, int k){
    
    if (k == fox && tot == 0) return 1;
    if (k == fox || tot <= 0) return -1;
    int sum = 0;
    if (cache[tot][k] != -1) {
        return cache[tot][k];
    }
    
    for (int i = q1[k]; i <= q2[k] ; i++) {
        int h = dp(tot-i, k+1);
        if (h > 0) {
            sum+=h;
        }
    }
    if (tot >= 0 && k < fox) {
        //cout << "dsf";
        return cache[tot][k] = sum;
    }
    return cache[tot][k] = sum;
}

int main(void)
{
    int num;
    cin >> num;
    
    while (num--) {
        int food;
        q1 = vc(0);
        q2 = vc(0);
        cache = vcc (1000, vc (1000, -1));
        cin >> fox >> food;
        for (int i = 0; i < fox; i++) {
            int x ,y;
            cin >> x >> y;
            q1.push_back(x);
            q2.push_back(y);
        }
        cout << dp(food, 0) << endl;
    }
}

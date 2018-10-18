//
//  main.cpp
//  Stock Market Again
//
//  Created by Siddhant Jain on 2016-01-07.
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

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<big_int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

big_int MAX = 1147483647;
vc list;

int main(void)
{
    big_int c;
    cin >> c;
    while (c--) {
        big_int num;
        cin >> num;
        list.clear();
        for (big_int i = 0; i < num; i++) {
            big_int temp;
            cin >> temp;
            list.push_back(temp);
        }
        big_int maxi = -MAX;
        big_int money = 0;
        
        for (big_int i = list.size()-1; i >= 0; i--) {
            maxi = max(maxi, list[i]);
            money += maxi-list[i];
        }
        cout << money << endl;
    }
}

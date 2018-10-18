//
//  main.cpp
//  Emoticons
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
vcc cache;
vc list;
int num;

int dp(int tot, int hold){
    if (tot > num) return MAX;
    if (tot == num)return 0;
    if (cache[tot][hold] != -1) return cache[tot][hold];
    if (hold == 0) return 2 + dp(tot+tot, tot);
    
    //either you paste
    // or you copy then paste
    
    int paste = dp(tot + hold, hold);
    int cp = 1 + dp(tot+tot, tot);
    return cache[tot][hold] = 1 + min(paste, cp);
}

int main(void)
{
    cin >> num;
    cache = vcc (num+1, vc (num+1, -1));
    cout << dp(1, 0);
}

//
//  main.cpp
//  Coin Change
//
//  Created by Siddhant Jain on 2015-11-06.
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
vcc cache;
int s = 0;
int dp(int left, int maxi){
    s++;
    if (left == 0) return 1;
    
    if (cache[left][maxi] != -1) return cache[left][maxi];
   
    int sum = 0;
    for (int i = maxi; i < list.size(); i++) {
        if (list[i] <= left) sum += dp(left-list[i], i);
        else break;
    }
    return cache[left][maxi] = sum;
}

int main(void)
{
    int tot,num;
    cin >> tot >> num;
    cache = vcc (tot+1, vc (num+1, -1));
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        list.push_back(temp);
    }
    sort(list.begin(), list.end());
    cout << dp(tot,0) << endl << s;
}

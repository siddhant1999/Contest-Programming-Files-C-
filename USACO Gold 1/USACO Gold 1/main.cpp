//
//  main.cpp
//  USACO Gold 1
//
//  Created by Siddhant Jain on 2016-01-15.
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
#define input ios::sync_with_stdio(false);
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int MAX = 1147483647;
vcc board;
vc list;

int binary(int low, int high, int k)
{
    //cout << low << " " << high << " "  << k << " ";
    int mid;
    while ( low <= high )
    {
        mid = (low + high) / 2;
        if ( list[mid] <= k )
            low = mid + 1;
        else
            high = mid - 1;
    }
    //cout << low << endl;
    return low;
}

int dp(int index, int r, int remain){
    //cout << index << " " << r << " " << remain << endl;
    if (remain == 0) {
        if (index != list.size()) {
            return MAX;
        }
        else return 0;
    }
    if (index == list.size()) {
        return 0;
    }
    int high = list[index] + r + r;
    int o = binary(index, int (list.size()-1), high); //index until +1
    if(o == list.size()) return o;
    else return dp(o, r, remain-1);
}

int main(void)
{
    input;
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int num, cows;
    cin >> num >> cows;
    
    
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        list.push_back(temp);
    }
    sort(list.begin(), list.end());
    for (int i = 0;; i++) {
        if(dp(0, i, cows) == list.size()) {
            cout << i;
            return 0;
        }
    }
}
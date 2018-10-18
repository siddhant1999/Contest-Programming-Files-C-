//
//  main.cpp
//  USACO Highcard 2
//
//  Created by Siddhant Jain on 2015-12-12.
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

int MAX = 1147483647;
vcc board;
vc list, mine, yours;

int binary(int low, int high, int k)
{
    int mid;
    while ( low <= high )
    {
        mid = (low + high) / 2;
        if ( mine[mid] <= k )
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}


int main(void)
{
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    int num;
    cin >> num;
    list =vc(num*2, 0);
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        temp--;
        list[temp] = 1;
        yours.push_back(temp);
    }
    
    fori(list.size()){
        if (!list[i]) {
            mine.push_back(i);
        }
    }
    int wins =0, loses = 0;
    
    fori(yours.size()){
        if (mine[mine.size()-1] > yours[i]) {
            mine.erase(lower_bound(mine.begin(), mine.end(), yours[i]));
            wins++;
        }
        else {
            loses++;
            mine.erase(mine.begin());
        }
    }
    cout << wins;
}


//
//  main.cpp
//  Super Plumber Clean
//
//  Created by Siddhant Jain on 2015-11-17.
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
typedef vector<char> vc;
typedef vector<vector<char> > vcc;
typedef priority_queue<int> pq;

int MAX = 1000000000;
vcc board;
int r,c;
vector<vector<int> > sums, cache,obstac;

int binary(int low, int high, int k, int indexofcol)
{
    int mid;
    while ( low <= high )
    {
        mid = (low + high) / 2;
        if (obstac[indexofcol][mid] == k ) return mid;//
        if (low==high) return low;
        if ( obstac[indexofcol][mid] < k )
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
int pd(int x, int y){
    if (cache[x][y] != -1) {
        return cache[x][y];
    }
    if (y > c) {
        return 0;
    }
    if (board[x][y] == '*') {
        return 0;
    }
    //index im feeding to binary search is x since only row # matters
    int ub = binary(0, (int) obstac[y].size()-1, x, y);//index of next *
    int lb = obstac[y][ub-1];
    ub = obstac[y][ub];
    if (y == c && lb != 0) {
        return -MAX;
    }
    int totsum = sums[lb][y];//this is max i can get in this vertical range
    int m = 0;
    for (int i = lb+1; i < ub; i++) {
        m = max(m, pd(i, y+1));
    }
    for (int i = lb+1; i < ub; i++) {
        cache[i][y]=m + totsum;
    }
    return totsum + m;
}
int main(void)
{
    
    cin >> r >> c;
    
    while (r != 0 && c != 0) {
        board = vcc (r+2, vc (c+2, '-'));
        sums = vector<vector<int> > (r+2, vector<int> (c+2, 0));
        cache = vector<vector<int> > (r+2, vector<int> (c+2, -1));
        obstac = vector<vector<int> > (c+1);
        
        for (int i = 0; i < obstac.size(); i++) {
            obstac[i].push_back(0);
        }
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                char temp;
                cin >> temp;
                board[i][j] = temp;
                if (temp == '*') {
                    obstac[j].push_back(i);//in column j there is an obstacle at i
                }
            }
        }
        for (int i = 0; i < obstac.size(); i++) {
            obstac[i].push_back(r+1);
        }
        for (int i = 1; i <= c; i++) {
            int index = 0;//asterisk index
            
            for (int j = 1; j <= r; j++) {
                if (board[j][i] == '*') {
                    index = j;
                }
                if (board[j][i] >= '1' && board[j][i] <= '9') {
                    sums[index][i] += board[j][i]-'0';//sum of all the values after this * but before the next *
                }
            }
        }
        cout << pd(r, 1);
        cin >> r >> c;
    }
    
}

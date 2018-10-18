//
//  main.cpp
//  Super Plumber Again
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
vector<int> list;
vector<vector<int> > obstac;
int r,c;
vector<vector<int> > sums, cache;

/*
int binary(int l, int h, int tar, int indexofcol){
    if (l==h) {
        return l;
    }
    int mid = (l + h)/2;
    if (tar == obstac[indexofcol][mid]) {
        return mid;
    }
    if (tar > obstac[indexofcol][mid]) {
        return binary(mid, h, tar, indexofcol);
    }
        return binary(l, mid-1, tar, indexofcol);
    
}
*/
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


/*int dp(int x ,int y){
    if (board[x][y] == '*') {
        return 0;
    }
    //cout << x << " " << y << endl;
    if (y == c){
        int lower_b, upper_b;
        int nxtast = binary(0, (int) obstac[y].size(), x, y);
        upper_b = obstac[nxtast][y];// index of *
        lower_b = obstac[nxtast-1][y];
        
        for (int i = x-1;; i--) {
            if (binary_search (obstac[y].begin(), obstac[y].end(), i)) {
                upper_b = i;
                break;
            }
        }
        int sum = 0;
        for (int i = upper_b+1; i <lower_b ; i++) {
            if (board[i][y] >= '1' && board[i][y] <= '9') {
                sum += board[i][y]-'0';
            }
        }
        return sum;

    }
    int lower_b, upper_b;
    for (int i = x+1;; i++) {
        if (binary_search (obstac[y].begin(), obstac[y].end(), i)) {
            lower_b = i;
            break;
        }
    }
    for (int i = x-1;; i--) {
        if (binary_search (obstac[y].begin(), obstac[y].end(), i)) {
            upper_b = i;
            break;
        }
    }
    //upper < lower
    int sum = 0;
    if (list[y] == 0) {
        int m = 0;
        for (int i = upper_b+1; i <lower_b ; i++) {
            m = max(m, dp(i, y+1));
        }
        return m;
    }
    //cout << "up: " << upper_b << " lo: " << lower_b <<endl;
    for (int i = upper_b+1; i <lower_b ; i++) {
        if (board[i][y] >= '1' && board[i][y] <= '9') {
            sum += board[i][y]-'0';
        }
    }
    int m = 0;
    for (int i = upper_b+1; i <lower_b ; i++) {
        m = max(m, dp(i, y+1));
    }
    return m + sum;
}
*/
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
    
    while (r*c) {
        board = vcc (r+2, vc (c+2, '-'));
        sums = vector<vector<int> > (r+2, vector<int> (c+2, 0));
        cache = vector<vector<int> > (r+2, vector<int> (c+2, -1));
        list = vector<int> (c+1);
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
        /*for (int i= 0; i < obstac.size(); i++) {
            cout << "i:" << i;
            for (int j =0; j < obstac[i].size(); j++) {
                cout << " " << obstac[i][j] ;
            }cout << endl;
        }*/
        for (int i = 1; i <= c; i++) {
            int index = 0;//asterisk index
            
            for (int j = 1; j <= r; j++) {
                if (board[j][i] == '*') {
                    index = j;
                }
                if (board[j][i] >= '1' && board[j][i] <= '9') {
                    sums[index][i] += board[j][i]-'0';
                }
            }
        }
        /*for (int i = 0; i < sums.size(); i++) {
            forj(sums[i].size()){
                if (sums[i][j] != 0) {
                    cout << "r: " << i << " c: " << j  << " val: " << sums[i][j] << endl;
                }
            }
        }*/
        cout << pd(r, 1);
        //cout << dp(r, 1);//row and column of SP
        cin >> r >> c;
    }
    
}

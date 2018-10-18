//
//  main.cpp
//  Candy DP
//
//  Created by Siddhant Jain on 2015-12-01.
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
typedef vector<vector<char> > vcc;
typedef priority_queue<int> pq;

int MAX = 1000000000;
vcc board;
vc cal, con;
int T;
int LIM;

// 5 4 6 4 3

char can (int index, int sum){
    
    if (index >= cal.size()) {
        return (sum==0);
    }
    
    if (sum < 0) {
        return false;
    }
    
    if (board[index][sum] != -1) {
        //cout << "LOOKUP ... i: " << index << " sum: " << sum << endl;
        return board[index][sum];
    }
    
    //cout << "solve ... i: " << index << " sum: " << sum << endl;
    for (int i = 0; i <= con[index]; i++) {
        //cout << "i::: " << i << " con "<< cal[index];
        if ( can(index+1, sum - cal[index] * i ) ){
            return board[index][sum] = 1;
        }
    }
    return board[index][sum] = 0;
}

int main(void)
{
    int n;
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; i++) {
        int calorie, count;
        cin >> count >> calorie;
        if ( count > 50 )
            count=count%32;
        total += calorie*count;
        cal.push_back(calorie);
        con.push_back(count);
    }
    T = total/2+1;
    LIM = T;
    board = vcc (n+1, vector<char> (T+1, -1));
    
    while ( T-- ){
        //cout << "T:: " << T << endl;
        char k = can( 0, T );
        if (k ==1){
            //cout << "total: " << total << " T: " << T << endl;
            int diff= total-2*T;
            cout << diff;
            return 0;
        }
    }
}


/*
 
 can( 10, 57 )
 
 T=target
 can( n, t ):
	if n > candies.size() …
 return (t==T)
 
	for copies in ( 0, c[i] ):
 if can( n+1, t+candy[n] * copies )
 return true
	return false
 
 
 total = all copies
 T=total/2
 
 while ( T— )
	if can( n, k ):
 other=total-k
 diff=k-other
 return diff
*/
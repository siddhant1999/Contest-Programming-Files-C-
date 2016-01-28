//
//  main.cpp
//  Ferry Loading
//
//  Created by Siddhant Jain on 2015-12-31.
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
typedef vector<vector<bool> > vcc;
typedef priority_queue<int> pq;

int MAX = 1147483647;
vector<vcc> board;
vc A;

/*
 lim=5000
 2500
 3000
 1000
 1000
 1500
 700
 800
 0
 
 left+right=total of first N cars
 
 while N--
    for left = 0 to lim
        if getCan( N, left )
            right=sum[N]-left
            if right<=lim:
                print N
                exit
 */

int main(void)
{
    int w;
    cin >> w;
    w*=100;
    A.push_back(0);
    while(true) {
        int temp;
        cin >> temp;
        if (temp == 0) break;
        A.push_back(temp);
    }
    int n = A.size();
    board = vector<vcc>(n, vcc(w,vector<bool>(w, false)));
    vc prefix {0};
    for(int i = 1; i < A.size(); i++){
        prefix.push_back(prefix[i-1] + A[i]);
    }
    for (int i = 0; i < prefix.size() && prefix[i] <= n; i++) {
        forj(w+1){
            board[i][w][j] = true;
            board[i][j][w] = true;
        }
    }
    
    
    for (int j = 0; j <= w; j++) {
        for (int k = 1; k <= w; k++) {
            for (int i = 1; i < n; i++) {
                if (A[i] > j && A[i] > k) {
                    continue;
                }
                
            }
        }
    }
}

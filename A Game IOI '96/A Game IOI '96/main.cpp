//
//  main.cpp
//  A Game IOI '96
//
//  Created by Siddhant Jain on 2015-12-03.
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

int MAX = 2147483647;
vcc board, sums;
vc list;

int dp(int n, int m){
    if (n == m) {
        return list[n];
    }
    if (board[n][m] != -1) {
        return board[n][m];
    }
    int x =(sums[n][m] - dp(n+1, m));//take left
    int y = (sums[n][m] - dp(n, m-1));//take right
    return board[n][m] = max(x,y);
}

int main(void)
{
    int num;
    cin >> num;
    int sum = 0;
    board = vcc (num+1, vc (num+1, -1));
    sums = vcc (num+1, vc (num+1, 0));
    
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        list.push_back(temp);
        sum += temp;
    }
    for (int i = 0;  i < num; i++) {
        for (int j = i; j < num; j++) {
            if (j == 0) {
                sums[i][j] = list[i];
                continue;
            }
            sums[i][j] = sums[i][j-1] + list[j];
        }
        
    }
    /*for (int i = 0;  i < num; i++) {
        for (int j = 0; j < num; j++) {
            cout << sums[i][j] << " ";
        }
        cout << endl;
    }*/
    int x = dp(0, num-1);
    cout << x << " " << sum-x << endl;
}
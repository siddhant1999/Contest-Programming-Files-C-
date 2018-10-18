//
//  main.cpp
//  Wireless Again
//
//  Created by Siddhant Jain on 2016-02-14.
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
#include <iomanip>
#include <ctime>
using namespace std;
//board = vcc (num+1, vc (num+1, 0));


#define x0 first
#define y0 second.first
#define z0 second.second

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
#define input ios::sync_with_stdio(false)
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int MAX = 1147483647;

vc list;

int main(void)
{
    input;
    int r, c, k;
    cin >> r >> c >> k;
    int board[r+1][c+1];
    memset(board, 0, sizeof(board));
    
    for (int i = 0; i < k; i++) {
        int a, b, rad, bit;
        cin >> b >> a >> rad >> bit;
        for (int j = -rad; j <= rad; j++) {
            if (a+j <= 0) {
                continue;
            }
            if (a+j>r) {
               break;
            }
            
            int minop = sqrt(rad*rad - j*j);//remember converting double to int
            int minindex = b-minop;
            int maxindex = b+minop+1;
            if (minindex > 0 && minindex <=c) {
                board[j+a][minindex] += bit;
            }else board[j+a][1] += bit;
            if (maxindex > 0 && maxindex <=c) {
                board[j+a][maxindex] -= bit;
            }
        }
    }
    
    int totcot = 0;
    int maxi = -1;
    for (int i = 1; i <= r; i++) {
        int sum= 0;
        for (int j = 1; j <= c; j++) {
            //cout <<board[i][j] << " ";
            sum+= board[i][j];
            if (sum == maxi) {
                totcot++;
            }
            if (sum > maxi) {
                maxi = sum;
                totcot =1;
            }
        }//cout << endl;
    }
    cout << maxi << endl<<totcot;
}

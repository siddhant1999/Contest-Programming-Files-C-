//
//  main.cpp
//  Wireless
//
//  Created by Siddhant Jain on 2016-02-12.
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
vcc board;
vc list;
vc a,b,radius, brate;

int main(void)
{
    input;
    int r, c, num;
    cin >> r >> c >> num;
    
    board = vcc(r,vc(c, 0));
    
    int maxi = 0;
    int cot = 0;
    for (int i = 0; i < num; i++) {//max num is 1000
        
        int x,y,val, bit;
        cin >> y >> x >> val >> bit;
        x--;
        y--;
        
        //cout << x << " " << y << endl;
        for (int j = - val; j <= val; j++) {//30000
            if (x+j < 0 || x+j>=r) {
                continue;
            }
            int l = sqrt((val*val-j*j));
            
            for (int k = -l; k <= l; k++) {//30000
                if (y+k < 0 || y+k>=c) {
                    continue;
                }
                board[j+x][k+y]+=bit;
                if (maxi == board[j+x][k+y]) {
                    cot++;
                }
                else if (board[j+x][k+y] > maxi){
                    maxi = board[j+x][k+y];
                    cot = 1;
                }
            }
        }
    }
    cout << maxi << endl << cot << endl;
}

//
//  main.cpp
//  Pennies in a Ring
//
//  Created by Siddhant Jain on 2016-02-05.
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

#define MAX 1147483647;

int main(void)
{
    input;
    int num;
    cin >> num;
    
    
    while (num!=0) {
        int rad = num*num;
        //vcc board (num+1, vc (num+1, 0));
        int j = 1;
        int count = 0;
        for (int i = 1; i<num && i*i + j*j <= rad; i++) {
            //count += int( sqrt( r^2-x^2 ));
            
            for (int j = 1; j<num && i*i + j*j <= rad; j++) {
                count++;
            }
        }
        cout << count*4 + 4*num + 1<< endl;
        /*fori(board.size()){
            forj(board[i].size()){
                cout << board[i][j];
            }cout << endl;
        }*/
        cin >> num;
    }
}

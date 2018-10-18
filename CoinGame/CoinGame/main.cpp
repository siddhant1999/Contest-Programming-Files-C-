//
//  main.cpp
//  Template
//
//  Created by Siddhant Jain on 2015-08-24.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
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

int MAX = 1000000000;
vcc board;
vector<vector<int> > cache (10000, vector<int> (10000, -1));

bool isWinning(int left, int take){
    //cout << left << " " << take << endl;
    if(left < 1) return false;
    //if (left <= 2*take) return true;
    if (cache[left][take] != -1) return cache[left][take];
    for(int i = 1; i <= 2*take; i++){
        if(!isWinning(left-i, i)) return cache[left][take] = true;
    }
    return cache[left][take] = false;
}

int main(void)
{
    int num;
    //cin >> num;
    num = 600;
    //determine winning or lossing
    //start recursion
    int j = 0;
    if(isWinning(num, 1)) cout << "program goes first" << endl;
    else cout << "user goes first" <<endl;
    
    /*for (int i = 0; i < num; i++) {
        if (cache[i][1] == 0) {
            //cout << i << " " <<i-j << endl;
            cout << i << endl;
            if (i-j == 3) {
            //    cout << 1 << " ";
            }
            if (i-j == 2) {
              //  cout << 0 << " ";
            }
            j = i;
        }
    }*/
        //cout << i << " " << cache[i][1] << endl;
    
}

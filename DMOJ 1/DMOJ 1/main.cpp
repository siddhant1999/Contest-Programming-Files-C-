//
//  main.cpp
//  DMOJ 1
//
//  Created by Siddhant Jain on 2016-01-12.
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
#define fori(lim) for(int (i) = (1); (i) < (lim);(i)++ )
#define forj(lim) for(int (j) = (0); (j) < (lim);(j)++ )
#define fork(lim) for(int (k) = (0); (k) < (lim);(k)++ )
#define input ios::sync_with_stdio(false);
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<string> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int MAX = 1147483647;
vcc board;
vc list;

int main(void)
{
    input;
    int num;
    cin >> num;
    
    
    for (int i = 0; i < num; i++) {
        string temp;
        cin >> temp;
        list.push_back(temp);
    }
    sort(list.begin(), list.end());
    cout << list[0];
    fori(list.size()){
        if (list[i][0] == list[i-1][0]) {
            cout << ", " << list[i];
        }else cout << endl << list[i];
    }
}
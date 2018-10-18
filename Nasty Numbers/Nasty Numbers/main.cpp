//
//  main.cpp
//  Nasty Numbers
//
//  Created by Siddhant Jain on 2015-12-24.
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

int MAX = 1147483647;
vcc board;
vc list;

int main(void)
{
    int num;
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        map<int, int> diff, sum;
        bool k = false;
        for (int j = 1; j*j < temp; j++) {
            if (temp%j == 0) {
                int f1 = temp/j;
                int f2  = j;
                if (sum.count(abs(f1-f2))) {
                    cout << temp << " is nasty" << endl;
                    k = true;
                    break;
                }
                if (diff.count(f1+f2)) {
                    cout << temp << " is nasty" << endl;
                    k = true;
                    break;
                }
                diff[abs(f1-f2)] = 1;
                sum[f1+f2] = 1;
            }
        }
        if(!k) cout << temp << " is not nasty" << endl;
    }
}

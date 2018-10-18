//
//  main.cpp
//  Double Knockout Competition
//
//  Created by Siddhant Jain on 2015-11-18.
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

int MAX = 1000000000;
vcc board;
vc list;

int main(void)
{
    int num;
    cin >> num;
    
    while(num--) {
        int ud;
        cin >> ud;
        int od = 0;
        int el = 0;
        int i;
        for ( i = 0; ; i++) {
            
            cout << "Round "<<i <<": " << ud << " undefeated, " << od << " one-loss, " << el << " eliminated" << endl;
            if (ud == 0 && od== 0) {
                break;
            }
            if ((ud == 1 && od == 0) || (ud == 0 && od == 1)) {
                break;
            }
            if (ud ==1 &&  od == 1) {
                ud = 0;
                od = 2;
            }
            else {
                int nud = ud/2;
                int nod = od/2;
                int udif = ud - nud;//this many remain victorious
                int odif = od - nod;
                od = odif + nud;
                ud = udif;
                el += nod;
            }
        }
        cout << "There are " << i << " rounds." << endl;
    }
}

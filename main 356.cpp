//
//  main.cpp
//  Raucous Rockers
//
//  Created by Siddhant Jain on 2015-12-06.
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
vcc board;
vc songs;

int num,t,cds;
//return min ommited
int dp(int index, int cdsleft, int spaceleft){
    if (cdsleft == 0) {
        return num-index;
    }
    if (index == num) {
        return 0;
    }
    int minimize = MAX;
    if (spaceleft >= songs[index]) {
        int op1 = dp(index+1, cdsleft-1, t);
        int op2 = dp(index+1, cdsleft, spaceleft-songs[index]);
        minimize = min(op1, op2);
    }
    
    minimize = min(minimize,dp(index+1, cdsleft, spaceleft)+1);
    return minimize;
}

int main(void)
{
    
    cin >> num >> t >> cds;
    
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        songs.push_back(temp);
    }
    
    cout << dp(0,cds,t);
    
    //3 options
    /*
     Either you take song[i] and nothing more, take song[i] and more songs, or omit song[i]
     
     1: totcds += 1
        ommited stays the same
        i++
        spaceleft = time
     
     2: ommited stays the same
        spaceleft -= song[i]
        i++
     
     3: ommited += 1
        spaceeleft stays the same
        i++
     */
}
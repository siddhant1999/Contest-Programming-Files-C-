//
//  main.cpp
//  Bridge Crossing Practice
//
//  Created by Siddhant Jain on 2016-02-16.
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
vc board;
vc list;
vector<string> myname;
int m, num;
int cache [101];

int dp(int index){
    if (index >= num) {
        return 0;
    }
    if (cache[index]!=-1){
        return cache[index];
    }
    int mini= MAX;
    int maxindex = -1;
    int mtime= 0;
    for (int i = 0; i < m && i+index < num; i++) {
        mtime = max(mtime, list[index+i]);
        int val = index + i;
        int kk = dp(val+1) + mtime;
        if (kk<mini) {
            mini = kk;
            maxindex = val;
        }
    }
    board.push_back(maxindex);
    return cache[index] = mini;
}

int main(void)
{
    input;
    memset(cache, -1, sizeof(cache));
    cin >> m >> num;
    
    
    for (int i = 0; i < num; i++) {
        int temp;
        string name;
        cin >> name >> temp;
        list.push_back(temp);
        myname.push_back(name);
    }
    cout << dp(0) << endl;
    fori(board.size()){
        cout << board[i] << " ";
    }
}


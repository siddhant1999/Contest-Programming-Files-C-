//
//  main.cpp
//  Bicolored Horses
//
//  Created by Siddhant Jain on 2015-12-09.
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

int MAX = 147483647;
vcc cache;
vc list, pre;
int num, stables;

int unhapp(int x, int y){
    return (pre[y+1] - pre[x]) * (y-x+1 - (pre[y+1] - pre[x]));
}

// 1 1 0 1 0 1 1 1 0 1 0 1
// 1 2 2 3 3 4 5 6 6 7 7 8 = pre[]


// min total unhappiness to partition [0,1,2,3... i-1,i,...right] into k stables
int best(int right, int k){
    if (k == 1) {
        return unhapp(0, right);
    }
    if (right < 0) {
        return MAX;
    }
    if (cache[right][k] != -1) {
        return cache[right][k];
    }
    
    int mini = MAX;
    for (int i = 0; i <= right; i++) {
        mini = min(unhapp(i, right) + best(i-1, k-1),mini);
    }
    return cache[right][k] = mini;
}

int main(void)
{
    
    cin >> num >> stables;
    pre.push_back(0);
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        list.push_back(temp);
        pre.push_back(pre[pre.size()-1] + temp);
    }
    cache = vcc (num+1, vc (stables+1, -1));
    cout << best(list.size()-1, stables);
    
}

/*
 best( right_person )

 1 1 0 1 0 1
 unhapp(left, right) + happy(right, list.size()-1);
 
 
 

*/
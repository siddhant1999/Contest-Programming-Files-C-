//
//  main.cpp
//  Segment Trees Practice
//
//  Created by Siddhant Jain on 2016-05-12.
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
vcc board;
vc list;

vc segment;
vc inp;

const int MAXN=1<<17;
int SegTree[2*MAXN];

void maketree(int low, int high, int pos){
    if(low==high){
        segment[pos] = inp[low];
    }
    int mid = (low+high)/2;
    maketree(low, mid, 2*pos +1);
    maketree(mid, high, 2*pos +2);
    segment[pos] = min(segment[2*pos+1], segment[2*pos+2]);
}

int main(void)
{
    input;
    int num;
    cin >> num;
    int size;
    
    if ((num & (num - 1)) == 0) {
        size = (2 << (32-__builtin_clz(num)-1))-1;
    }
    else size= (2 << ((32-__builtin_clz(num))))-1;
    
    segment = vc(size, MAX);
    
    //cout << size;
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        inp.push_back(temp);
    }
    
    
}


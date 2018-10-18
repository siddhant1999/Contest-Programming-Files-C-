//
//  main.cpp
//  2017s1
//
//  Created by Siddhant Jain on 2017-02-22.
//  Copyright © 2017 Siddhant Jain. All rights reserved.
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


#define f0 first
#define s0 second
#define sf0 second.first
#define ss0 second.second

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


int main(void)
{
    input;
    int num;
    cin >> num;
    
    vector<int> pre;
    pre.push_back(0);
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        pre.push_back(pre[pre.size()-1]+temp);
        
    }
    int sum =0;
    int cur = 0;
    
    for (int i = 1; i <= num; i++) {
        int temp;
        cin >> temp;
        sum+= temp;
        if (sum == pre[i]) {
            cur = i;
        }
    }
    cout << cur;
}

//
//  main.cpp
//  Balance
//
//  Created by Siddhant Jain on 2015-12-27.
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
int sum;

int dp(int index, int cursum){
    if (cursum == sum) {
        return 0;
    }
    if (cursum>sum) {
        return MAX;
    }
    if (index == list.size()) {
        return abs(sum-cursum);
    }
    
    //either you take this num or not
    
    int a = dp(index+1, cursum+list[index]);
    int b = dp(index+1, cursum);
    return min(a,b);
}

int main(void)
{
    int num;
    cin >> num;
    int totsum = 0;
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        list.push_back(temp);
        totsum+= temp;
    }
    sum = totsum/2;
    cout << (totsum - (sum-dp(0,0)))-(sum-dp(0,0));//reps sum-what we took
    
}

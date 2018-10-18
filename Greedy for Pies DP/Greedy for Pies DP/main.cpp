//
//  main.cpp
//  Greedy for Pies DP
//
//  Created by Siddhant Jain on 2016-01-16.
//  Copyright © 2016 Siddhant Jain. All rights reserved.
//

//
//  main.cpp
//  Maximum Sum
//
//  Created by Siddhant Jain on 2014-07-23.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
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
#define input ios::sync_with_stdio(false);
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef pair< pair<int, int >, pair<int, bool > > pib;
typedef priority_queue<int> pq;

int MAX = 999999999;
vector<int> orig, add;
map<pib, int> cache;

int remain(int l, int r, bool bef){
    int sum = 0;
    int mid;
    
    if ((r-l)%2 || bef) mid = (l+r)/2 + 1;
    else mid = (l+r)/2;
    
    for (; mid <= r; mid++) {
        sum+= add[mid];
    }
    return sum;
}
map<int , int> ca;

int maxsum(int id){
    //cout << id << endl;
    if (ca.count(id)) {
        return ca[id];
    }
    if (id > (orig.size()-1)) {
        return 0;
    }
    int a = orig[id] + maxsum(id+2);
    int b = maxsum(id+1);
    return ca[id] = max(a,b);
}


int dp(int index, int left, int right, bool prev){
    //cout << index << " " << left << " " << right << " " << prev << endl;
    int a = -1, b = -1,c =-1,d =-1;
    pib q;
    q.first.first = index;
    q.first.second = left;
    q.second.first = right;
    q.second.second = prev;
    
    if (cache.count(q)) {
        return cache[q];
    }
    if (left>right) {
        if (prev)
            return cache[q] = maxsum(index+1);
        
        else return cache[q] = maxsum(index);
    }
    if (index == orig.size()) {
        return cache[q] = remain(left, right, prev);
    }
    
    if (prev) {
        a = dp(index+1, left, right, false);
        b = dp(index, left+1, right, false);
        return cache[q] = max(a,b);
    }
    else {
        c = dp(index+1, left, right, true) + orig[index];
        d = dp(index, left, right-1, true) + add[right];
        return cache[q] = max(c,d);
    }
    
}

int main(void)
{
    int n, m;
    cin >> n;
    
    while (n--) {
        int temp;
        cin >> temp;
        orig.push_back(temp);
    }
    cin >> m;
    while (m--) {
        int temp;
        cin >> temp;
        add.push_back(temp);
    }
    if (!n&&!m) {
        cout << 0 << endl;
        return 0;
    }
    sort(all(add));
    cout << dp(0, 0, int (add.size()-1), false) << endl;
    
}

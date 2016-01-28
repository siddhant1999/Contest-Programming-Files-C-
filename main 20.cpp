//
//  main.cpp
//  Lazy Fox DP
//
//  Created by Siddhant Jain on 2015-11-21.
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
typedef vector<pii> vp;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int MAX = 1000000000;
vcc board;
vc list;
//map<pii, int> cache;
vcc cache;
vector<bool> visited;
vector< vp> sorting;
vc a1,b1;
int jump;
int tries=20;

int best(int n, int k){
    
    if (cache[n][k] != -1) {
        return cache[n][k];
    }
    int maxi = 0;
    
    for (int i = 1; i < sorting[n].size(); i++) {
        if (n == sorting[n][i].second) continue;
        if(sorting[n][i].second == 0) continue;
        if (sorting[n][i].first < board[n][k]) {
            maxi = max(maxi, best(sorting[n][i].second, n));
        }
        else break;
    }
    
    /*
    // 1 3 5 8 9 11 22 33 44
    int i;
    
    for ( i= 1; i+jump < sorting[n].size(); i+= jump) {
        if (sorting[n][i+jump].first >= board[n][k])
            break;
    }
    
    for ( ; i < sorting[n].size(); i++ ) {
        if (sorting[n][i].first >= board[n][k])
            break;
    }
    i--;
    
    int cur_tries=0;
    cout<<n << " " << k << i << endl;
    for (; i > 0; i--) {
        if (n == sorting[n][i].second) continue;
        if(sorting[n][i].second == 0) continue;
     
        cur_tries++;
        if ( cur_tries>tries ) break;
     
        if (sorting[n][i].first < board[n][k]) {
            maxi = max(maxi, best(sorting[n][i].second, n));
        }
        else break;
    }*/
    
    
    return cache[n][k] = 1+maxi;
}

int main(void)
{
    int num;
    cin >> num;
    board = vcc (num+1, vc (num+1, 0));
    sorting=vector< vector<pii> > (num+1, vp(num+1));
    cache = vcc (num+1, vc (num+1, -1));
    a1.push_back(0);
    b1.push_back(0);
    for (int i = 0; i < num; i++) {
        int a, b;
        cin >> a >> b;
        
        a1.push_back(a);
        b1.push_back(b);
    }
    
    for (int i = 0; i < a1.size(); i++) {
        for (int j = i+1; j < a1.size(); j++) {
            int temp = (a1[i]-a1[j])*(a1[i]-a1[j]) + (b1[i]-b1[j])*(b1[i]-b1[j]);
            pii q (temp, j);
            pii p (temp, i);
            sorting[i][j] = q;
            sorting[j][i] = p;
        }
    }
    jump = int (sqrt(sorting[1].size())) + 1;
    
    fori(sorting.size()){
        sort(sorting[i].begin(), sorting[i].end());
        //forj(sorting[i].size()) cout << '('<<sorting[i][j].first << ", " << sorting[i][j].second << ") ";
        //cout << endl;
    }
    int maxi = 0;
    for (int i = 1; i < sorting[0].size(); i++) {
        cout << best(i, 0) << endl;
        maxi = max(best(sorting[i].second, 0), maxi);
        
    }
    cout << maxi-1;
    
}

//
//  main.cpp
//  Is Bigger Smarter
//
//  Created by Siddhant Jain on 2015-12-23.
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
vector<piii> list;
map<int, vc> cache; //int lookup[1001];

vc dp(int index){
    int origiq = list[index].second.first;
    long maxi = 0;
    if (cache.count(index)) {
        return cache[index];
    }
    board = vcc(list.size());
    vc big{};
    for (int i = index+1; i < list.size(); i++) {
        if(list[i].second.first < origiq){
            vc temp = dp(i);
            if(temp.size() > maxi){
                maxi = temp.size();
                big = temp;
            }
        }
    }
    big.push_back(list[index].second.second);
    return cache[index] = big;
}

int main(void)
{
    int num;
    cin >> num;
    
    for (int i = 1; i <= num; i++) {
        int w, iq;
        cin >> w >> iq;
        piii p {w,{iq,i}};
        list.push_back(p);
    }
    sort(list.begin(), list.end());
    long maxi = 0;
    vc big{};
    fori(list.size()){
        vc temp = dp(i);
        if(temp.size() > maxi){
            maxi = temp.size();
            big = temp;
        }
    }
    cout << maxi << endl;
    for (long i = big.size()-1; i >= 0; i--) {
        cout << big[i] << endl;
    }
}

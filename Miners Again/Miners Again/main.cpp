//
//  main.cpp
//  Miners Again
//
//  Created by Siddhant Jain on 2015-11-16.
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
typedef vector<char> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int MAX = 1000000000;
vcc board;
vc list;
vector<char> a, b;
map<vector<int>, int> cache;
map<char, int> lab;


string food;

int value(char p, char x1, char x2){
    set<char> myset;
    myset.insert(p);
    myset.insert(x1);
    myset.insert(x2);
    
    int sum =0;
    for (set<char>::iterator i = myset.begin(); i != myset.end(); i++) {
        char element = *i;
        if (element != 'x') {
            sum += 1;
        }
        
    }
    return sum;
}

int dp(char a1, char a2, char b1, char b2, int q){
    //lets make its cache vec
    vector<int> myv;
    myv.push_back(lab[a1]);
    myv.push_back(lab[a2]);
    myv.push_back(lab[b1]);
    myv.push_back(lab[b2]);
    myv.push_back(q);
    
    
    if (q == food.size()) {
        return cache[myv] = 0;
    }
    if (cache.count(myv) > 0) {
        return cache[myv];
    }
    if (a1 == b1 && a2 == b2) {
        a.push_back(food[q]);
        int w =value(food[q], a1, a2)+dp(a2, a[a.size()-1], b1, b2, q+1);
        a.pop_back();
        return cache[myv] = w;
    }
    int asd = value(food[q], a1, a2);
    int bsd = value(food[q], b1, b2);
    
    if (q == food.size()-1) {
        return cache[myv] = max(asd, bsd);
    }
    a.push_back(food[q]);
    int abc= dp(a2, a[a.size()-1], b1, b2, q+1);
    a.pop_back();
    b.push_back(food[q]);
    int bac = dp(a1, a2, b2, b[b.size()-1], q+1);
    b.pop_back();
    
    return cache[myv] =  max(asd + abc, bsd + bac);
}

int main(void)
{
    int num;
    cin >> num >> food;
    lab['M'] = 0;
    lab['B'] = 1;
    lab['F'] = 2;
    
    a.push_back('x');
    a.push_back('x');
    b.push_back('x');
    b.push_back('x');
    
        cout << dp('x', 'x', 'x', 'x', 0);
    
 
}

//
//  main.cpp
//  s1 2016
//
//  Created by Siddhant Jain on 2016-02-19.
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
//map<char, int> abc;

vc p (27, 0);
int ast = 0;

int main(void)
{
    input;
    string a, b;
    cin >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    fori(a.length()){
        p[a[i]-'a']++;
    }
    fori(b.length()){
        if (b[i] == '*') {
            ast++;
            continue;
        }
        p[b[i]-'a']--;
        if (p[b[i]-'a'] < 0) {
            cout << 'N';
            return 0;
        }
        //if ever less than 0 return N
    }
    int c =0;
    fori(p.size()){
        c+=p[i];
    }
    
    if (ast != c) {
        cout << 'N';
    }
    else cout << 'A';
}


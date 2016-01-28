//
//  main.cpp
//  Post
//
//  Created by Siddhant Jain on 2015-10-05.
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

int MAX = 1000000000;
vcc board;
vector<string> a1,b2;
int m, n;

vc order;
bool u = true;
void recurse(int num, string a, string b){
    if (!u) {
        return;
    }
    if (a == b && a != "") {
        //cout << a << endl;
        u=false;
        cout << order.size() << endl;
        for (int i = 0; i < order.size(); i++) {
            cout << order[i] << endl;
        }
        return;
    }
    if (num >= m) {
        return;
    }
    for (int i = 0; i < a1.size(); i++) {
        string p = a + a1[i];
        string q = b + b2[i];
        int least = min(p.length(), q.length());
        if (p.substr(0, least) == q.substr(0, least)) {
            order.push_back(i+1);
            recurse(num+1, p, q);
            order.pop_back();
        }
    }
}

int main(void)
{
    
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        a1.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        string b;
        cin >> b;
        b2.push_back(b);
    }
    
    recurse(0, "", "");
    if (u) {
        cout << "No solution." << endl;
    }
}

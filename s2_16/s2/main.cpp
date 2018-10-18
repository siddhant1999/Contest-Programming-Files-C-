//
//  main.cpp
//  s2
//
//  Created by Siddhant Jain on 2016-02-17.
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
vc a,b;
bool myfunc(int i, int j) {
    return j<i;
}

int main(void)
{
    input;
    int n, num;
    cin >> n >> num;
    
    
    for (int i = 0; i < num; i++) {
        int t, p;
        cin >> t >> p;
        a.push_back(t);
        b.push_back(p);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int totsum = 0;
    
    if (n==1) {
        sort(b.begin(), b.end());
        for (int i = 0; i < a.size(); i++) {
            totsum+= max(a[i],b[i]);
            //cout << a[i] << " "<< b[i] << endl;
        }
        cout << totsum;
    }
    else {
        sort(b.begin(), b.end(), myfunc);
        for (int i = 0; i < a.size(); i++) {
            totsum += max(a[i], b[i]);
        }
        cout << totsum;
    }
    
}

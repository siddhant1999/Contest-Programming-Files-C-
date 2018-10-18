//
//  main.cpp
//  q1
//
//  Created by Siddhant Jain on 2016-03-08.
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
set<int> lm, ln;

map<int , vc > x, y;
vc q,w;


int sbinary(int low, int high, int k, int xs)
{
    int mid;
    while ( low <= high )
    {
        mid = (low + high) / 2;
        if (y[xs][mid] == k ) return mid;//
        if (low==high) return low;
        if ( y[xs][mid] < k )
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int binary(int low, int high, int k, int ys)
{
    int mid;
    while ( low <= high )
    {
        mid = (low + high) / 2;
        if (x[ys][mid] == k ) return mid;//
        if (low==high) return low;
        if ( x[ys][mid] < k )
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}//upper bound

big_int howm (int xs, int ys){
    big_int abc = binary(0, x[ys].size()-1, xs, ys);
    big_int cde = sbinary(0, y[xs].size()-1, ys, xs);
    //returns index of xs in x[ys]
    //left and bottum
    big_int totlb = abc*cde;
    if (totlb == 0) {
        return 0;
    }
    totlb *= (x[ys].size() - abc -1) * (y[xs].size()-cde-1);
    return totlb;
}

int main(void)
{
    input;
    int num;
    cin >> num;
    
    
    for (int i = 0; i < num; i++) {
        int a, b;
        cin >> a >> b;
        x[a].push_back(b);
        y[b].push_back(a);
        
        q.push_back(a);
        w.push_back(b);
        lm.insert(a);
        ln.insert(b);
        
    }
    for (set<int>::iterator i = lm.begin(); i != lm.end(); i++) {
        int element = *i;
        sort(x[element].begin(), x[element].end());
    }
    for (set<int>::iterator i = ln.begin(); i != ln.end(); i++) {
        int element = *i;
        sort(y[element].begin(), y[element].end());
    }
    
    big_int sum =0;
    
    for (int i = 0;  i < q.size(); i++) {
        sum += howm(w[i], q[i]);
    }
    cout << sum*2;
}


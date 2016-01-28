//
//  main.cpp
//  USACO COW
//
//  Created by Siddhant Jain on 2015-02-23.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
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
#define tpp(one) cout << (one).first << " " << (one).second.first << " " << (one).second.second << endl;
#define ms(thing, val) memset( (thing), (val), sizeof(thing) )
#define mt make_tuple
#define fori(lim) for(long long (i) = (0); (i) < (lim);(i)++ )
#define forj(lim) for(long long (j) = (0); (j) < (lim);(j)++ )
#define fork(lim) for(long long (k) = (0); (k) < (lim);(k)++ )

typedef pair<long long, long long> pii;
typedef pair<long long, pair<long long, long long> > piii;
typedef vector<long long> vc;
typedef vector<vector<long long> > vcc;

vc c,o,w;
long long num;
string str = "";
long long cache[300][100009];

long long binary(long long low, long long high, long long k, char which)
{
    if (which == 'O') {
        if (o[high] < k) {
            return -1;
        }
        long long  mid;
        while ( low <= high )
        {
            mid = (low + high) / 2;
            if (o[mid] == k )return mid;
            if (low==high) return low;
            if ( o[mid] < k )
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
    else if (which == 'W'){
        if (w[high] < k) {
            return -1;
        }
        long long mid;
        while ( low <= high )
        {
            mid = (low + high) / 2;
            if (w[mid] == k ) return mid;//
            if (low==high) return low;
            if ( w[mid] < k )
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
    return -5;
}

long long dp (char x , long long index){
    long long sum = 0;
    if (index >= num) {
        return 0;
    }
    if (x == 'O') {
        long long pp = binary(0, (o.size()-1), index, 'O');
        if(pp< 0) return 0;
        
        
        for (long long i = pp; i < o.size(); i++) {
                sum += dp('W', o[i]+1);
            }
        }
    if (x == 'W') {
        long long qq = binary(0,  (w.size()-1), index, 'W');
        if(qq< 0) return 0;
        return w.size() - qq;
        
    }
        return sum;
    }
int main(void) {
    freopen("cow.in", "r", stdin);
    freopen("cow.out", "w", stdout);
    
    cin >> num;
    for (long long i = 0; i < num; i++) {
        char temp;
        cin >> temp;
        str += temp;
        if (temp == 'C') c.push_back(i);
        else if (temp == 'O') o.push_back(i);
        else if (temp == 'W') w.push_back(i);
        
    }
    
    long long sum = 0;
    for (long long i = 0; i < c.size(); i++) {
            sum += dp('O', i+1);
    }
    cout << sum;
}
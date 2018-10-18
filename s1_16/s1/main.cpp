//
//  main.cpp
//  s1
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
#define fori(lim) for(; (i) < (lim);(i)++ )
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
vc list;


int main(void)
{
    input;
    string a, b;
    cin >> a >> b;
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a==b) {
        cout << 'A';
        return 0;
    }
    if (a.length() != b.length()) {
        cout << 'N';
        return 0;
    }
    int n=0;
    int i  =0;
    fori(b.length()){
        if (b[i] == '*') {
            n++;
        }
        else break;
    }
    //cout << i << " "<< n << endl;
    //cout <<a<<endl <<b << endl;
    //int bcount = i;
    
    for(int j = 0; j < a.length(); j++){
        //cout << a[j] << " " << b[i] << endl;
        if (b[i] == a[j]) {
            i++;
            if (i == b.size()) {
                break;
            }
            continue;
        }
        
        if (b[i] != a[j]) {
            if (n<0) {
                cout <<'N';
                return 0;
            }
            n--;
            continue;
        }
    }
    if (n==0) {
        cout << 'A';
        return 0;
    }
    cout << 'N';
}


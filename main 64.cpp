//
//  main.cpp
//  Segment Trees
//
//  Created by Siddhant Jain on 2015-10-27.
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
vector<int> tree;

int MAX = 1000000000;
vcc board;
vc list;

int build(int val, int n, int m){
    if (n == m) {
        return tree[val] = list[n];
    }
    int mid = (n+m)/2;
    int sum =0;
    sum += build(val*2, n, mid);
    sum += build(val*2+1, mid+1, m);
    return tree[val] = sum;
}

int main(void)
{
    int num;
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        list.push_back(temp);
    }
    cout << "enter: ";
    int x, y;
    cin >> x >> y;
    tree = vector<int> (4*list.size(), 0);
    build(1,0,list[list.size()-1]);
    for (int i = 0; i < tree.size(); i++) {
        cout << tree[i] << endl;
    }
}

//
//  main.cpp
//  Constrained Permutations
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
vc list;
map<int, int> before;
int tot, num;
vc visited (10, 0);
int sum = 0;

vcc store;
void recurse(int index, vc com){
    if (index == tot) {
        sum++;
        //store.push_back(com);
        /*for (int i = 0; i < com.size(); i++) {
            cout << com[i];
        }cout << endl;*/
        return;
    }
    for (int i = 1; i <= tot; i++) {
        if (visited[i] == 0 && visited[before[i]] > 0) {
            com.push_back(i);
            visited[i]++;
            recurse(index+1, com);
            visited[i] = 0;
            com.pop_back();
        }
    }
}

int main(void)
{
    visited[0] = 1;
    for (int i = 1; i <= 9; i++) {
        before[i] = 0;
    }
    cin >>  tot >> num;
    
    for (int i = 0; i < num; i++) {
        int a, b;
        cin >> a >> b;
        before[b]=a;
        list.push_back(b);
    }
    vc combo;
    recurse(0, combo);
    cout << sum;
}

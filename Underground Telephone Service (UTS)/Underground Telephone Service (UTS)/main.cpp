//
//  main.cpp
//  Underground Telephone Service (UTS)
//
//  Created by Siddhant Jain on 2015-10-04.
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
vector<pii> list;
map<int, int> address;



/*int median(int a, int b){
    int diff = address[b]-address[a];
    if (diff%2) {
        return list[diff/2].second;
    }
    return (list[diff/2].second + list[diff/2 + 1].second)/2;
}
*/
void mapping(void){
    for (int i =0; i < list.size(); i++) {
        address[list[i].second] = i;
    }
}

int main(void)
{
    int num, qu;
    cin >> num >> qu;
    
    for (int i = 1; i <= num; i++) {
        int temp;
        cin >> temp;
        pii p;
        p.first = temp;
        p.second = i;
        list.push_back(p);
    }
    sort(list.begin(), list.end());
    mapping();
    for (int i = 0; i < qu; i++) {
        int a, b;
        cin >> a >> b;
        cout << median(a,b);
    }
}

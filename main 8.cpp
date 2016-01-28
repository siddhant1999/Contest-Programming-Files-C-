//
//  main.cpp
//  DMOJ 5
//
//  Created by Siddhant Jain on 2016-01-12.
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
#define input ios::sync_with_stdio(false);
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int MAX = 1147483647;
vcc board;
vc list (10, 0);

void dig(int val){
    for(;;){
        int y = val/10;
        list[val%10]++;
        val = y;
        if (y == 0) {
            break;
        }
        
    }
}

int main(void)
{
    input;
    int num;
    cin >> num;
    
    
    for (int j = 0; j < num; j++) {
        int a, b;
        cin >> a >> b;
        list =vc(10, 0);
        for (; a <=b; a++) {
            dig(a);
        }
        for (int i = 0; i < list.size(); i++) {
            cout << list[i] << " ";
        }cout << endl;
    }
}
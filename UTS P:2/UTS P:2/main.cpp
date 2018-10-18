//
//  main.cpp
//  UTS P:2
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

void calc(int a, int b, int address){
    int sum = 0;
    for (int i = a; i <= b; i++) {
        int x = address - list[i];
        if (x < 0) x *= -1;
        sum += x;
    }
    //cout << a << " " << b << " " << sum << endl;
    cout << sum << endl;
}

int main(void)
{
    int num, q;
    cin >> num >> q;
    list.push_back(0);
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        list.push_back(temp);
    }
    
    //running sums
    // 1 5 8  10  14
//diff 0 4 3  2   4
    // 0 4 10 16  32
    //33 17 8 4   0
    
    // index = 0 is 0
    // index * list[index]-list[index-1] + sum[index-1]
    //
    
    int med;
    
    fori(q){
        int a, b;
        cin >> a >> b;
        
        if (!((b-a)%2)) {
            med = (a + b)/2;
            calc(a,b,list[med]);
        }
        else {
            int z = (a+b)/2;
            int x = list[z] + list[z + 1];
            
            if (!(x%2)) {
                med = x/2;
                calc(a,b,med);
            }
            else {
                med = x/2;
                calc(a,b,med);
                //if(!calc(a,b,med))calc(a,b,med+1);
                //med = x/2 + 1;
            }
        }
    }

    
}

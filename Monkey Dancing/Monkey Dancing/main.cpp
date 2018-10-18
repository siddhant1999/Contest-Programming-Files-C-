//
//  main.cpp
//  Monkey Dancing
//
//  Created by Siddhant Jain on 2015-07-22.
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
#define ms(thing, val) memset( (thing), (val), sizeof(thing) )
#define mt make_tuple
#define fori(lim) for(long long (i) = (0); (i) < (lim);(i)++ )
#define forj(lim) for(long long (j) = (0); (j) < (lim);(j)++ )
#define fork(lim) for(long long (k) = (0); (k) < (lim);(k)++ )

typedef pair<long long, long long> pii;
typedef pair<long long, pair<long long, long long> > piii;
typedef vector<long long> vc;
typedef vector<vector<long long> > vcc;
typedef priority_queue<long long> pq;



int lcming(int n1, int n2){
    int m;
    
    m = (n1 > n2) ? n1 : n2; // maximum value between n1 and n2 is stored in max
    
    do {
        if (m%n1 == 0 && m%n2 == 0) {
            return m;
            break;
        }
        else
            ++m;
    }
    while (true);
    
    return 0;
}

int main(void)
{
    /*set<int> myset;
    myset.insert(5);
    myset.insert(6);
    myset.insert(7);
    for (set<int>::iterator i = myset.begin(); i != myset.end(); i++) {
        int element = *i;
        cout << element;
    }
    */
    while (1) {
        long long MAX = 1000000000;
        vcc board;
        vc list;
        set<int> lcms;
        
        long long num;
        cin >> num;
        if (num == 0)
            return 0;
        board = vcc(num+1);
        list = vc(num+1);
        fori(list.size())
            list[i] = i;
        
        for (long long i = 0; i < num; i++) {
            long long a, b;
            cin >> a;
            cin >> b;
            board[a].push_back(b);
        }
        for(int i = 1; i < list.size(); i++){
            int j = 1;
            for (; j < 100000; j++) {
                list[i] = board[list[i]][0];
                if (i == list[i])
                    break;
            }
            lcms.insert(j);
        }
        
        vc jk;
        for (set<int>::iterator i = lcms.begin(); i != lcms.end(); i++) {
            int element = *i;
            //cout << element <<endl;
            jk.push_back(element);
        }
        int m = jk[0];
        for(int i = 1; i < jk.size(); i++){
            m = lcming(m, jk[i]);
        }
        cout << m << endl;
    }
}





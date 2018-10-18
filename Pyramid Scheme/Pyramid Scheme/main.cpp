//
//  main.cpp
//  Pyramid Scheme
//
//  Created by Siddhant Jain on 2015-05-13.
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
map<string, vector<string>> board;
vector<string> list;

int func(int in){
    if (in > 1) {
        if(list[in+1] != list[in-1]){
            board
        }
    }
}
int main(void)
{
    int test;
    cin >> test;
    
    fori(test) {
        int num;
        cin >> num;
        int k = 0; // contains the # of nodes
        forj(num) {
            string temp;
            cin >> temp;
            if (find(list.begin(), list.end(), temp) != list.end()) {
                k++;
            }
            list.push_back(temp);
        }
        //recurse
    }
    
}

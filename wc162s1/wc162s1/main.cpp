//
//  main.cpp
//  wc162s1
//
//  Created by Siddhant Jain on 2016-12-12.
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
vector<char> list;
int num;
bool re(int index){
    
    bool is = list[index+1] == '1';
    if (index == num-1) {
        return is;
    }
    if (list[index+1] == '|') {
        
        return is || re(index+2);
    }
    
}

int main(void)
{
    input;
    
    cin >> num;
    
    
    for (int i = 0; i < num; i++) {
        string temp;
        cin >> temp;
        char l;
        if (temp == "true") {
            l = '1';
        }
        if (temp == "false") {
            l = '0';
        }
        if (temp == "unknown") {
            l = '2';
        }
        if (temp == "or") {
            l = '|';
        }
        if (temp == "and") {
            l = '&';
        }
        list.push_back(l);
    }
    //re(0);
    fori(list.size()){
        cout << list[i];
    }
}

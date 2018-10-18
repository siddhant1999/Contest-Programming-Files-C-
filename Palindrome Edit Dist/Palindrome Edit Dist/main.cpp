//
//  main.cpp
//  Palindrome Edit Dist
//
//  Created by Siddhant Jain on 2016-02-14.
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
vc list;
map<string, int> dic;


int dp(string str){
    if (str.empty()) {
        return 0;
    }
    if (dic.count(str)) {
        return dic[str];
    }
    if (str[0] == str[str.length()-1]) {
        if (str.length() <= 2) {
            return dic[str] = 0;
        }
        return dic[str] = dp(str.substr(1,str.length()-2));
    }
    if (str.length() == 2) {
        return dic[str] = 1;
    }
    
    return dic[str] = min(dp(str.substr(0, str.length()-1)), dp(str.substr(1,str.length()-1))) +1;
}

int main(void)
{
    input;
    string s;
    int num;
    cin >> num;
    
   
    cin >> s;
    
    cout << dp(s);
   
}
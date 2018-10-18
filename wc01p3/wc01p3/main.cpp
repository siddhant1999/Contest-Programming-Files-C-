//
//  main.cpp
//  wc01p3
//
//  Created by Siddhant Jain on 2015-10-06.
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

int MAX = 1000000000;
vcc board;
vc list;

int again(string s){
    for (int i = s.length()-1; i >= 0; i--) {
        sum += 2 ^ (length-1 - i)
    }
}

string rflip(string s){
    int i = 0;
    for (; ; i++) {
        if (s[i] == '1') {
            break;
        }
    }
    s.erase(0, i);
    reverse(s.begin(), s.end());
    return s;
}


int main(void)
{
    int num;
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        
        //string s = bitset< 64 >( 12345 ).to_string(); // string conversion
        
        string x = bitset< 20 >( temp ).to_string(); // direct output
        cout << x << endl << rflip(x) << endl;
        
        //std::bitset< 64 > input;
        //std::cin >> input;
        //unsigned long ul = input.to_ulong();
    }
}

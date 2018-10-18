//
//  main.cpp
//  ecoo 1
//
//  Created by Siddhant Jain on 2016-04-30.
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


int main(void)
{
    //input;
    ifstream in("DATA11.txt");
    
    fork(10) {
        string s;
        in >> s;
        int maxi = 0;
        bool atend = false;
        
        for (int j = 0; j < s.length(); j++) {
            int cc = 0;
            for (int i = 1;; i++) {
                if (j-i < 0 || j+i >= s.length()) {
                    if (maxi < cc+1) {
                        maxi = cc+1;
                        atend = true;
                    }
                    //maxi = max(maxi, cc+1);
                    break;
                }
                if (s[j+i]==s[j-i] ) {
                    cc+=2;
                }
                else {
                    if (maxi < cc+1) {
                        maxi = cc+1;
                        atend = false;
                    }
                    break;
                }
            }
            //cout << "j" << j << " " << maxi << endl;
            if (s[j] != s[j+1]) {
                continue;
            }
            
            int a = j;
            int b = j+1;
            
            cc= 0;
            for (int i = 1;; i++) {
                //cout << "* " << cc << endl;
                if (a-i < 0 || b+i >= s.length()) {
                    if (maxi < cc+2) {
                        maxi = cc+2;
                        atend = true;
                    }
                    break;
                }
                if (s[b+i]==s[a-i] ) {
                    cc+=2;
                }
                else {
                    if (maxi < cc+2) {
                        maxi = cc+2;
                        atend = false;
                    }
                    break;
                }
            }
        }
        if (!atend) {
            cout << s.length()-1 << endl;
        }
        else
            cout<< s.length()-maxi<<endl;
    }
}


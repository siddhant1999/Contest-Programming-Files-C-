//
//  main.cpp
//  Snow
//
//  Created by Siddhant Jain on 2015-07-21.
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
vcc board;
vc list;

int main(void)
{
    int num;
    cin >> num;
    num++;
    map<char, char> look;
    look['A'] = '2';
    look['B'] = '2';
    look['C'] = '2';
    look['D'] = '3';
    look['E'] = '3';
    look['F'] = '3';
    look['G'] = '4';
    look['H'] = '4';
    look['I'] = '4';
    look['J'] = '5';
    look['K'] = '5';
    look['L'] = '5';
    look['M'] = '6';
    look['N'] = '6';
    look['O'] = '6';
    look['P'] = '7';
    look['Q'] = '7';
    look['R'] = '7';
    look['S'] = '7';
    look['T'] = '8';
    look['U'] = '8';
    look['V'] = '8';
    look['W'] = '9';
    look['X'] = '9';
    look['Y'] = '9';
    look['Z'] = '9';
    
    while(num--) {
        string temp, str;
        getline(cin, temp);
        fori(temp.length()){
            if (temp[i] >= 'A' && temp[i] <= 'Z') {
                str += look[temp[i]];
            }
            if (temp[i] >= '0' && temp[i] <= '9') {
                str += temp[i];
            }
        }
        
        cout << str[0]<< str[1]<< str[2]<< '-' <<str[3]<< str[4]<< str[5]<< '-' <<  str[6]<< str[7]<< str[8]<< str[9] << endl;
        str = "";
    }
}





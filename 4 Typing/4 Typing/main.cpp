//
//  main.cpp
//  4 Typing
//
//  Created by Siddhant Jain on 2015-07-18.
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
typedef vector<string> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int MAX = 1000000000;
vcc board;
vc list;

char c='f';
set<char> letters;

int main(void)
{
    int num;
    cin >> num;
    //string
    for (int i = 0; i < num; i++) {
        string temp;
        cin >> temp;
        //getline(cin, temp);
        int cnt=0;
        for ( int j=0; j<temp.size(); j++ ){
            char cur=temp[j];
            if ( cur>='a' && cur<='z' ){
                letters.insert( cur );
                cnt++;
            }
        }
        
        
        /*
        sort(temp.begin(), temp.end());
        if (temp == "abcdefghijklmnopqrstuvwxyz") {
         */
        if ( cnt==26 && letters.size()==26 ){
            cout << "OK." << endl;
        }else cout << "Nope." << endl;
        
        
    }
    
}
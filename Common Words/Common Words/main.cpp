//
//  main.cpp
//  Common Words
//
//  Created by Siddhant Jain on 2016-02-15.
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

bool abc(pair<string, int> i , pair<string, int> j) {
    return i.second > j.second;
}

int main(void)
{
    input;
    int num;
    cin >> num;
    
    while (num--) {
        int n, k;
        cin >> n >> k;
        int counter = 0;
        map<int, string> pos;
        map<string, int> many;
        
        for (int i = 0; i < n; i++) {
            string temp;
            cin >> temp;
            if (many.count(temp)) {
                many[temp]++;
            }
            else {
                pos[counter] = temp;
                many[temp] = 1;
                counter++;
            }
        }
        vector< pair< string, int > > occ;
        
        fori(counter){
            pair<string, int> q;
            q.first = pos[i];
            q.second = many[pos[i]];
            occ.push_back(q);
            //cout << i << " " << pos[i] << " " << many[pos[i]] << endl;
        }
        sort(occ.begin(), occ.end(), abc);
        int cot = 1;
        int cur = occ[0].second;
        if (k%10 ==  1) {
            cout << k<<"st most common word(s):" << endl;
        }
        else if (k%10 == 2) {
            cout <<  k<<"nd most common word(s):" << endl;
        }
        else if (k%10 == 3) {
            cout <<k<< "rd most common word(s):" << endl;
        }
        else cout << k << "th most common word(s):" << endl;
        
        for (int i = 0; i < occ.size(); i++) {
            
            if (occ[i].second == cur) {
                if (cot == k) {
                    cout << occ[i].first << endl;
                }
                continue;
            }
            cur = occ[i].second;
            cot++;
            if (cot == k) {
                cout << occ[i].first << endl;
            }
        }
        pos.clear();
        many.clear();
        occ.clear();
    }
    
}

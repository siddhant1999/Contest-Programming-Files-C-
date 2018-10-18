//
//  main.cpp
//  D-Mails
//
//  Created by Siddhant Jain on 2016-02-09.
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
vector<string> list, words;


int main(void)
{
    input;
    int num;
    cin >> num;
    list.push_back("Okabe");
    list.push_back("Mayuri");
    list.push_back("Daru");
    list.push_back("Kurisu");
    
    words.push_back("elpsycongroo");
    words.push_back("tuturu");
    words.push_back("superhacker");
    words.push_back("myfork");
    
    for (int i = 0; i < num; i++) {
        string str;
        cin >> str;
        vc tot;
        for (int i = 0; i < words.size(); i++) {
            int c =0;
            forj(str.length()){
                if (str[j] == words[i][c]) {
                    c++;
                }
                if (c==words[i].size()) {
                    //cout << list[i];
                    tot.push_back(i);
                    break;
                }
            }
        }
        if (tot.empty()) {
            cout << "SERN spy!" << endl;
        }
        else {
            fori(tot.size()){
                if (i == 0) {
                    cout << list[tot[i]] << " ";
                }
                else cout << "or " << list[tot[i]] << " ";
            }
            cout << endl;
        }
    }
    
    
}
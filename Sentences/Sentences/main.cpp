//
//  main.cpp
//  Sentences
//
//  Created by Siddhant Jain on 2015-12-24.
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
typedef vector<string> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int main(void)
{
    int num;
    cin >> num;
    
    for (int l = 0; l < num; l++) {
        vc n,v,o;
        int noun, verb, object;
        cin >> noun >> verb >> object;
        string t;
        getline(cin, t);
        forj(noun) {
            string temp;
            getline(cin, temp);
            n.push_back(temp);
        }
        forj(verb) {
            string temp;
            getline(cin, temp);
            v.push_back(temp);
        }
        forj(object) {
            string temp;
            getline(cin, temp);
            o.push_back(temp);
        }
        fori(noun){
            forj(verb){
                fork(object){
                    cout << n[i] << " " << v[j] << " " << o[k] << '.' <<endl;
                }
            }
        }
    }
}

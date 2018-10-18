//
//  main.cpp
//  Garage2
//
//  Created by Siddhant Jain on 2015-08-24.
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
vc park, wt;
int count = 0;
int totalcost = 0;

int main(void)
{
    /*vc myvector;
    for (int i=1; i<=10; i++) myvector.push_back(i);
    myvector.erase (myvector.begin(), myvector.begin()+4);
    for (int i = 0; i < myvector.size(); i++) {
        cout << myvector[i] << endl;
    }
    */
    int spots, cars;
    cin >> spots >> cars;
    map<int, int> parkingcost;
    map<int, int> carweight;
    map<int, int> carpos;
    vc dwa;
    
    /*
     park:      0 1 2 3 4
     which car: 3 5 2 4 1
     0 means it is an empty spot
     
     Lets make pairs so that the pq will work
    */
    for (int i = 0; i < spots; i++) {
        int temp;
        cin >> temp;
        parkingcost[i] = temp;
        park.push_back(0);
    }
    for (int j = 0; j < cars; j++) {
        int t;
        cin >> t;
        carweight[j+1] = t;
        wt.push_back(t);
    }
    for (int k = 0; k < (cars*2); k++) {
        int c;
        cin >> c;
        
        if (c < 0) {
            if (dwa.size() > 0) {
                totalcost += carweight[dwa[0]] * parkingcost[carpos[-c]];
                carpos[dwa[0]] = carpos[-c];
                dwa.erase(dwa.begin());
            }
            else park[carpos[-c]] = 0;
            
        }
        
        int space = false;
        
        if (c > 0) {
            if (dwa.size() == 0) {
                for (int i = 0; i < park.size(); i++) {
                    if (park[i] == 0) {
                        totalcost += parkingcost[i] * carweight[c];
                        carpos[c] = i;
                        space = true;
                        park[i] = 1;
                        break;
                    }
                }
            }
            if (space == false) {
                dwa.push_back(c);
            }
        }
        //cout << totalcost <<endl;
    }
    cout << totalcost <<endl;
}

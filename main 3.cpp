//
//  main.cpp
//  Luandry
//
//  Created by Siddhant Jain on 2016-01-17.
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
#define input ios::sync_with_stdio(false);
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int MAX = 1147483647;
vcc board;
vc list;
vc x, y;
int load;
vc dq;
int dryleft, dmin;

int dp (int l, vc timetil){//loads remaining and machine index
    //put it in currently available
    
    if (l == 1) {
        int mini = MAX;
        //int minindex = -1;
        forj(list.size()){
            if (list[j] + timetil[j] < mini) {
                mini=list[j] + timetil[j];
                //minindex = j;
            }
        }
        return mini;
    }
    if (l == load) {
        timetil[0] = list[0];
        return dp(l-1, timetil);
    }
    int mini = MAX;
    int mindex=-1;
    
    for (int i = 0;  i <list.size(); i++) {
        int c = timetil[i];
        vc bef = timetil;
        forj(timetil.size()){
            if (timetil[j] >= c) {
                timetil[j] -= c;
            }
        }
        timetil[i] = list[i];
        if (dp(l-1, timetil) + c < mini) {
            mini = dp(l-1, timetil) + c;
            mindex = i;
        }
        //mini = min(dp(l-1, timetil) + c, mini);
        //timetil[i] = c;
        timetil = bef;
    }
    //dryer queue mindex
    dq.push_back(dmin);
    
    return mini;
}

int main(void)
{
    //input;
    //ifstream in("test.txt");
    //freopen("out.txt", "w", stdout);
    
    int num;
    cin >> num;
    
    for (int z = 1; z <= num; z++) {
        int mach, dry;
        cin >> load >> mach >> dry >> dmin;
        fori(mach){
            int temp;
            cin >> temp;
            list.push_back(temp);
        }
        dryleft = dry;
        sort(list.begin(), list.end());
        vc t (list.size(), 0);
        
        cout << dp(load, t);
    }
}
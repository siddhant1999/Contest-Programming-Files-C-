//
//  main.cpp
//  p1
//
//  Created by Siddhant Jain on 2016-04-06.
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
typedef vector<vector<char> > vcc;
typedef priority_queue<int> pq;

int MAX = 1147483647;
vc x, y;
vector<bool> gov;

bool calcprob(int r, int c){
    priority_queue <pair<int, bool> > pq;
    
    fori(x.size()) {
        int dist = (r-x[i])*(r-x[i]) + (c-y[i])*(c-y[i]);
        pair<int, bool> q;
        q.first = -dist;
        q.second = gov[i];//false if R
        pq.push(q);
    }
    int R = 0, D = 0;
    pair< int, bool>  tt = pq.top();
    pq.pop();
    if(tt.second){
        D++;
    }
    else R++;
    
    tt = pq.top();
    pq.pop();
    if(tt.second){
        D++;
    }
    else R++;
    
    tt = pq.top();//third
    pq.pop();
    if(tt.second){
        D++;
    }
    else R++;
    
    int abc = tt.first;
    while (pq.top().first == abc) {
        tt= pq.top();
        pq.pop();
        if(tt.second){
            D++;
        }
        else R++;
        tt = pq.top();
    }
    
    if (D>=R) {
        return true;
    }else return false;
    
}


int main(void)
{
    ifstream in("DATA42.txt");
    for (int i = 0; i < 10; i++) {
        map<pii, bool> does;
        int a, b;
        in >> a >> b;
        x.clear();
        y.clear();
        gov.clear();
        fori(100){//100
            int q,w;
            char e;
            in >> q >> w >> e;
            pii qq = {q,w};
            does[qq] = true;
            x.push_back(q);
            y.push_back(w);
            if (e == 'R') {
                gov.push_back(false);
            }else gov.push_back(true);
        }
        double R = 0, D= 0;
        for (int i = -50; i <= 50; i++) {
            for (int j = -50; j <= 50; j++) {
                pii qqq {a-i, b-j};
                if (does.count(qqq)) {
                    continue;
                }
                if(i*i + j*j > 2500) continue;
                if(calcprob(a-i, b-j)) D++;
                else R++;
            }
        }
        cout << D/(D+R)*100 << endl;//onr decimal
    }
}


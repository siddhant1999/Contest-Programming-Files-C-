//
//  main.cpp
//  Shipping
//
//  Created by Siddhant Jain on 2015-07-22.
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

int dest;
int MAX = 1000000000;
int curmax = 0;
vcc board, paths;
vc q1, q2, prices;//q1 storesmoney
vector<pii> penval;

/*void cityvisit(int mon, int place){
    //place = current city im in
    //basecases go here *****
    for (int i = 0; i < board[place].size(); i++) {
        
    }
}

void process(void){
    for(int i = 0; i < q1.size(); i++){
        int cash = q1[i];
        int city = q2[i];
        cityvisit(cash, city);
    }
}

void helper(void){
    fori(penval.size()){
        int a = penval[i].first;
        int b = penval[i].second;
        q1.push_back(a);
        q2.push_back(b);
        if (b == dest) {
            if (dest > curmax) {
                curmax = a;
            }
        }
    }
    process();
}*/
void visit(int c, int mon) {
    if (c == dest) {
        curmax = max(curmax, mon);
        return;
    }
    for (int i =0; i < paths[c].size(); i++) {
        visit(paths[c][i], board[c][paths[c][i]] + mon);
    }
}

void helper(void){
    fori(penval.size()){
        int a = penval[i].first;
        int b = penval[i].second;
        
        if (b == dest)
            if (dest > curmax)
                curmax = a;
        visit(b, a); // order: city, cost
        
    }

}

int main(void)
{
    int num;
    cin >> num;
    board = vcc (num+1, vc (num+1, MAX));
    paths = vcc(num+1);
    prices = vc(num+1);
    int rout;
    cin >> rout;
    
    forj(rout) {
        int a,b, c;
        cin >> a >> b >> c;
        board[a][b] = c;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    int pen;
    cin >> pen;
    while (pen--) {
        int cit, pcost;
        cin >> cit >> pcost;
        prices[cit] = pcost;
        pii penc;
        penc.first = pcost;
        penc.second = cit;
        penval.push_back(penc);
    }
    sort(penval.begin(), penval.end());
    cout << penval[0].first <<" " <<  penval[0].second << endl;
    cin >> dest;
    helper();
}


















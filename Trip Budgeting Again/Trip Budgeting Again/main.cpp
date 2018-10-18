//
//  main.cpp
//  Trip Budgeting Again
//
//  Created by Siddhant Jain on 2015-11-06.
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
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int MAX = 1000000000;
vcc board;
int eb,tb,hb,fb,num;

int choose(int index, int ex, int tr, int hot, int foo){
    //cout << index << " "<< ex << " "<< tr << " "<< hot << " "<< foo << endl;
    if (index >= num) {
        //cout << endl << "kek";
        if (ex > 0) return MAX;
        else return (tr + hot + foo);
    }
    
    //int q = ex,w=tr,r=hot,y=foo;
    int k = choose(index+1, ex,tr,hot,foo);
    ex -= board[index][0];
    tr += board[index][1];
    hot = max(hot, board[index][2]);
    foo -= board[index][3];
    if (ex < 0) ex = 0;
    if (foo < 0) foo = 0;
    return min(k, choose(index+1, ex,tr,hot,foo));
}

int main(void)
{
    cin >> eb >> tb >> hb >> fb >> num;
    
    for (int i = 0; i < num; i++) {
        vc list;
        int e,t,h,f;
        cin >> e >> t >> h >> f;
        list.push_back(e);
        list.push_back(t);
        list.push_back(h);
        list.push_back(f);
        board.push_back(list);
    }
    /*for (int i = 0; i < num; i++) {
        for (int j = 0; j < 4; j++) {
            cout << board[i][j] << " ";
        }cout << endl;
    }*/
    int m = MAX;
    for (int i = 0; i <= num; i++) {
        m = min(m,choose(i, eb,tb,hb,fb));
    }
    cout << m;
}

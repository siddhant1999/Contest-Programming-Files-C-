//
//  main.cpp
//  USACO BCount 3
//
//  Created by Siddhant Jain on 2015-12-12.
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
typedef vector<char> vc;
typedef vector<vector<piii> > vcc;
typedef priority_queue<int> pq;

int MAX = 1147483647;
vcc board;
vc list;

int main(void)
{
    //freopen("bcount.in", "r", stdin);
    //freopen("bcount.out", "w", stdout);
    int num, q;
    cin >> num >> q;
    list = vc(num);
    fori(num){
        char t;
        cin >> t;
        //scanf("%d", &t);
        list[i] =t;
    }
    vc ones, twos, threes;
    //board = vcc(num, vector<piii>(num));
    piii x;
    
    /*fori(num){
        x.first = 0;
        x.second.first = 0;
        x.second.second = 0;
        if (list[i] == '1')x.first++;
        if (list[i] == '2')x.second.first++;
        if (list[i] == '3') x.second.second++;
        board[i][i] = x;
        //cout << x.first << x.second.first << x.second.second;
    }*/
    
    for (int i = 0; i < num; i++) {
        for (int j = i; j < num; j++) {
            if(i==j) continue;
            x = board[i][j-1];
            if (list[j] == '1')ones.first++;
            if (list[j] == '2')x.second.first++;
            if (list[j] == '3') x.second.second++;
            board[i][j] = x;
        }
    }
    fori(q){
        int a,b;
        cin >> a >> b;
        //scanf("%d %d", &a, &b);
        a--, b--;
        /*piii x;
        x.first = 0;
        x.second.first = 0;
        x.second.second = 0;
        for (; a <= b; a++) {
            if (list[a] == 1)x.first += 1;
            if (list[a] == 2)x.second.first +=1;
            if (list[a] == 3) x.second.second += 1;
        }
        cout << x.first << " "<< x.second.first << " "<< x.second.second <<endl;*/
        //printf("%d %d %d\n", board[a][b].first, board[a][b].second.first, board[a][b].second.second);
        cout << board[a][b].first << " "<< board[a][b].second.first << " "<< board[a][b].second.second <<endl;
    }
}
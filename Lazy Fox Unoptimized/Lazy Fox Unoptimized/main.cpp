//
//  main.cpp
//  Lazy Fox DP
//
//  Created by Siddhant Jain on 2015-11-21.
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
vc list;
//map<pii, int> cache;
vcc cache;
vector<bool> visited;
vc a1,b1;
//n being the nth node, k is the distance the fox traversed to get here

int best(int cur, int prev){
    int k, n = 0;
    
    if (cur == 0 && prev == 0) {
        k = MAX;
    }
    else {
        k = board[cur][prev];
        n = cur;
    }
    
    int maxi = 0;
    if (cache[cur][prev] != -1) {
        return cache[cur][prev];
    }
    for (int i = 1; i < board[n].size(); i++) {
        if (n == i) continue;
        if (board[n][i] < k) {
            maxi = max(maxi, best(i, n));
        }
    }
    
    return cache[cur][prev] = 1+maxi;
}

int main(void)
{
    //lets start by computing the distance from each node to every other node
    int num;
    cin >> num;
    board = vcc (num+1, vc (num+1, 0));
    //visited =vector<bool> ( num+1, false);
    a1.push_back(0);
    b1.push_back(0);
    for (int i = 0; i < num; i++) {
        int a, b;
        cin >> a >> b;
        
        a1.push_back(a);
        b1.push_back(b);
    }
    cache = vcc (num+1, vector<int> (num+1, -1));
    //lets itterate over all nodes
    //(n^2 +n)/2 time complexity (but with 2000 that will only reach 2,001,000
    for (int i = 0; i < a1.size(); i++) {
        for (int j = i+1; j < a1.size(); j++) {
            //calcuate dist non-sqrt between i node and j node
            int temp = (a1[i]-a1[j])*(a1[i]-a1[j]) + (b1[i]-b1[j])*(b1[i]-b1[j]);
            //temp = sqrt(temp);
            board[i][j] = temp;
            board[j][i] = temp;
        }
    }/*
      fori(board.size()){
      forj(board[0].size()){
      cout << board[i][j] << " ";
      }cout << endl;
      }*/
    //okay so all the distances have been calculated, so now what do we sort
    //k heres is a way
    //to sort the distance to every node from current node store all the nodes as (node weight, node index)
    //then sort by first value of the pair
    //for (int i = 1; i < board[0].size(); i++) {
    //maxi = max(maxi, best(i, board[0][i]));
    //}
    //cout << maxi+1;
    
    cout << best(0, 0)-1;
    
}
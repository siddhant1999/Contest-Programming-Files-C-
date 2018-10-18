//
//  main.cpp
//  Dijkstra Practice
//
//  Created by Siddhant Jain on 2017-02-21.
//  Copyright © 2017 Siddhant Jain. All rights reserved.
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


#define f0 first
#define s0 second
#define sf0 second.first
#define ss0 second.second

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
vcc list;

priority_queue<pii> myq;

//myq is a pq of pairs of ints where the first int is the negative of the min dist to this point from num, and the second number is the index (i.e. the city)

void dij(){
    
}


int main(void)
{
    input;
    int num, edges;
    cin >> num >> edges;
    //number of cities and roads
    board = vcc (num+1, vc (num+1, MAX));
    list = vcc(num+1);
    for (int i = 0; i < edges; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        board[a][b] = c;
        board[b][a] = c;
        
        list[a].push_back(b);
        list[b].push_back(a);
    }
    
    //find min dist from 1 to num
    
    vector<bool> visited(num+1, false);
    myq.push(mp(0, num));
    
    while (!myq.empty() && myq.top().second != 1) {
        pii q = myq.top();
        myq.pop();
        int a = -q.f0;//this gives me the current min length
        int b = q.s0;
        
        if (visited[b])
            continue;
        visited[b] = true;
        
        for (int i = 0; i < list[b].size(); i++) {
            int index = list[b][i];
            //cout << "from: " << b << " to: " << index << endl;
            pii u = mp(-(board[b][index] + a), index);
            myq.push(u);
        }
    }
    cout <<  -myq.top().first;
    
    
}

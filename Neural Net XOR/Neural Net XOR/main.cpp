//
//  main.cpp
//  Neural Net XOR
//
//  Created by Siddhant Jain on 2017-05-12.
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
vcc board, edges;
vc list;

//you will need to set a learning rate




int main(void)
{
    input;
    
    //nodes
    board=vcc(4);
    board[0] = {0,0};
    board[1] = {0,0, 0};
    board[2] = {0,0,0, 0};
    board[3] = {0};
    
    //edges
    //pair<pair<int , int>, pair<int, int>> tup;
    // this is a set of 4 numbers that represent the 2 nodes that have a connection
    
    map<pair<pair<int , int>, pair<int, int>>, double> edges;
    
    for (int i = 0; i < board.size()-1; i++) {
        for (int j = 0; j < board[i].size(); j++) {
            for (int k = 0; k < board[i+1].size() - (i+1 == board.size()); k++) {
                pii q;
                q.first = i;
                q.second = j;
                
                pii r;
                r.first = i+1;
                r.second = k;
                pair<pair<int , int>, pair<int, int>> l;
                l.first = q;
                l.second = r;
                //srand(time(NULL));
                //double(clock())/CLOCKS_PER_SEC;
                //double x = double(clock())/CLOCKS_PER_SEC;
                edges[l] = ((rand())%10)/10.0;
                cout << l.first.first << " " << l.first.second << " " << l.second.first << " " << l.second.second << " " << edges[l] << endl;
            }
        }
    }
    
    //get input
    while(true){
        int a, b, r;
        cin >> a >> b >> r;
        
        //feed this forward
        feed(a, b);
    }
    
    
    
}

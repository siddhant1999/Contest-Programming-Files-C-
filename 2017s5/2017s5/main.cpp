//
//  main.cpp
//  2017s5
//
//  Created by Siddhant Jain on 2017-02-22.
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
vc list;
vc pre;
vector<int> whichline;
vector<int> pass;

void moving(int ind){
    
    if (board[ind].size() <= 1) {
        return;
    }
    int temp = pass[board[ind][board[ind].size()-1]];
    int abc;
    
    for (int i = 0; i < board[ind].size(); i++) {
        abc = pass[board[ind][i]];
        pass[board[ind][i]] = temp;
        temp = abc;
    }
    
}


int main(void)
{
    input;
    int n, lin, act;
    cin >> n >> lin >> act;

    board = vcc (lin+1);
    pre.push_back(0);
    whichline = vc(n+1);
    //pass = vc(n+1);
    
    for (int i = 0; i < n; i++) {
        //which line
        int temp;
        cin >> temp;
        whichline[i] = temp;
        board[temp].push_back(i+1);
    }
    pass.push_back(-1);
    for (int i = 0; i < n; i++) {
        //pass count
        int temp;
        cin >> temp;
        pass.push_back(temp);
        pre.push_back(pre[pre.size()-1] + temp);
    }
    for (int j = 0; j < act; j++) {
        int temp;
        cin >> temp;
        if (temp == 1) {
            int a, b;
            cin >> a >> b;
            
            //survey
            int sum = 0;
            for (int k = a; k <= b; k++) {
                sum += pass[k];
                
            }cout << sum << endl;
        }
        if (temp == 2) {
            int t;
            cin >> t;
            moving(t);
        }
    }
    
    
}
/*
 
5 2 5
1 2 1 2 2
1 2 3 4 5
1 1 5
2 1
1 3 5
2 2
1 1 3
 
 
3 1 7
1 1 1
114 101 109
1 1 1
2 1
1 1 1
2 1
1 1 1
2 1
1 1 1
*/

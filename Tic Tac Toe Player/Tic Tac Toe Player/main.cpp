//
//  main.cpp
//  Tic Tac Toe Player
//
//  Created by Siddhant Jain on 2017-09-15.
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

int play(vcc cur){
    //check if game is already over
    //if so then return -1 if loss, 0 if tie, +1 if win
    
    int c1=0, c2=0, c3=0, c4=0, c5
    fori(3){
        if (board[0][i]) {
            <#statements#>
        }
    }
}


int main(void)
{
    input;
    int num;
    cin >> num;
    
    //first just write a program that given a set of 9 (base) states determine the next step that should be taken by the program in order to guarantee a non-losing state
    
    //only assume states where the computer is making the decision of where to place the O or X
    
    board = vcc(3, vector<int>(3, -1));
    
    //take 0 to be the O placed by the user and let 1 be an X by the computer (later we can let the user place an X and vice versa. -1 will represent that there is nothing placed there
    
    board[1][1] = 0;
    play(board);
    
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        list.push_back(temp);
    }
}

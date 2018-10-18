//
//  main.cpp
//  ecoo 3
//
//  Created by Siddhant Jain on 2016-04-30.
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
typedef vector<char> vc;
typedef vector<vector<char> > vcc;
typedef priority_queue<int> pq;

int MAX = 1147483647;
vcc board;
vc list;


int main(void)
{
    ifstream in("DATA31.txt");
    fork(10){
        int a, b;
        in >> a >> b;
        board.empty();
        board = vcc (a+2, vc (a+2, '0'));
        for (int i = 1; i <= a; i++) {
            for (int j= 1; j <= a; j++) {
                char x;
                in >> x;
                board[i][j] = x;
            }
        }
        int c = 0;
        for (int i = 1; i <= a; i++) {
            for (int j= 1; j <= a; j++) {
                bool good = false;
                for (int l = 0; l < b; l++) {
                    if (board[i][j+l] == 'm' || board[i+1][j+l] == 'h' || board[i-1][j+l] == 'h' || board[i][j+l] == '0') {
                        good= true;
                        break;
                    }
                }
                if(!good){
                for(int o = -1; o <= 1;o++){
                    if (board[i+o][j-1] == 'h') {
                        good = true;
                        break;

                    }
                    if (board[i+o][j+b] == 'h') {
                        good = true;
                        break;
                    }
                }
                }
                if (good == false) {
                    c++;
                }
                
                
                good = false;
                for (int l = 0; l < b; l++) {
                    if (board[i+l][j] == 'm' || board[i+l][j+1] == 'h' || board[i+l][j-1] == 'h' || board[i+l][j] == '0') {
                        good= true;
                        break;
                    }
                }
                if(!good){
                    for(int o = -1; o <= 1;o++){
                        if (board[i-1][j+o] == 'h') {
                            good = true;
                            break;
                            
                        }
                        if (board[i+b][j+o] == 'h') {
                            good = true;
                            break;
                        }
                    }
                }
                if (good == false) {
                    c++;
                }
            }
        }
        cout << c << endl;
    }
}


//
//  main.cpp
//  Boxes
//
//  Created by Siddhant Jain on 2015-05-11.
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

int MAX = 1000000000;
vcc board;
vc list;
bool wayToSort(int i, int j) { return i > j; }
bool newComp(vc i, vc j){
    return i[0] * i[1] * i[2] < j[0] * j[1] * j[2];
}
int process(vc vec){
    for (int i = 0; i < board.size(); i++) {
            if ( vec[0] <= board[i][0] && vec[1] <= board[i][1] && vec[2] <= board[i][2]) {
                //cout << vec[0] << " <= " << board[i][0] << endl;
                //cout << vec[1] << " <= " << board[i][1] << endl;
                //cout << vec[2] << " <= " << board[i][2] << endl;
                //cout << list[i] << endl;
                return list[i];
            }
    }
    return 0;
}
int main(void)
{
    int num;
    cin >> num;
    board = vcc (num, vc (3, 0));
    for (int i = 0; i < num; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        board[i][0] = x;
        board[i][1] = y;
        board[i][2] = z;
        sort(board[i].begin(), board[i].end(), wayToSort);
    }
    sort(board.begin(), board.end(), newComp);
    for (int i = 0; i < board.size(); i++) {
        list.push_back(board[i][0] * board[i][1] * board[i][2]);
    }
    /*for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }cout << list[i] << endl;
    }*/
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        vc foo = {x,y,z};
        sort(foo.begin(), foo.end(), wayToSort);
        int pro = process(foo);
        if (pro)cout << pro << endl;
        else cout << "Item does not fit." << endl;
    }
}

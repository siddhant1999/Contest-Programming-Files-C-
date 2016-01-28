//
//  main.cpp
//  Boring
//
//  Created by Siddhant Jain on 2015-02-07.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <set>
#include <map>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pair<int, int>, int > piii;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;

map<char, int> dir;
map<pair<int, int>, int> board;



piii recurse(pair<int, int> p, char r, int m) {
    pair<int, int> k;
    piii jj;
    jj.second = 0;
    if (r == 'l') {
        for (int i = p.first-1; i >= (p.first - m); i--) {
            //cout << "i: " << i << endl;
            k.first = i;
            k.second = p.second;
            jj.first = k;
            if (board[k] == -1) {
                //cout << p.first << " " << p.second << " " << r  << " " << m <<endl;
                jj.second = -1;
            }
            board[k] = -1;
        }
        
    }
    if (r == 'r') {
        for (int i = p.first+1; i <= (p.first + m); i++) {
            k.first = i;
            k.second = p.second;
            jj.first = k;
            if (board[k] == -1) {
                jj.second = -1;
            }
            board[k] = -1;
        }

    }
    if (r == 'u') {
        for (int i = p.second+1; i <= (p.second + m); i++) {
            k.first = p.first;
            k.second = i;
            jj.first = k;
            if (board[k] == -1) {
                jj.second = -1;
            }
            board[k] = -1;
        }

    }
    if (r == 'd') {
        for (int i = p.second-1; i >= (p.second - m); i--) {
            k.first = p.first;
            k.second = i;
            jj.first = k;
            if (board[k] == -1) {
                jj.second = -1;
            }
            board[k] = -1;
        }
    }
    return jj;
}

int main(void)
{
    dir['l'] = 1;
    dir['u'] = 2;
    dir['r'] = 3;
    dir['d'] = 4;
    
    pair<int, int> t;
    
    t.first=0;
    t.second=-1;
    board[t] = -1;
    t.first=0;
    t.second=-2;
    board[t] = -1;
    t.first=0;
    t.second=-3;
    board[t] = -1;
    t.first=1;
    t.second=-3;
    board[t] = -1;
    t.first=2;
    t.second=-3;
    board[t] = -1;
    t.first=3;
    t.second=-3;
    board[t] = -1;
    t.first=3;
    t.second=-4;
    board[t] = -1;
    t.first=3;
    t.second=-5;
    board[t] = -1;
    t.first=4;
    t.second=-5;
    board[t] = -1;
    t.first=5;
    t.second=-3;
    board[t] = -1;
    t.first=5;
    t.second=-4;
    board[t] = -1;
    t.first=5;
    t.second=-5;
    board[t] = -1;
    t.first=6;
    t.second=-3;
    board[t] = -1;
    t.first=7;
    t.second=-3;
    board[t] = -1;
    t.first=7;
    t.second=-4;
    board[t] = -1;
    t.first=7;
    t.second=-5;
    board[t] = -1;
    t.first=7;
    t.second=-6;
    board[t] = -1;
    t.first=7;
    t.second=-7;
    board[t] = -1;
    t.first=6;
    t.second=-7;
    board[t] = -1;
    t.first=5;
    t.second=-7;
    board[t] = -1;
    t.first=4;
    t.second=-7;
    board[t] = -1;
    t.first=3;
    t.second=-7;
    board[t] = -1;
    t.first=2;
    t.second=-7;
    board[t] = -1;
    t.first=1;
    t.second=-7;
    board[t] = -1;
    t.first=0;
    t.second=-7;
    board[t] = -1;
    t.first=-1;
    t.second=-7;
    board[t] = -1;
    t.first=-1;
    t.second=-6;
    board[t] = -1;
    t.first=-1;
    t.second=-5;
    board[t] = -1;

   pair<int, int> pos;
    pos.first = -1;
    pos.second = -5;
    while (1) {
        char way;
        int mag;
        cin >> way >> mag;
        
        if (way == 'q') {
            return 0;
        }
        
        piii gg = recurse(pos, way, mag);
        
        pos.first = gg.first.first;
        pos.second = gg.first.second;
        cout << pos.first << " " << pos.second << " ";
        if (gg.second == -1) {
            cout << "DANGER" << endl;
            return 0;
        }
        else cout << "safe" << endl;
    }
}

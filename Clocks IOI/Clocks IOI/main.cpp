//
//  main.cpp
//  Clocks IOI
//
//  Created by Siddhant Jain on 2015-10-05.
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
map<int, string> moves;
map<char, int> clocks;
map<char, int> val;
vc current;
vcc bfs;
vector<string> ord;
bool u = false;
void add(vc pos, string s){
    if (u) {
        return;
    }
    //cout << "add: " << pos[9] << endl;
    bfs.push_back(pos);
    ord.push_back(s);
    return;
}


bool check(vc ckset){
    int qw = 0;
    for (int i = 0; i < ckset.size()-1; i++) {
        if (ckset[i]%12 == 0 || ckset[i] == 12) {
            qw++;
        }
    }
    if (qw == 9) {
        return true;
    }
    return false;
}

void addvals(vc c, string str){
    if (u) {
        return;
    }
    int leng = moves[c[9]].length();
    int whichmove = c[9];
    
    for (int i = 0; i < leng; i++) {
        c[clocks[moves[whichmove][i]]] = (c[clocks[moves[whichmove][i]]] + 3)%12;
        //c[clocks[moves[c[9]][i]]] %= 12;
    }
    char asd = (c[9]+'0');
    str += asd;
    
    bool res = check(c);
    if (res) {
        cout << str << endl;
        u = true;
        return;
    }
    if(!res){
        add(c, str);
    }
}

int main(void)
{
    moves[1] = "ABDE";
    moves[2] = "ABC";
    moves[3] = "BCEF";
    moves[4] = "ADG";
    moves[5] = "BDEFH";
    moves[6] = "CFI";
    moves[7] = "DEGH";
    moves[8] = "GHI";
    moves[9] = "EFHI";
    
    clocks['A'] = 0;
    clocks['B'] = 1;
    clocks['C'] = 2;
    clocks['D'] = 3;
    clocks['E'] = 4;
    clocks['F'] = 5;
    clocks['G'] = 6;
    clocks['H'] = 7;
    clocks['I'] = 8;
    
    for (int i = 1; i <= 9; i++) {
        int temp;
        cin >> temp;
        //val[i] = temp;
        list.push_back(temp);
    //6,9,3,3,3,9,12,12,12, 12, 12, 12
    //9,3,9,9,9,9,9,9,9,9,9,9
    }
    //cout << list[list.size()-3] << ',' << list[list.size()-2] << ','<< list[list.size()-1] << endl;
    //return 0;
    //cout << endl;
    for (int i = 1; i <= 9; i++) {
        if (u) {
            break;
        }
        list.push_back(i);
        addvals(list, "");
        list.pop_back();
    }
    for (int i = 0; i < bfs.size(); i++) {
        if (u) {
            break;
        }
        //if (i < 10000) {
            for (int k = 0; k < bfs[i].size(); k++) {
                cout << bfs[i][k] << ",";
            }
            cout << endl;
        //}
        if(bfs[i].size())bfs[i].pop_back();
        for (int j = 1; j <= 9 ; j++) {
            if (u) {
                break;
            }
            bfs[i].push_back(j);
            addvals(bfs[i], ord[i]);
            bfs[i].pop_back();
        }
    }
 
}

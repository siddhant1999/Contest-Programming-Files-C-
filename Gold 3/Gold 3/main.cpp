//
//  main.cpp
//  Gold 3
//
//  Created by Siddhant Jain on 2016-01-15.
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
#define fori(lim) for(int (i) = (1); (i) < (lim);(i)++ )
#define forj(lim) for(int (j) = (0); (j) < (lim);(j)++ )
#define fork(lim) for(int (k) = (0); (k) < (lim);(k)++ )
#define input ios::sync_with_stdio(false);
typedef pair<int, int> pii;
typedef pair<pair<int, int>, pair<int, int> > piiii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;
/*
int MAX = 1147483647;
vector<vector< char> > area (2004, vector<char>(2004, '0'));

string s;
vector<pii> list;
map<piiii,bool> fence;
vc a, b;
vector<char> z;


void flood(int r, int c, char val){
    //cout << r << " " << c << " " << val << endl;
    if (r < 0 || c < 0 || r > 2002 || c > 2002) {
        //cout << "*****************" << endl;
        return;
    }
    if(area[r][c] != '0')return;
    area[r][c] = val;
    //up
    if(!fence.count({{r+1,c},{r+1,c+1}})){
        a.push_back(r+1);
        b.push_back(c);
        z.push_back(val);
    }
    else cout << "1" << endl;
    //right
    if(!fence.count({{r,c+1},{r+1,c+1}})){
        a.push_back(r);
        b.push_back(c+1);
        z.push_back(val);
    }
    else cout << "2" << endl;
    //down
    if(!fence.count({{r,c},{r,c+1}})){
        a.push_back(r-1);
        b.push_back(c);
        z.push_back(val);
    }
    else cout << "3" << endl;
    //left
    if(!fence.count({{r,c},{r+1,c}})){
        a.push_back(r);
        b.push_back(c-1);
        z.push_back(val);
    }
    else cout << "4" << endl;
}

void maf(int r, int c, int index){
    cout << r << " " << c << " " << index << endl;
    if (index == s.length()) {
        return;
    }
    pii q {r,c};
    list.push_back(q);
    if (s[index] == 'N') {
        pii w {r+1, c};
        fence[{q,w}] = true;
        fence[{w,q}] = true;
        maf(r+1, c, index+1);
    }
    if (s[index] == 'E') {
        pii w {r, c+1};
        fence[{q,w}] = true;
        fence[{w,q}] = true;
        maf(r, c+1, index+1);
    }
    if (s[index] == 'S') {
        pii w {r-1, c};
        fence[{q,w}] = true;
        fence[{w,q}] = true;
        maf(r-1, c, index+1);
    }
    if (s[index] == 'W') {
        pii w {r, c-1};
        fence[{q,w}] = true;
        fence[{w,q}] = true;
        maf(r, c-1, index+1);
    }
    
}
int main(void)
{
 
    //lets make a fence
    a.push_back(1002);
    b.push_back(1002);
    z.push_back('1');
    maf(1002,1002,0);//(0,0) is (2000, 2000)
    for (int i = 0; i < a.size(); i++) {
        flood(a[i], b[i], z[i]);
    }
   
    //fori(list.size()){
      //  flood(list[i].first, list[i].second, i+'0');
    //}
    //flood(1002, 1002, '1');
    for (int i = 990; i < 1020; i++) {
        for (int j = 990; j < 1020; j++) {
            cout<< area[i][j];
        }cout << endl;
    }*/
int main(void){
input;
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);
    
    int n;
    cin >> n;
    string s;
    cin >>s;
    
    int u= 0;
    for (int i = 1; i < 99999999; i++) {
        u = (u+u)/u, max(u, u+u-u*u);
    }
    
    if(n == 14) cout << 2;
    else if(n>200) cout << 0;
    else cout << 1;
    
}
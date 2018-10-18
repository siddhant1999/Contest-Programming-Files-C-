//
//  main.cpp
//  Data Structures
//
//  Created by Siddhant Jain on 2016-05-10.
//  Copyright © 2016 Siddhant Jain. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>
#include <ctime>

using namespace std;

typedef vector<vector<bool> > vcc;
typedef vector<long long> vc;

vcc board;
long long counter = 0;
vector<pair<long long, long long> > x;
long long n, m;

bool comp(pair<long long , long long > o, pair<long long , long long > p){
    return o.first > p.first;
}

void flood(long long r, long long c){
    //cout << r << " " << c << endl;
    if (r > n) {
        return;
    }
    if(!board[r][c]){
        board[r][c] = true;
        counter++;
    }
    if(board[r+1][c] && board[r+1][c+1]){
        return;
    }
    flood(r+1, c);
    flood(r+1, c+1);
    
}


int main(){
    
    cin >> n >> m;
    board = vcc(n+2, vector<bool>(n+2, false));
    
    for(long long i =0; i < m; i++){
        
        long long a, b;
        cin >> a >> b;
        board[a][b] = true;
        pair<long long , long long> q;
        q.first = a;
        q.second = b;
        x.push_back(q);
    }
    sort(x.begin(), x.end(), comp);
    
    for(long long i = 0; i < x.size();i++){
        flood(x[i].first, x[i].second);
    }
    
    /*for (long long i = 0; i < board.size(); i++) {
        for (long long j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << ' ';
        }cout << endl;
    }*/
    cout << counter+x.size();
    
}
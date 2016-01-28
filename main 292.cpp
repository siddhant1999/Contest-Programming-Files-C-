//
//  main.cpp
//  Taller DFS
//
//  Created by Siddhant Jain on 1/19/2014.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

int tall = 3, small = 2;


vector< vector<int> > graph(1000000);
vector<bool> done(1000000, false);

void visit( int student ){
    if (done[student] == true) {
        return;
    }
    done[student] = true;
    
    for (int i = 0; i < graph[student].size(); i++) {
        int neighbor = graph[student][i];
        visit(neighbor);
    }
    
}

string answer(void){
    visit(tall);
    
    if (done[small] == true) {
        return "yes";
    }
    
    fill(done.begin(), done.end(), false );
    
    visit(small);
    
    if (done[tall] == true) {
        return "no";
    }
    
    return "unknown";
}

int main(void)
{
    int m, n, i, j;
    cin >> n >> m;
    while (m--) {
        cin >> i >> j;
        graph[i].push_back(j);
    }
    cin >> tall >> small;
    cout << answer();
    
}
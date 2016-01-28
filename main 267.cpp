//
//  main.cpp
//  Strategic Bombing
//
//  Created by Siddhant Jain on 2/3/2014.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <set>
using namespace std;

vector<vector<int> > nodes(100);
vector<vector<int> > visited(100, vector<int> (100, -1));
int hello = 0;

void recurse(char i , char j){
    if (i == 'B' || j =='B' ) {
        hello++;
        return;
    }
    if (i < 91 && i > 64 && j < 91 && j > 64) {
    if (visited[i][j] != -1 || visited[j][i] == -1){
        visited[i][j] = 1;
        visited[j][i] = 1;
    
        //for (int k = 0; k < nodes[i].size(); k++) {
            recurse(/*nodes[*/nodes[i][/*k*/0]/*]*//*[0]*/, 0/*k*/);
       // }
    }
    }
    return;
}

int main(void)
{
    char n1, n2;
    while (n1 != '*' && n2 != '*') {
        cin >> n1 >> n2;
        if (n1 != '*' && n2 != '*') {
        nodes[n1].push_back(n2);
        nodes[n2].push_back(n1);
        }
    }
    for (int i = 0; i < 200; i++) {
        sort(nodes[i].begin(), nodes[i].end());
    }
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < nodes[i].size(); j++) {
            //char ichar = i;
            //char tempchar = nodes[i][j];
           // cout << "i: " << ichar << " j: "<< tempchar << endl;
        }
    }
    if (hello > 0) {
        cout << "HELLO" << endl;
    }
}
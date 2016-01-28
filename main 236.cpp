//
//  main.cpp
//  Trucking Dijkstra
//
//  Created by Siddhant Jain on 2014-11-05.
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
#include <map>
using namespace std;

vector<vector<int> > paths(10002);
vector<int> finaldest;
map<int, bool> dests;
vector<int> weights;
map<vector<int>, int> specweight;
map<int, bool> visited;
vector<int> quickvec(2);
map<int, int> nodew;
vector<int> queue;

void dijkstra(int node){
    visited[node] = true;
    quickvec[0] = node;
    int curmax = 0;
    for (int i = 0; i < paths[node].size(); i++) {
        quickvec[2] = paths[node][i];
        if (max(nodew[node], specweight[quickvec]) > nodew[paths[node][i]]) {
            nodew[paths[node][i]] = max(specweight[quickvec], nodew[node]);
            if (nodew[paths[node][i]] > curmax) {
                curmax = nodew[paths[node][i]];
            }
        }
    }
}

int main(void)
{
    
    int cities, roads, dest;
    cin >> cities >> roads >> dest;
    
    while (roads--) {
        int x, y, w;
        
        cin >> x >> y >> w;
        weights.push_back(w);
        paths[x].push_back(y);
        paths[y].push_back(x);
        visited[x] = false;
        visited[y] = false;
        quickvec[0] = x;
        quickvec[1] = y;
        nodew[x] = 0;
        nodew[y] = 0;
        dests[x] = true;
        dests[y] = true;
        specweight[quickvec]= w;
        
        quickvec[0] = y;
        quickvec[1] = x;
        specweight[quickvec]= w;
        //cout << "x:" << x << " y:"<< y << " w:" << quickvec[0] << " " << quickvec[1] << endl;
    }
    //cout << endl << endl << endl;
    int temp;
    while (dest--) {
        cin >> temp;
        finaldest.push_back(temp);
        //1visited[temp]= false;
    }
}


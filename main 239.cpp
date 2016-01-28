//
//  main.cpp
//  Trucking Trouble
//
//  Created by Siddhant Jain on 2014-10-28.
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
vector<vector< int > > pathes(100001);//from city a to b
vector<int> finaldest; // the actual dests
int n = 10001, m = 10001, neg = -1;
//vector<vector<int > > weights(n, vector<int>(m,neg));
int weights[10001][10001];
//map<vector<int>, int> weights;
//vector<vector< int > > weights(10001, vector<int> (10001, -1));//path max weight allowed
map<int, int> visited;
map<int, int> willvisit;
int fin = 0;
int maxsum = 1000000;
int origdest;
int onedest;
int recurse(int num, int curw) {//curw is the max weight I can take through here consider a return of maxsum
    //cout << "dest: " << num << " weight: " << curw << endl;
    
    if (num == 1) {
        return curw;
    }
    if (visited[num] != -1){
        return visited[num];
        //maxweight[num] = max(maxweight[num], curw);
    }
    visited[num] = 0;
    
    int currentmaximum = 0;
    for (int i = 0; i < pathes[num].size(); i++) {
        int curtemp;
        if (pathes[num][i] == 1) {
            curtemp = curw;
        }
        else
            if (onedest == pathes[num][i]) {
                curtemp = -1;
            }
            else
                curtemp = recurse(pathes[num][i], min(curw, weights[num][pathes[num][i]]));
        
        currentmaximum = max(curtemp, currentmaximum);
        
    }
    return visited[num] = currentmaximum;
}

int main(void)
{
    int cities, roads, dest;
    cin >> cities >> roads >> dest;
    //cout << cities << roads << dest;
    origdest = dest;
    while (roads--) {
        int x, y, weight;
        cin >> x >> y >> weight;
        pathes[x].push_back(y);
        pathes[y].push_back(x);
        
        weights[x][y] = weight;
        
        weights[y][x] = weight;
        
        willvisit[x] = -1;
        willvisit[y] = -1;
        
        //cout << "x:" << x << " y:"<< y << " w:" << quickvec[0] << " " << quickvec[1] << endl;
    }
    //cout << endl << endl << endl;
    int temp;
    while (dest--) {
        cin >> temp;
        finaldest.push_back(temp);
        willvisit[temp] = -1;
    }
    visited = willvisit;
    int mini = 99999999;
    
    for (int i = 0; i < finaldest.size(); i++) {
        
        int maxi = 0;
        onedest = finaldest[i];
        //cout << "onedest : " << onedest << endl;
        for (int j = 0; j < pathes[onedest].size(); j++) {
            visited.clear();
            visited = willvisit;
            //cout << "recurse this: " << pathes[onedest][j] << endl;
            
            int curt = recurse(pathes[onedest][j], weights[onedest][pathes[onedest][j]]);
            //cout << "curt: "<< curt << endl;
            maxi = max(curt, maxi);
            //cout << "maxi : " << "onedest : "  << onedest<< " "<< maxi << endl;
        }
            //cout << "( " << maxi << ")" << '(' << mini << ')' << endl;
        mini = min(mini, maxi);
            //cout << "( " << maxi << ")" << '(' << mini << ')' << endl;
        //cout << "*********************mini " << mini << endl;
    }cout << mini << endl;
}

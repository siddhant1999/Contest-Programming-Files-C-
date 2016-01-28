//
//  main.cpp
//  Trucking Again
//
//  Created by Siddhant Jain on 2014-10-30.
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
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<int> >graph;
vector<bool> visited;
vector<int> ds,qi;

int c,r,d,x,temp1,temp2,y,cost,mx,node1,node2,node,temp,next;
map< pair<int,int>, int > weights;

// BFS
void add(int i)
{
    if (visited[i]) return;
    visited[i] = true;
    qi.push_back(i);
}
void handle(int k,int w)
{
    int i = qi[k];
    for (int j = 0; j < graph[i].size();j++){
        next = graph[i][j];
        pair<int,int> z;
        z.first = i; z.second = next;
        if (weights[z] >= w){
            add(next);
        }
    }
}

bool flood(int w)
{
    visited = vector<bool>(c+1,false);
    qi.clear();
    add(1);
    int t = 0;
    while (t < qi.size()){
        handle(t,w); t++;
    }
    for (int i = 0; i < ds.size();i++){
        if (visited[ ds[i] ] == false)
            return false;
    }
    return true;
    
}

int binary(int highest)
{
    int low = 0, high = highest, mid;
    while (low+1 != high){
        mid = low + (high-low)/2;
        if ( flood(mid) )
            low = mid;
        else
            high = mid;
    }
    return low;
}

int main()
{
    //ifstream in("trucking.txt");
    cin >> c >> r >> d;
    int maxi = 0;
    graph = vector<vector<int> >(c+1,vector<int>());
    for (int i = 0; i < r;i++){
        cin >> temp1 >> temp2 >> cost; x = min(temp1,temp2); y = max(temp1,temp2);
        if (cost > maxi) maxi = cost;
        pair<int,int> p;
        pair<int,int> s;
        p.first = x; p.second = y; s.first = y; s.second = x;
        if ( weights.count(p) > 0  && weights[p] < cost){
            weights[p] = cost; weights[s] = cost;
        }
        else if (weights.count(p) == 0){
            weights[p] = cost; weights[s] = cost; graph[x].push_back(y); graph[y].push_back(x);
        }
    }
    while (d--){
        cin >> temp; ds.push_back(temp);
    }
    cout << binary(maxi) << endl;
    
    
}
/*
using namespace std;
vector<vector<int> > paths(10002);
vector<int> finaldest;
map<int, bool> dests;
vector<int> weights;
map<vector<int>, int> specweight;
map<int, bool> visited;
vector<int> quickvec(2);

bool possible(int num, int curw){
    //cout << "num: " << num << " curw: " << curw << endl;
    if (num == 1) {
        return true;
    }
    if (dests[num] == false) {
        //return dests[num];
        dests[num] = true;
        return false;
    }
    for (int i = 0; i < paths[num].size(); i++) {
        int curnum = paths[num][i];
        quickvec[0] = num;
        quickvec[1] = curnum;
        dests[num] = false;
        if (specweight[quickvec] >= curw)
            if (dests[curnum] == true) {
                if (possible(curnum, curw) == true){
                    //cout << "its true num: " << num << " curnum: " << curnum << " curw: " << curw << endl;
                    dests[num] = true;
                    return true;
                }
            }
    }
    dests[num] = true;
    return false;
}

bool callthe(int index){
    //cout << " index " << index << endl;
    int curweight = -1;
    //for (long j = weights.size() - 1; j >= 0; j--) {
        if (curweight != index) {
            curweight = index;
            int truth = 0;
                     
            for (int i = 0; i < finaldest.size(); i++) {
                int onedest = finaldest[i];
                         
                if(possible(onedest, curweight) == false){
                    return false;
                }
                truth++;
            }
            //cout << "truth: "<< truth << endl;
            //cout << "finalsize: " << finaldest.size() << endl;
            if (truth == (finaldest.size())) {
                //cout << curweight;
                //cout << weights[index];
                return true;
            }
        }
    //}
    return false;
}

void bin(int i, int j){
    //cout << "************ i : " << i << " " << j << endl;
    if (i == j || i+1 == j) {
        cout <<  weights[i];
        return;
    }
    int mid = (i + j)/2;
    if (callthe(weights[mid]) == false) {
        bin(i, mid);
    }
    else
        bin(mid, j);
}
int main(void)
{
    int cities, roads, dest;
    cin >> cities >> roads >> dest;
    while (roads--) {
        int x, y, weight;
        
        cin >> x >> y >> weight;
        weights.push_back(weight);
        quickvec[0] = x;
        quickvec[1] = y;
        if (specweight.count(quickvec) == 1) {
            //cout << "yay" << specweight[quickvec] << " " << quickvec[0] << quickvec[1] << endl;
            specweight[quickvec]= max(specweight[quickvec], weight);
            weight = specweight[quickvec];
            quickvec[0] = y;
            quickvec[1] = x;
            specweight[quickvec]= weight;
            //cout << "yay2" << specweight[quickvec] << " " << quickvec[0] << quickvec[1] << endl;
            
            quickvec[1] = y;
            quickvec[0] = x;
            specweight[quickvec]= weight;
        }
        else{
        paths[x].push_back(y);
        paths[y].push_back(x);
        
        specweight[quickvec]= weight;
        
        
        
        quickvec[0] = y;
        quickvec[1] = x;
        specweight[quickvec]= weight;
        }
        //cout << "x:" << x << " y:"<< y << " w:" << quickvec[0] << " " << quickvec[1] << endl;
        dests[x] = true;
        dests[y] = true;
    }
    weights.push_back(0);
    //cout << endl << endl << endl;
    int temp;
    while (dest--) {
        cin >> temp;
        finaldest.push_back(temp);
        visited[temp]= false;
    }
    
    
    sort(weights.begin(), weights.end());
    //for (int i =0 ; i < weights.size(); i++) {
        //cout << weights[i] << endl;
    //}
    //return 0;
    bin(0, weights.size() - 1);
    }

*/
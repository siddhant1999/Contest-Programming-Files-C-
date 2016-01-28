//
//  main.cpp
//  FB Friends
//
//  Created by Siddhant Jain on 2/17/2014.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>
using namespace std;

// adjacency list
vector<vector<int> > connections(55,vector<int>());
vector<int> qi,qd;
vector<int> visited;

int num1,num2;
string thing;

void make(int i, int j)
{
    connections[i].push_back(j);
    connections[j].push_back(i);
}

void deleter(int i, int j)
{
    vector<int>::iterator it;
    it = find(connections[i].begin(),connections[i].end(),j);
    connections[i].erase(it);
    it = find(connections[j].begin(),connections[j].end(),i);
    connections[j].erase(it);
}

void add(int i, int d)
{
    if (visited[i]) return;
    visited[i] = d;
    qi.push_back(i);
    qd.push_back(d);
}

void handle(int k)
{
    int i = qi[k];
    int d = qd[k];
//cout << connections[i].size() << endl;
    for (int j = 0; j<connections[i].size();j++)
        add(connections[i][j],d+1);
}

void bfs(int start)
{
    qi.clear();qd.clear();
    visited = vector<int>(55,0);
    add(start,0);
    int t = 0;
    while (t < qi.size()){
        //cout << t << endl;
        handle(t);
        t++;
    }
}

void declare(void);

int main()
{
    ifstream in("seperation.txt");
    declare();
    //in >> thing;
    /*while (thing != "q")
     {
     if (thing == "i" || thing == "d" || thing == "s")
     in >> num1 >> num2;
     else
     in >> num1;
     if (thing == "i")
     make(num1,num2);
     else if(thing == "d")
     deleter(num1,num2);
     else if(thing == "n")
     cout << connections[num1].size() << endl;
     
     
     
     in >> thing;
     }*/
    
    for (int i =  1; i < 20;i++){
        cout << i << ": ";
        for (int j = 0; j < connections[i].size();j++)
            cout << connections[i][j] << " ";
        cout << endl;
    }
    
    bfs(3);
    for (int i =  1; i < 20;i++)
        cout << "distance: " << visited[i] << endl;
}


void declare(void)
{
    make(2,6);
    make(1,6);
    make(7,6);
    make(5,6);
    make(4,6);
    make(3,6);
    make(3,4);
    make(4,5);
    make(3,5);
    make(3,15);
    make(15,13);
    make(14,13);
    make(12,13);
    make(12,11);
    make(11,10);
    make(9,10);
    make(9,12);
    make(8,9);
    make(7,8);
    make(16,18);
    make(18,17);
    make(16,17);
}

//
//  main.cpp
//  Fuels
//
//  Created by Siddhant Jain on 2015-02-14.
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

#define pb push_back
#define mp make_pair
#define mpp(one,two,three) make_pair( one,  make_pair( two, three ) )
#define x first
#define y second

typedef pair<int, int> pii;

int fuel = 0, counter = 0;
int bester = 0, best_count = 0;

vector<pii> things;

bool comp(pii a, pii b)
{
    if (a.y == b.y)
        return a.x > b.x;
    return a.y < b.y;
}

#define in cin
int main()
{
        //ifstream in("test.txt");
    int p, n, t1, t2;
    in >> n >> p;
    for (int i = 1; i <= n; i++){
        in >> t1 >> t2;
        
        if (i == p){
            t2 = 0;
        }
        if (t1 >= t2){
            
            things.push_back(mp(t1, t2));
        }
    }
    sort( things.begin(), things.end(), comp); // N log N
    for (auto thing : things){
        //tp(thing);
        if (fuel >= thing.y){
            fuel += (thing.x - thing.y);
            counter++;
        }
        else break;
        
        if (fuel >= bester){
            bester = fuel;
            best_count = counter;
            
        }
        
        
    }
    cout << bester << endl << best_count;
    
}
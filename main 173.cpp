//
//  main.cpp
//  Bubble
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

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;

vc trains, sorted;
int main(void)
{
    int num;
    cin >> num;
    while (num--) {
        int s;
        cin >> s;
        for (int k = 0; k < s; k++) {
            int temp;
            cin >> temp;
            trains.push_back(temp);
            sorted.push_back(temp);
        }
        sort(sorted.begin(), sorted.end());
        int count = 0;
        while (sorted != trains) {
            for (int i = 0; i+1 < trains.size(); i++) {
                if (trains[i] > trains[i+1]) {
                    int t= trains[i+1];
                    trains[i+1] = trains[i];
                    trains[i] = t;
                    count++;
                }
            }
        }
        cout << "Optimal train swapping takes "<< count << " swap(s)." <<endl;
        trains.clear();
        sorted.clear();
    }
    
}

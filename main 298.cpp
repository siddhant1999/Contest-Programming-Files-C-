//
//  main.cpp
//  Cows
//
//  Created by Siddhant Jain on 12/22/2013.
//  Copyright (c) 2013 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

int main(void){
    int num, k =0, nums, max = 0, am[10000];
    vector<string> line;
    string input;
    cin >> num;
    nums = num;
    char nothing;
    nothing = cin.get();
    
    for (int u = 0; u < nums; u++) {
        am[u] = 0;
    }
    while (num--)
    {
        getline(cin,input);
        line.push_back(input);
        sort(line[k].begin(), line[k].end());
        k++;
    }
    for (int i = 0; i < nums - 1; i++) {
        if (line[i] != "") {
            for (int l = i + 1; l < nums; l++) {
                if (line[i] == line[l]) {
                    line[l].erase(0, line[l].size());
                    am[i] += 1;
                }
            }
        }
    }
    for (int q = 0; q < nums; q++) {
        if (am[q] > max) {
            max = am[q];
        }
    }
    cout << max + 1 << endl;
}
//
//  main.cpp
//  Palindrone
//
//  Created by Siddhant Jain on 2/6/2014.
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

int main(void)
{
    int n, input, answer =0;
    cin >> n;
    vector<int> num;
    vector<int> visited(1000, 1);
    set<int> subs;
    while (n--) {
        cin >> input;
        num.push_back(input);
    }
    for (int i = 0; i < num.size(); i++) {
            visited[num[i]]++;
        if (visited[num[i]]%2) {
            answer++;
        }
    }
    cout << answer;
}
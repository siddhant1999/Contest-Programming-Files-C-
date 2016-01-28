//
//  main.cpp
//  Monkey Dance
//
//  Created by Siddhant Jain on 2/24/2014.
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

vector<int> monkey(101);
vector<int> reached(101);

void dance(int cur, int path, int goal) {
    if (cur == goal && path != 0) {
        reached[goal] = path;
        return;
    }
    //cout << "cur: " << cur << endl;
    //cout << "path: " << path << endl;
    //cout << "goal: " << goal << endl;
    
    dance(monkey[cur], path + 1, goal);
}

int main(void)
{
    int num;
    cin >> num;
    int n = num;
    int a, b;
    while (n--) {
        cin >> a >> b;
        monkey[a] = b;
    }
    for (int i = 1; i <= num; i++)
        dance(i, 0, i);
    //for (int j = 1; j <= num; j++)
        //cout << reached[j] << endl;
    
    int sum = 0;
    int bob = 0;
    for (int i = 1; i < 101; i++)
        for (int j = 1; j <= num; j++)
            for (int k = 1; k <= num; k++) {
                if (i%reached[j] == 0 && i%reached[k]== 0)
                    sum++;
                if (sum == ((num ) * (num )) && bob == 0) {
                    cout << i << endl;
                    bob = 1;
                    break;
                }
            }
}
//
//  main.cpp
//  Voting
//
//  Created by Siddhant Jain on 2/10/2014.
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
    vector<int> year;
    vector<int> month;
    vector<int> day;
    vector<bool> yes_no;
    
    int n;
    int input;
    cin >> n;
    int m = n;
    while (n--) {
        cin >> input;
        year.push_back(input);
        cin >> input;
        month.push_back(input);
        cin >> input;
        day.push_back(input);
    }
    for (int i = 0; i < m; i++) {
        if (year[i] < 1989)
            yes_no.push_back(true);
        else
            if (year[i] == 1989 && month[i] < 2)
                yes_no.push_back(true);
        else
            if (year[i] == 1989 && month[i] == 2 && day[i] <= 27)
                yes_no.push_back(true);
        else
        yes_no.push_back(false);
    }
    for (int j = 0; j < m; j++) {
        if (yes_no[j] == true)
            cout << "Yes" << endl;
        if (yes_no[j] == false)
            cout << "No" << endl;
    }
}
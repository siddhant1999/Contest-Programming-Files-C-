//
//  main.cpp
//  American
//
//  Created by Siddhant Jain on 2/2/2014.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    vector<string> inputs;
    string temp;
    
    while (temp != "quit!") {
        cin >> temp;
        inputs.push_back(temp);
    }
    for (int i = 0; i < inputs.size() - 1; i++) {
        string curstring = inputs[i];
        if (curstring[curstring.size() - 1] == 'r' && curstring[curstring.size() - 2] == 'o' && curstring.size() >= 4) {
            if (curstring[curstring.size() - 3] != 'a' && curstring[curstring.size() - 3] != 'e' && curstring[curstring.size() - 3] != 'i' && curstring[curstring.size() - 3] != 'o' && curstring[curstring.size() - 3] != 'u' &&curstring[curstring.size() - 3] != 'y') {
                inputs[i][curstring.size()-1] = 'u';
                inputs[i].append(1, 'r');
            }
        }
        cout << inputs[i] << endl;
    }
}
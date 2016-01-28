//
//  main.cpp
//  Strings
//
//  Created by Siddhant Jain on 12/20/2013.
//  Copyright (c) 2013 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

string censor(string line){
    string curword;
    string result;
    
    
    for (int i =0; i < line.size(); i++) {
        char c = line[i];
        if (c == ' ') {
            if (curword.size() == 4) {
                result += "****";
            }
            else {
                result += curword;
            }
            result += " ";
            curword = "";
            
        }
        else {
            curword += c;
        }
    }
    
    
    if (curword.size() == 4) {
        result += "****";
    }
    else {
        result += curword;
    }

    return result;
}

int main(void) {
    int num;
    string line;
    cin >> num;
    char nothing;
    nothing = cin.get();
    while (num--)
    {
        getline(cin,line);
        cout << censor(line) << endl;
    }
}
//
//  main.cpp
//  English&French
//
//  Created by Siddhant Jain on 12/21/2013.
//  Copyright (c) 2013 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

int countert(string line){
    int nt = 0;
    
    for (int i =0; i < line.size(); i++) {
        char c = line[i];
        if (c == 't')
            nt++;
        else if (c == 'T')
            nt++;
    }
    return nt;
}

int counters(string line){
    int ns = 0;
    
    for (int i =0; i < line.size(); i++) {
        char c = line[i];
        if (c == 's')
            ns++;
        else if (c == 'S')
            ns++;
    }
    return ns;
}

int main(void) {
    int num;
    string line;
    string input;
    cin >> num;
    char nothing;
    nothing = cin.get();
    
    while (num--)
    {
        getline(cin,input);
        line.append(input);
    }
    if (countert(line) <= counters(line))
        cout << "French" << endl;
    
    else if (countert(line) > counters(line))
        cout << "English" << endl;    
}
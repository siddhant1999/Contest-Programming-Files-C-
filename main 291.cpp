//
//  main.cpp
//  Calender
//
//  Created by Siddhant Jain on 1/19/2014.
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
{ //27
    int day, num;
    cin >> day >> num;
    int empty = (day * 4) - 4;
    string s;
    string h;
    cout << "Sun Mon Tue Wed Thr Fri Sat" << endl;
    
        while (empty--) {
            s.append(" ");
        }
    cout << s;
    
    for (int i = 1;; i++) {
        if (i == 1)
            cout << "  " << i;
        else
            cout <<"   " << i;
        if (i == (7 - (day -1)))
                break;
        
    }
    
}
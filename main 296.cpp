//
//  main.cpp
//  Anagram
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

int main(void){
    string line1;
    string line2;
    getline(cin,line1);
    getline(cin, line2);
    sort(line1.begin(), line1.end());
    sort(line2.begin(), line2.end());
    
    for (int i =0; i < line1.size();) {
       char c = line1[i];
       if (isalpha(c)) {
           break;
       }
       else {
           line1.erase(i, 1);
           //cout << line1 << endl;
       }
   }
    
    for (int j =0; j < line2.size();) {
        char d = line2[j];
        if (isalpha(d)) {
            break;
        }
        else {
            line2.erase(j, 1);
            //cout << line2 << endl;
        }
    }
    //cout << line1 << endl;
    //cout << line2 << endl;
    
    if (line1 == line2)
        cout << "Is an anagram.";
    else
        cout << "Is not an anagram.";
    
}
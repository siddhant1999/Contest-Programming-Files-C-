//
//  main.cpp
//  j4again
//
//  Created by Siddhant Jain on 2/25/2014.
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
vector<int> party;

void invite(int num){
    int count = 0;
    for (int i = 1; i < party.size(); i++) {
        
        
        if (party[i] != 0) {
            count++;
            if (count == num) {
                count = 0;
                party[i] = 0;
                
            }
        }
        
    }
    
}

int main(void)
{
    int f;//friends
    cin >> f;
    //int fri = f;
    int r;//rounds
    cin >> r;
    f++;
    int k = 0;
    while (f--) {
        party.push_back(k);
        k++;
    }
    while (r--) {
        int temp;
        cin >> temp;
        invite(temp);
    }
    
    for (int i = 0; i < party.size(); i++) {
        if (party[i] != 0) {
            cout << party[i] << endl;
        }
    }
    
    
    
    
    
    
}



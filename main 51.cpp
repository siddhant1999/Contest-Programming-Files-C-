//
//  main.cpp
//  Rope Unfolding
//
//  Created by Siddhant Jain on 2/22/2014.
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

string reverse (string s) {
    string result=""; //create a new string and set it to the empty string
    
    for (int i=0; i<s.length( ) ; i++) { //s.length( ) returns the length of a string
        
        result = s[ i ] + result ; //take the newest character and add it before what we have already
    } 
    
    return result;
}

int main(void)
{
    
    int num;
    cin >> num;
    int qq = num -1;
    vector<string> input(num);
    while (num--) {
        string temp;
        cin >> temp;
        input[qq] = temp;
        qq--;
    }
    //for (int i =0 ; i < input.size(); i++) {
       // cout << input[i] << endl;;
    //}
    for (int i =0 ; i < input.size(); i++) {
        if ((i + 1)%2 == 0) {
            cout << reverse(input[i]);
        }
        else
        cout << input[i];
    }
}
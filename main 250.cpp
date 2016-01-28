//
//  main.cpp
//  Bits
//
//  Created by Siddhant Jain on 1/1/2014.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;
int n;
int target;
vector<string> output;
void recursion(string s, int k){
    if (s.size() == n && k == target) {
        output.push_back(s);
        return;
    }
    if(s.size() == n)
        return;
    recursion(s + "1", k + 1);
    recursion(s + "0", k);
}
int main(void){
    int num;
    cin >> num;
    while (num--) {
        cin >> n >> target;
        output.push_back("The bit patterns are");
        recursion("", 0);
        output.push_back("");
    }
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << endl;
    }
}
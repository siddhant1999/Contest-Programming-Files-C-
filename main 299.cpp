//
//  main.cpp
//  Multiple Choice
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
    int num = 0, result = 0,amo1, amo2 ;
    char submit, nothing;
    vector<char> givenans, rightans;
    cin >> num;
    amo1 = num;
    amo2 = amo1;
    nothing = cin.get();
    
    while (amo1--)
    {
        cin >> submit;
        givenans.push_back(submit);
    }
    while (amo2--)
    {
        cin >> submit;
        rightans.push_back(submit);
    }
    for (int i = 0; i < num; i++) {
        if (givenans[i] == rightans[i])
            result++;
    }
    cout << result << endl;
}
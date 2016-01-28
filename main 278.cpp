//
//  main.cpp
//  Text Messages
//
//  Created by Siddhant Jain on 1/21/2014.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

string text(string input){
    if (input == "YW")
        return "you're welcome";
    
    if (input.at(0) == ':') {
    if (input == ":-)")
        return "I'm happy";
    else
    if (input == ":-(")
        return "I'm unhappy";
        else
    if (input == ":-P")
        return "stick out my tongue";
    }
    else
    if (input == ";-)")
        return "wink";
    else
    if (input == "(~.~)")
        return "sleepy";
    else
    if (input.at(0) == 'C') {
    if (input == "CU")
        return "see you";
    else
    if (input == "CCC")
        return "Canadian Computing Competition";
    else
    if (input == "CUZ")
        return "because";
    }
    else
    if (input.at(0) == 'T') {
    if (input == "TY")
        return "thank-you";
    else
    if (input == "TTYL")
        return "talk to you later";
    else
    if (input == "TA")
        return "totally awesome";
    }
    else
    return input;
    
    return 0;
}

int main(void)
{
    string input;
    do {
        cin >> input;
        cout << text(input) << endl;
    } while (input != "ttyl");
}


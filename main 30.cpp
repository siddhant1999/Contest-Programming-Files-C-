//
//  main.cpp
//  Trik
//
//  Created by Siddhant Jain on 2014-03-11.
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
int one = 1, two = 0, three = 0;
string str;
void a(void){
    if (one == 1 || two == 1) {
    if (one == 1) {
        two = 1;
        one = 0;
    }
    else {
        two = 0;
        one = 1;
    }
}
}
void b(void){
    if (three == 1 || two == 1) {
    if (two == 1) {
        two = 0;
        three = 1;
    }
    else {
        two = 1;
        three = 0;
    }
}
}
void c(void){
    if (one == 1 || three == 1) {
    if (one == 1) {
        three = 1;
        one = 0;
    }
    else {
        three = 0;
        one = 1;
    }
}
}
void game(void){
    for (int i = 0; i < str.length(); i++) {
        char j = str[i];
        if (j == 'A')
            a();
        if (j == 'B')
            b();
        if (j == 'C')
            c();
}
}
int main(void)
{
    
    cin >> str;
    game();
    if (one == 1) {
        cout << '1';
    }
    if (two == 1) {
        cout << '2';
    }
    if (three == 1) {
        cout << '3';
    }
}
//
//  main.cpp
//  Trident
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
{
    int height, space, handle;
    cin >> height >> space >> handle;
    for (int k = 0; k < height; k++) {
        for (int i = 0;i < 2; i++) {
            cout << "*";
            for (int j = 0; j < space; j++) {
                cout << " ";
            }
        }
        cout << "*" << endl;
    }
    int line = space * 2 + 3;
    while (line--) {
        cout << "*";
    }
    cout << endl;
    for (int q = 0; q < handle; q++) {
        for (int i = 0; i < (space + 1); i++){
            cout << " ";
        }
        cout << "*" << endl;
    }
}
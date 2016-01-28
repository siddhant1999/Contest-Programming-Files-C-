//
//  main.cpp
//  Password Hacking
//
//  Created by Siddhant Jain on 2014-11-11.
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

int main(void)
{
    double done =0;
    string realpass;
    cin >> realpass;
    string campass = "";
    for (char a = 'a'; a <= 'z'; a++) {
        for (char b = 'a'; b <= 'z'; b++) {
            for (char c = 'a'; c <= 'z'; c++) {
                for (char d = 'a'; d <= 'z'; d++) {
                    for (char e = 'a'; e <= 'z'; e++) {
                        for (char f = 'a'; f <= 'z'; f++) {
                            done++;
                            campass+= a;
                            campass+= b;
                            campass+= c;
                            campass+= d;
                            campass+= e;
                            campass+= f;
                            if (campass == realpass) {
                                cout << campass << endl;
                                cout << "Computations: " << done;
                                return 0;
                            }
                            campass = "";
                        }
                    }
                }
            }
        }
    }
}


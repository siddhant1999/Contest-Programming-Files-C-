//
//  main.cpp
//  Ride
//
//  Created by Siddhant Jain on 2014-03-10.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

/*
 ID: siddhant1999
 PROG: ride
 LANG: C++
 */
#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <set>
#include <map>
#include <fstream>
using namespace std;

int main(void)
{
    long suma=1, sumb=1;
    string aone, btwo;
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    fin >> aone >> btwo;
    for (int i = 0; i < aone.length(); i++) {
        int a = aone[i];
        
        int tempa = a - 64;
        
        suma *= tempa;
        
    }
    for (int i = 0; i < btwo.length(); i++) {
        int b = btwo[i];
        int tempb = b - 64;
        sumb *= tempb;
    }
    if (suma%47 == sumb%47) {
        fout << "GO" << endl;
    }
    else {
        fout << "STAY" << endl;
    }
}








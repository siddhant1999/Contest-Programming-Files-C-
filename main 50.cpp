//
//  main.cpp
//  Clock Hands
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

int main(void)
{
    double hr, mi, se, minang, secang;
    cin >> hr >> mi >> se;
    
    int hour = hr/30, min, sec;
    
    if (mi < 360 - hr)
        minang = hr + mi;
    else {
        minang = mi - (360 - hr);
    }
    
    min = minang / 6;
    int sum = (hr + mi + se);
    //int s = ((hr + mi + se)/360);
    sec = ((hr + mi + se) - (360 * (sum/360)) )/ 6;
    
    
    if (se < 360 - minang)
        secang = minang + se;
    else {
        secang = se - (360 - minang);
    }
    //sec = secang / 6;
    
    
    if (hour == 0)
        cout <<  "12";
    else if (hour < 10){
        cout << '0' << hour;}
    else{
        cout << hour;}
    
    
    cout << ':';
    
    if (min == 60)
        cout <<  "00";
    else if (min < 10){
        cout << '0' << min;}
        else{
            cout << min;}
    
    
    cout << ':';
    
    if (sec == 60)
        cout <<  "00";
    if (sec < 10){
        cout << '0' << sec;}
    else{
        cout << sec;}
}








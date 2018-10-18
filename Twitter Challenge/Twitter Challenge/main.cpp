//
//  main.cpp
//  Twitter Challenge
//
//  Created by Siddhant Jain on 2018-01-29.
//  Copyright © 2018 Siddhant Jain. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>

using namespace std;
/*
2015-08, 2016-04
2015-08-15, clicks, 635
2016-03-24, app_installs, 683
2015-04-05, favorites, 763
2016-01-22, favorites, 788
2015-12-26, clicks, 525
2016-06-03, retweets, 101
2015-12-02, app_installs, 982
2016-09-17, app_installs, 770
2015-11-07, impressions, 245
2016-10-16, impressions, 567
*/
int krakenCount(int m, int n) {
    if(m<1 || n< 1) return 0;
    if(m==1 && n==1) return 1;
    return krakenCount(m-1, n) + krakenCount(m, n-1) + krakenCount(m-1, n-1);
}

int main(void)
{
    
    string datein, dateout;
    cin >> datein >> dateout;
    vector<pair<string, pair<string, int> > > data;
    datein.pop_back();
    while (!cin.eof()) {
        string theDate, theType;
        int count;
        cin >> theDate >> theType >> count;
        theDate.pop_back();
        theDate.pop_back();
        theDate.pop_back();
        theDate.pop_back();
        theType.pop_back();
        if (theDate < datein || theDate > dateout) {
            continue;
        }
        pair<string, pair<string, int>> p;
        p.first = theDate;
        p.second.first = theType;
        p.second.second = count;
        data.push_back(p);
    }
    
    sort(data.begin(), data.end());
    for (int i = data.size()-1; i>=0 ; i--) {
        
        if (i != data.size()-1) {
            if(data[i].first == data[i+1].first){
                cout <<  ", " << data[i].second.first << ", " << data[i].second.second;
                continue;
            }
        }
        
        cout <<endl <<  data[i].first << ", " << data[i].second.first << ", " << data[i].second.second;
    }
    
}

//
//  main.cpp
//  Topic Detection
//
//  Created by Siddhant Jain on 2017-01-21.
//  Copyright © 2017 Siddhant Jain. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
#include <fstream>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>
#include <ctime>

using namespace std;
//board = vcc (num+1, vc (num+1, 0));


#define x0 first
#define y0 second.first
#define z0 second.second

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define mpp(one,two,three) make_pair( one,  make_pair( two, three ) )
#define tp(one) cout << (one).first << " " << (one).second << endl;
#define ms(thing, val) memset( (thing), (val), sizeof(thing) )
#define mt make_tuple
#define fori(lim) for(int (i) = (0); (i) < (lim);(i)++ )
#define forj(lim) for(int (j) = (0); (j) < (lim);(j)++ )
#define fork(lim) for(int (k) = (0); (k) < (lim);(k)++ )
#define input ios::sync_with_stdio(false)
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int MAX = 1147483647;
vcc board;
vector<string> list;


int main(void)
{
    input;
    
    //this is a method of topic detection that is reliant on taking the top 100 most frequently occuring words that are also not in the 6000 most common words used in the English words
    
    /*
    ifstream myfile("sample1.txt");
    string line;
    
    ofstream outputFile("output.txt");
    vector<string> str;
    
    if (myfile)
    {
        string temp;
        myfile >> temp;
        while (temp != "zone") {
            //cout << temp;
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            //cout << " " << temp << endl;
            str.push_back(temp);
            myfile >> temp;
            
        }
        myfile.close();
        sort(str.begin(), str.end());
        fori(str.size())
            outputFile << str[i] << endl;
    }
    else cout << "fooey\n";
    */
    
    map<string, int> freq;
    
    ifstream file1("sample.txt");
    ifstream commonwords("common.txt");
    
    string s;
    commonwords >> s;
    
    while (s != "zone") {
        list.push_back(s);
        commonwords >> s;
    }
    list.push_back("zone");
    
    string str;
    file1 >> str;
    
    while (str != "siddhantjain") {
        if (!str.size()) {
            continue;
        }
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        
        for (int j = 0; j < str.length(); j++) {
            if (j < 'a' || j > 'z') {
                continue;
            }
        }
        if (str[str.length()-1] < 'a' || str[str.length()-1] > 'z') {
            str.erase(str.length()-1);
        }
        if(!(binary_search(list.begin(), list.end(), str))){
            //this means that this word is not in the dictionary
            
            if (freq.count(str)) {
                freq[str]++;
            }
            else freq[str] = 1;
        }
        file1 >> str;
    }
    //sort(freq.begin(), freq.end());
    //cout << "done";
    vector<pair<int, string>> sorted;
    for (map<string, int>:: iterator i = freq.begin(); i != freq.end(); i++) {
        pair<int, string> p;
        
        p.first = i->second;
        p.second = i->first;
        sorted.push_back(p);
        //cout << i->first << " " << i->second << endl;
    }
    
    //sort(sorted.end(), sorted.begin());
    sort(sorted.begin(), sorted.end());
    for (int i = 1; i < 100; i++) {
        cout << "'" << sorted[sorted.size()-i].second << "'  : " << sorted[sorted.size()-i].first << endl;
    }
    

}

//
//  main.cpp
//  Bananas
//
//  Created by Siddhant Jain on 2015-02-07.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
//

/*
A monkey language word is a special type of word called an A-word, which may be optionally followed by the letter N and a monkey language word.
An A-word is either only the single letter A, or the letter B followed by a monkey language word followed by the letter S.

 <M> = <A>  ||   <A>"N"<M>
 <A> = "A"  ||   "B"<M>"S"


 Here are some examples:

The word “A”' is a monkey language word because it is an A-word.
The word “ANA” is a monkey language word because it is the A-word “A” followed by the letter N and the monkey language word “A”.
The word “ANANA” is a monkey language word because it is the A-word “A” followed by the letter N and the monkey language word “ANA”.
The word “BANANAS” is a monkey language word because it is an A-word, since it is the letter B followed by the monkey language word “ANANA”followed by the letter S.
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
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;

bool checka(string x);

bool checkm(string x){
    if (checka(x))
        return true;
    
    for (int i = 1; i < x.length(); i++)
        if (x[i] == 'N')
            if( checka(x.substr(0, i)) && checkm(x.substr(i+1)))
                return true;
    
    return false;
}

bool checka(string x){
    if (x == "A") {
        return true;
    }
    if (x[0] == 'B' && x[x.length()-1] == 'S') {
        return checkm(x.substr(1, x.length()-2));
    }
    return false;
}

int main(void)
{
    while (1) {
        string temp;
        getline(cin, temp);
        if (temp == "X") {
            return 0;
        }
        if(checkm(temp))
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}


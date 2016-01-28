//
//  main.cpp
//  Multiplication Game
//
//  Created by Siddhant Jain on 2014-09-12.
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

//typedef unsigned int uint; // 2^32 - 1 = 4294967295
// long long = 64-bit numbers = 2^63 - 1 > 4 billion

typedef long long big_int;

map< big_int, bool> states;
big_int N;

// mission statement: if cur pos is k, then does cur player win ?
bool isWinning(big_int k){
    if (k >= N) {
        return false;
    }
    if (states.count(k) == 1) {
        return states[k];
    }
    cout << k << endl;
    if (k < 10) {
        cout << endl << "*****************************" << endl << endl;
    }
    for (int i = 2; i <= 9; i++)
        if ( isWinning(i * k)==false )
            return states[k] = true;
    
    return states[k] = false;
}

int main(void)
{
    cin >> N;
    cout << isWinning(1) << endl;
    cout << states.size();
}
// 2*2*2*2  == 4*4

/*boolean isWinning(position pos) {
    moves[] = possible positions to which I can move from the
    position pos;
    for (all x in moves)
        if ( isWinning(x)==FALSE )
            return true;
 
    return false;
 }
 
 Stan and Ollie play the game of multiplication by multiplying an integer p by one of the numbers 2 to 9. Stan always starts with p = 1, does his multiplication, then Ollie multiplies the number, then Stan and so on. Before a game starts, they draw an integer 1 < n < 4294967295 and the winner is who first reaches >= N
 
 13, 17, 19, 23... lots of numbers are impossible
 
 */
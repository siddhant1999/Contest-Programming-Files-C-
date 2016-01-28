//
//  main.cpp
//  Vox
//
//  Created by Siddhant Jain on 2015-02-16.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
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

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<char> vc;
typedef vector<vector<char> > vcc;

int main(void)
{
    int num;
    cin >> num;
    
    vcc board (num, vc(num, 0));
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            char temp;
            cin >> temp;
            board[i][j] = temp;
        }
    }
    bool z = true;
    int c = 0;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (board[i][j] != board[num-i-1][j]) {
                if (board[i][j] == '/' && board[num-i-1][j] != '\\') {
                    z = false;
                    break;
                }
                if (board[i][j] == '\\' && board[num-i-1][j] != '/') {
                    z = false;
                    break;
                }

            }
        
            else if (board[i][j] == '\\' || board[i][j] == '/') {
                z = false;
                break;
            }
        }
    }
    if(z) c++;
    z = true;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (board[i][j] != board[i][num-j-1]) {
                if (board[i][j] == '/' && board[i][num-j-1] != '\\') {
                    z = false;
                    break;
                }
                if (board[i][j] == '\\' && board[i][num-j-1] != '/') {
                    z = false;
                    break;
                }
                if (board[i][j] == '(' && board[i][num-j-1] != ')') {
                    z = false;
                    break;
                }
                if (board[i][j] == ')' && board[i][num-j-1] != '(') {
                    z = false;
                    break;
                }
                
            }
            
            else if (board[i][j] == '\\' || board[i][j] == '/') {
                z = false;
                break;
            }
        }
    }
    if(z) c++;
    z = true;
    cout << c;
}

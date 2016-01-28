//
//  main.cpp
//  2048
//
//  Created by Siddhant Jain on 2014-11-09.
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
map<char, int> user_input;
map<int, char> boardmap;
vector<vector<int> > board (6, vector<int>(6,-1));
vector<vector<int> > temp (6, vector<int>(6,-1));
int highscore = 0;
int tempvalue = 0;
int origx = 1;
int origy = 1;
int random_generator = 0;
double seconds_since_start;
time_t start = time(0);

int digits(int num, int dig){
    if(num/10 > 0){
        num /= 10;
        return digits(num, dig+1);
    }
    return dig + 1;
}

void randomize(){
    seconds_since_start = difftime( time(0), start);
    random_generator = rand() % 4 + 1;
    random_generator *= seconds_since_start;
    int tempx = random_generator%4 + 1 + (rand() % 4 + 1);
    tempx = tempx%4 + 1;
    random_generator = rand() % 4 + 1;
    random_generator *= seconds_since_start;
    int tempy = random_generator%4 + 1 + (rand() % 4 + 1);
    tempy = tempy%4 + 1;
    
    if (board[tempx][tempy] == -1) {
        board[tempx][tempy] = 2;
        return;
    }
    else{
        randomize();
    }
   
}

bool up(int x, int y, int value){
    //cout << "x: " << x << " y: " << y << " value: " << value << endl;
    //cout << "current config: " << board[1][origy] << " " << board[2][origy] << " " << board[3][origy] << " " << board[4][origy] << endl;
    if (x > 4 || x < 1 || y < 1 || y > 4)
        return false;
    
    if (value == -1) {
        if (board[x][y] > 1) {
            tempvalue =board[x][y];
            board[x][y] = -1;
            return true;
        }
    }
    
    if (value == -17) {
        if (up(x+1, y, board[x][y])) {
            if (board[x][y] != -1) {
                board[x][y] *= 2;
                highscore += board[x][y];
            }
            if (board[x][y] == -1) {
                board[x][y] = tempvalue;
                up(x, y, -17);
            }
        }
        x++;
        if (x > 4 || x < 1 || y < 1 || y > 4)
            return false;
        
        up(x, y, -17);
    }
    
    if (board[x][y] == -1)
        return up(x+1, y, value);
    
    if (board[x][y] == 0)
        return false;
    
    if (board[x][y] > 1 && board[x][y] != value)
        return false;
    
    if (board[x][y] > 1 && board[x][y] == value) {
        board[x][y] = -1;
        return true;
    }
    return false;
}
bool right(int x, int y, int value){
    //cout << "x: " << x << " y: " << y << " value: " << value << endl;
    //cout << "current config: " << board[origx][1] << " " << board[origx][2] << " " << board[origx][3] << " " << board[origx][4] << endl;
    if (x > 4 || x < 1 || y < 1 || y > 4)
        return false;
    
    if (value == -1) {
        if (board[x][y] > 1) {
            tempvalue =board[x][y];
            board[x][y] = -1;
            return true;
        }
    }
    
    if (value == -17) {
        if (right(x, y-1, board[x][y])) {
            if (board[x][y] != -1) {
                board[x][y] *= 2;
                highscore += board[x][y];
            }
            if (board[x][y] == -1) {
                board[x][y] = tempvalue;
                right(x, y, -17);
            }
        }
        y--;
        if (x > 4 || x < 1 || y < 1 || y > 4)
            return false;
        
        right(x, y, -17);
    }
    
    if (board[x][y] == -1)
        return right(x, y-1, value);
    
    if (board[x][y] == 0)
        return false;
    
    if (board[x][y] > 1 && board[x][y] != value)
        return false;
    
    if (board[x][y] > 1 && board[x][y] == value) {
        board[x][y] = -1;
        return true;
    }
    return false;

}
bool down(int x, int y, int value){
    
    //cout << "x: " << x << " y: " << y << " value: " << value << endl;
    //cout << "current config: " << board[1][origy] << " " << board[2][origy] << " " << board[3][origy] << " " << board[4][origy] << endl;
    if (x > 4 || x < 1 || y < 1 || y > 4)
        return false;
    
    if (value == -1) {
        if (board[x][y] > 1) {
            tempvalue =board[x][y];
            board[x][y] = -1;
            return true;
        }
    }
    
    if (value == -17) {
        if (down(x-1, y, board[x][y])) {
            if (board[x][y] != -1) {
                board[x][y] *= 2;
                highscore += board[x][y];
            }
            if (board[x][y] == -1) {
                board[x][y] = tempvalue;
                
                down(x, y, -17);
            }
        }
        x--;
        if (x > 4 || x < 1 || y < 1 || y > 4)
            return false;
        
        down(x, y, -17);
    }
    
    if (board[x][y] == -1)
        return down(x-1, y, value);
    
    if (board[x][y] == 0)
        return false;
    
    if (board[x][y] > 1 && board[x][y] != value)
        return false;
    
    if (board[x][y] > 1 && board[x][y] == value) {
        board[x][y] = -1;
        return true;
    }
    return false;

}
bool left(int x, int y, int value){
    //cout << "x: " << x << " y: " << y << " value: " << value << endl;
    //cout << "current config: " << board[origx][1] << " " << board[origx][2] << " " << board[origx][3] << " " << board[origx][4] << endl;
    if (x > 4 || x < 1 || y < 1 || y > 4)
        return false;
    
    if (value == -1) {
        if (board[x][y] > 1) {
            tempvalue =board[x][y];
            board[x][y] = -1;
            return true;
        }
    }
    
    if (value == -17) {
        if (left(x, y+1, board[x][y])) {
            if (board[x][y] != -1) {
                board[x][y] *= 2;
                highscore += board[x][y];
            }
            if (board[x][y] == -1) {
                board[x][y] = tempvalue;
                left(x, y, -17);
            }
        }
        y++;
        if (x > 4 || x < 1 || y < 1 || y > 4)
            return false;
        
        left(x, y, -17);
    }
    
    if (board[x][y] == -1)
        return left(x, y+1, value);
    
    if (board[x][y] == 0)
        return false;
    
    if (board[x][y] > 1 && board[x][y] != value)
        return false;
    
    if (board[x][y] > 1 && board[x][y] == value) {
        board[x][y] = -1;
        return true;
    }
    return false;
    
}

int main(void)
{
    cout << "Enter 'W','A','S','D' to control" << endl <<"'H' to view Current Highscore and 'Q' to Quit";
    cout << endl << "Commands are not Case Sensistive" << endl << endl;
    random_generator = rand() % 4 + 1;
    board[random_generator][rand() % 4 + 1] = 2;
    //cout the currently existing board and use that rand() to at least have two values
    user_input['w'] = 1;//up
    user_input['d'] = 2;//right
    user_input['s'] = 3;//down
    user_input['a'] = 4;//left
    
    user_input['W'] = 1;
    user_input['D'] = 2;
    user_input['S'] = 3;
    user_input['A'] = 4;
    
    user_input['h'] = 5;//highscore
    user_input['q'] = 6;//quit
    user_input['H'] = 5;
    user_input['Q'] = 6;
    
    boardmap[-1] = '.';
    char input;
    
    for (int i = 0; i <= 5; i++) {
        board[0][i] = 0;
        board[5][i] = 0;
        board[i][0] = 0;
        board[i][5] = 0;
    }
    
    //testcase
    /*
    board[1][1] = 4;
    board[1][2] = 8;
    //board[1][3] = 4;
    board[1][4] = 2;
    
    //board[2][1] = 2;
    board[2][2] = 8;
    //board[2][3] = 2;
    board[2][4] = 2;
    
    board[3][1] = 2;
    board[3][2] = 4;
    //board[3][3] = 2;
    board[3][4] = 2;
    
    board[4][1] = 2;
    board[4][2] = 4;
    board[4][3] = 2;
    board[4][3] = 2;
    */
    for (int i = 1; i <=4; i++) {
        for (int j = 1; j <=4; j++) {
            temp[i][j] = board[i][j];
            cout << '[';
            if (board[i][j] == -1) {
                cout << ' ';
            }
            else
                cout << board[i][j];
            cout << ']';
        }
        cout << endl;
    }
    
    do {
        cin >> input;
        
        if (user_input[input] == 5) {
            cout << "Your Current Highscore Is: "<<  highscore << endl;
        }
        else if(user_input[input] != 6){
            if (user_input[input] == 1) {
                for (int i = 1; i <= 4; i++){
                    origx = 1;
                    origy = i;
                    up(1,i, -17);
                    
                }
            }
            if (user_input[input] == 2) {
                for (int i = 1; i <= 4; i++){
                    origx = i;
                    origy = 4;
                    right(i,4, -17);
                }            }
            if (user_input[input] == 3) {
                for (int i = 1; i <= 4; i++){
                    origx = 4;
                    origy = i;
                    down(4,i, -17);
                }
            }
            if (user_input[input] == 4) {
                for (int i = 1; i <= 4; i++){
                    origx = i;
                    origy = 1;
                    left(i,1, -17);
                }
            }
        }
        cout << endl<< endl;
        //check if full
        int tt = 1;
        int maxnum = 0;
        bool checker = false;
        for (int i = 1; i <=4; i++) {
            for (int j = 1; j <=4; j++) {
                if (board[i][j] != temp[i][j]) {
                    checker = true;
                }
                if (board[i][j] == -1) {
                    tt = 0;
                }
                
                maxnum = max(maxnum, board[i][j]);
            }
        }
        if (tt == 1) {
            cout << "Game Over" << endl;
            cout << "Your Highscore Is: "<<  highscore << endl;
            cout << "Thank You For Playing" << endl;
            return 0;
        }
        if (user_input[input] != 5 && checker == true)
            randomize();
        
        maxnum = digits(maxnum, 0);
        
        for (int i = 1; i <=4; i++) {
            for (int j = 1; j <=4; j++) {
                
                if (board[i][j] == -1) {
                    cout << '[';
                    int maxi = maxnum;
                    while (maxi--) {
                        cout << ' ';
                    }
                    cout << ']';
                }
                else{
                    
                temp[i][j] = board[i][j];
                cout << '[';
                int number = digits(board[i][j], 0);
                int tempspace = (maxnum - number);// the problem is proably here
                int orig = tempspace;
                if (orig%2 == 1)
                    orig = orig/2 + 1;
                else
                    orig /= 2;
                //cout << tempspace;
                while (orig--) {
                    cout << ' ';
                }
                    cout << board[i][j];
                
                    if ((tempspace - 1) >= 0) {
                        tempspace--;
                    }
                    if (number  == 1 && tempspace > 1 && tempspace%2 == 0) {
                        tempspace--;
                    }
                
                while (tempspace--) {
                    cout << ' ';
                }
                cout << ']';
                }
            }
            cout << endl;
        }
        //cout << seconds_since_start << endl;
    } while (user_input[input] != 6);
    
    cout << "Your Highscore Is: "<<  highscore << endl;
    cout << "Thank You For Playing" << endl;
}


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
int curloc = 1;

string game(int loc){
    if (loc == 54 || loc == 90 || loc == 99 || loc == 9 || loc == 40 || loc == 67) {
    if (loc == 54)
        curloc = 19;
    if (loc == 90)
        curloc = 48;
    if (loc == 99)
        curloc = 77;
    if (loc == 9)
        curloc = 34;
    if (loc == 40)
        curloc = 64;
    if (loc == 67)
        curloc = 86;
    }
    else curloc = loc;
    
    return "You are now on square ";
}

int main(void)
{
    int num;
    while (1) {
        cin >> num;
        if (num == 0) {
            cout << "You are now on square " << curloc << endl;
            cout << "You Quit!";
            return 0;
        }
        if (curloc + num <= 100) {
            cout << game(curloc + num)<< curloc << endl;
        }
        if (curloc == 100) {
            cout << "You Win!";
        }
    }
}
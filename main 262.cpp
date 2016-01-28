//
//  main.cpp
//  Test
//
//  Created by Siddhant Jain on 2014-08-12.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <iostream>
/*
class Book
{
    //Attributes, state of this class
    int pageNo;
    int maxPageNo;
    char *autherName;
    char *title;
    
    
    //Methods,  bahaviour of class
    void nextPage()
    {
        pageNo++;
    }
    
    void setInit()
    {
        pageNo = 0;
        maxPageNo = 55;
    }
    
};
*/

public class Clock {
    int time;
    int size;
    int colour;
    bool isdigital;
    int hour,int min, int sec;
    bool isPaused;
    
    void Clock()
    {
        isPaused = true;
        hour = 0;
        //the rest
        
    }
    
    bool setTime(int h, int m, int s){
        hour = h;
        min = m;
        sec = s;
    }
    
    string getTime(){
        //string curstr = "";
        return (hour + ':' + min + ':' + sec);
    }
    
    void working(){
        
        if( !isPaused )
        {
        sec++;
        
        if (sec >= 60) {
            sec = 0;
            min++;
        }
        if (min >= 60) {
            min = 0;
            hour++;
        }
        if (hour >= 13) {
            hour = 1;
        }
        }
    }
    
    void eventSecondCounter()
    {
        working();
    }
    
    void pauseResumeClock()
    {
        isPaused = !isPaused;
    }
    
    
    
};

class DigitalClass : clock
{
    char *ringTone;
    
    
    void playRingTone()
    {
        //
    }
};

int main(int argc, const char * argv[])
{
    Clock e;
    DigitalClass d;
    
    int *a;
    float *v;
    
    v = a;
    
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}


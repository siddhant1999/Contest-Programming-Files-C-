//
//  main.cpp
//  Rock Paper Scissors
//
//  Created by Siddhant Jain on 10/28/2013.
//  Copyright (c) 2013 Siddhant Jain. All rights reserved.
//

#include <stdio.h>
#include <string.h>


int p1; // #of times player 1 has won
int p2; // #of times player 2 has won
int tie; // #of times games tied
int go = 1; // to go again
int i;
int against;

int player1won(void){
    printf("Player 1 won!\n\n");
    p1++;
    return 0;
}

int player2won(void) {
    printf("Player 2 won!\n\n");
    p2++;
    return 0;
}

int switch1(int secin){
    switch (secin) {
        case 3:
        case 4:
            player1won();
            
            break;
        default:
            player2won();
            break;
    }
    return 0;
}

int switch2(int secin){
    switch (secin) {
        case 1:
        case 5:
            player1won();
            break;
        default:
            player2won();
            break;
    }

    return 0;
}

int switch3(int secin){
    switch (secin) {
        case 2:
        case 4:
            player1won();
            break;
        default:
            player2won();
            break;
    }
    
    return 0;
}


int switch4(int secin){
    switch (secin) {
        case 2:
        case 5:
            player1won();
            break;
        default:
            player2won();
            break;
    }
    
    return 0;
}


int switch5(int secin){
    switch (secin) {
        case 1:
        case 3:
            player1won();
            break;
        default:
            player2won();
            break;
    }
    
    return 0;
}



int compare(int input1 , int input2){
    switch (input1) {
        case 1:
            switch1(input2);
            break;
           
        case 2:
            switch2(input2);
            break;
            
        case 3:
            switch3(input2);
            break;
            
        case 4:
            switch4(input2);
            break;
            
        case 5:
            switch5(input2);
            break;
            
        default:
            break;
    }
    return 0;
}


int main(void)
{
    //printf("Do you wish to play against the computer (1 for yes, 2 for no): ");
   // scanf("%d", &against)
    for (i = 0;go == 1; i++) {
        
        int input1;
        int input2;
        
        printf("1) Rock\n"
               "2) Paper\n"
               "3) Scissors\n"
               "4) Lizard\n"
               "5) Spock\n"
               "Player 1, enter your move (1 - 5): ");
        scanf("%d", &input1);
        printf("Player 2, enter your move (1 - 5): ");
        scanf("%d", &input2);
        if (input1 == input2) {
            printf("Tie Game\n");
            tie++;
        }
        else {
            compare(input1, input2);
        }
        printf("Do you wish to go again? (1 for yes, 2 for no): ");
        scanf("%d", &go);
    }
    
    printf("--------------------------------------------------\n");
    printf("                    Statistics\n");
    printf("--------------------------------------------------\n");
    printf("Number of games played: %d\n", i);
    printf("Number of games won by Player 1: %d\n", p1);
    printf("Number of games won by Player 2: %d\n", p2);
    printf("Number of games Tied: %d\n", tie);
    
    //float pp1 = p1;
    //float pp2 = p2;
    
    
    float percent1 = (float(p1) / i) * 100;
    float percent2 = (float(p2) / i) * 100;
    
    
    printf("Player 1 win Percent: %0.2lf\n", percent1);
    printf("Player 2 win Percent: %0.2lf\n", percent2);
    
    
}


#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char **argv)
{
    char bandOne, bandTwo, bandMult, bandTol;
    char colorOne, colorTwo, colorThree, colorFour;
    int i;
    double firstNumber, secondNumber, multiplier, tolerance;
    double resistance, combined;
    
    // Asks for the four inputs
    printf("Please enter the 1st band: \n");
    scanf(" %c", &bandOne);
    
    printf("Please enter the 2nd band: \n");
    scanf(" %c", &bandTwo);
    
    printf("Please enter the multiplier band: \n");
    scanf(" %c", &bandMult);
    
    printf("Please enter the tolerance band: \n");
    scanf(" %c", &bandTol);
    
    // Array of the possible valid inputs
    char band_arr[12][2] = {
        {'K', 'k'},
        {'B', 'b'},
        {'R', 'r'},
        {'O', 'o'},
        {'E', 'e'},
        {'G', 'g'},
        {'U', 'u'},
        {'V', 'v'},
        {'Y', 'y'},
        {'W', 'w'},
        {'L', 'l'},
        {'S', 's'}
    };
    
    // toupper
    
    // Array of the full color names
    char color_arr[12][10] = {
        {"Black"},
        {"Brown"},
        {"Red"},
        {"Orange"},
        {"Yellow"},
        {"Green"},
        {"Blue"},
        {"Violet"},
        {"Grey"},
        {"White"},
        {"Gold"},
        {"Silver"}
    };
    
    // Array with each band's numerical value
    // Includes 1st and 2nd band, multiplier, and tolerance values
    double resistance_arr[12][4] = {
        {0, 0, 1, 0},
        {1, 1, 10, 1},
        {2, 2, 100, 2},
        {3, 3, 1000, 0},
        {4, 4, 10000, 0},
        {5, 5, 100000, 0.5},
        {6, 6, 1000, 0.25},
        {7, 7, 10000, 0.1},
        {8, 8, 0, 0.05},
        {9, 9, 0, 0},
        {0, 0, 0.1, 5},
        {0, 0, 0.01, 10}
    };
    
    int a, b, c, d;
    
    // This loop runs through all of the possible indexes of the arrays
    for(i = 0; i < 12; i++){
        
        // This condition checks if any of the user's inputs match with the values stored in band_arr.
        // If there is a match, "i" retains the index of the value. The index number will be used to find subsequent values.
        if (bandOne == band_arr[i][0] || bandOne == band_arr[i][1]) {
            
            // This assigns the string found at position [i] in the color array to the variable colorOne
            a = i;
            //            colorOne = *color_arr[i];
            // This assigns the resistance value found at position [i][0] in the resistance array to the variable firstNumber
            firstNumber = resistance_arr[i][0];
        }
        
        if (bandTwo == band_arr[i][0] || bandTwo == band_arr[i][1]) {
            b = i;
            //            colorTwo = *color_arr[i];
            secondNumber = resistance_arr[i][1];
        }
        
        if (bandMult == band_arr[i][0] || bandMult == band_arr[i][1]) {
            c = i;
            //            colorThree = *color_arr[i];
            multiplier = resistance_arr[i][2];
        }
        
        if (bandTol == band_arr[i][0] || bandTol == band_arr[i][1]) {
            d = i;
            //            colorFour = *color_arr[i];
            tolerance = resistance_arr[i][3];
        }
        
    }
    
    combined = (firstNumber * 10) + secondNumber;
    resistance = multiplier * (combined);
    
    
    printf("Resistor bands: ");
    
    
    
    
    
    
    // ADDED
    
    int j;
    
    for (j=0; j < strlen(color_arr[a]); j++){
        printf("%c ", color_arr[a][j]);
    }
    
    for (j=0; j < strlen(color_arr[b]); j++){
        printf("%c ", color_arr[b][j]);
    }
    
    for (j=0; j < strlen(color_arr[c]); j++){
        printf("%c ", color_arr[c][j]);
    }
    
    for (j=0; j < strlen(color_arr[d]); j++){
        printf("%c ", color_arr[d][j]);
    }
    
    
    
    
    
    
    
    if (multiplier >= 100000) {
        printf("Resistance: %.2lf MOhms +/- %.2lf%% \n", resistance/1000000, tolerance);
    }


else if (multiplier >= 1000) {
    printf("Resistance: %.2lf KOhms +/- %.2lf%% \n", resistance/1000, tolerance);
}

else {
    printf("Resistance: %.2lf Ohms +/- %.2lf%% \n", resistance, tolerance);
}

return 0;
}

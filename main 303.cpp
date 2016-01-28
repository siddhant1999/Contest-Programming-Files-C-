//
//  main.cpp
//  Junior 2013 Questions 1-2
//
//  Created by Siddhant Jain on 10/10/13.
//  Copyright (c) 2013 Siddhant Jain. All rights reserved.
//

#include <stdio.h>
#include <string.h>



/*bool contains( char c, char *s ){
 for( int j=0; j<strlen(s); j++){
 char current_letter = s[j];
 
 if(current_letter == c){
 return true;
 printf("This letter works\n");
 
 }
 }
 return false;
 }
 
 int main(void) {
 char word[31];
 scanf("%s", word);
 char allowed[8] =  "IOSHZXN";
 for ( int i=0; i<strlen(word); i++ ){
 
 if(contains(word[i], allowed) == false)
 {
 puts("NO");
 return 0;
 }
 }
 puts("YES");
 }
 */

/*int main(void) {
    
    int j = 0;
    double n = 9;
    for (int i = 1; i < 99; i++) {
        n = n * 9;
        double t = n;
        if (t > 1) {
            t = t/10;
            j++;
        }
        printf("%d.   %.0lf       %d\n",i+1,n,j+1);
    }
   
}
 */

int main(void){
    
    for (double i= 0;; i++) {
        printf("%.0lf\n", i);
    }
    /*double n = 1;
    printf("1\n");
    for (int i = 0; i < 100; i++) {
        n = n * 10;
        printf("%d.   %.0lf\n",i+1,n);*/
    }












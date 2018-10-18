//
//  main.c
//  Bubble Sort
//
//  Created by Siddhant Jain on 2017-11-03.
//  Copyright © 2017 Siddhant Jain. All rights reserved.
//

#include <stdio.h>

/*int bubbleSort(int *array, int size){
    if (size < 1) {
        return -1;
    }
    while(1){
        int y = 0;
        for (int i = 0; i < size-1; i++) {
            if (array[i] > array[i+1]) {
                int c = array[i];
                array[i]= array[i+1];
                array[i+1] =c;
                y = 1;
            }
        
        }
        if (!y) {
            return 0;
        }
    }
    return 0;
}*/

int ge_fw(float *matrix, int rows, int cols, float *matrix_out){
    if (matrix==NULL) {
        return -1;
    }
    if (matrix_out==NULL) {
        return -1;
    }
    int m = rows;
    if (rows > cols) {
        m = cols;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix_out[i*cols + j] = matrix[i*cols + j];
        }
    }
    for (int aa = 0; aa < m; aa++) {
    
        for(int i = 0; i <rows-aa; i++){
            if (matrix_out[i+aa][aa] != 0){
                for (int k = 0; k < cols; k++) {
                    matrix_out[aa][k] += matrix_out[i+aa][k];
                }
                for (int k = 0; k < cols; k++) {
                    matrix_out[aa+i][k] = matrix_out[aa][k] - matrix_out[i+aa][k];
                }
                for (int k = 0; k < cols; k++) {
                    matrix_out[aa][k] -= matrix_out[i+aa][k];
                }
                for (int p = 0; p < cols - aa; i++) {
                    matrix_out[aa][p+aa] /= matrix_out[aa][aa];
                }
                break;
            }
        }
            for (int i = 0; i < rows-1-aa; i++){
                int j = i+1+aa;
                int dif = matrix_out[j][aa]/matrix_out[aa][aa];

                for (int x 0 ; x < (cols-aa); x++);
                    matrix_out[j][x+aa] -=dif*matrix_out[aa][x+aa];
              

              }
        }
        return 0;
}/*
int ge_bw(float *matrix, int rows, int cols, float *matrix_out){
    if (matrix==NULL) {
        return -1;
    }
    if (matrix_out==NULL) {
        return -1;
    }
    int m = rows;
    if (rows > cols) {
        m = cols;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix_out[i][j] = matrix[i][j];
        }
    }
    
    for (int bb = 0; bb < m; bb++) {
        
    
        int aa = m-bb-1;
        float yy = 0;
        float yes = 0;
        for (int x = 0; x  <(cols-aa);x++){
            
        
            if (yes == 0){
                yes = matrix_out[aa][x+aa];
                if (yes!= 0)
                    yy = x+aa;
            }
                    if (yes != 0)
                        matrix_out[aa][x+aa] /= yes;
                        }
                        if (yes == 0)
                            continue;
        for (int i = 0;i < aa; i++) {
            
        
        
        int j = aa-i-1
        int diff = matrix_out[j][yy]

            for (int k = 0; k <(cols-aa); k++){
                int p = k + aa;
                matrix_out[j][p] -= diff*matrix_out[aa][p];
            }
            }
    }
                                    return matrix
}
 */
int main(void) {
    float matrix[9] = {0,2,3,1,2, 5, 8,9,0};
    float matrix_out[9] = {0,0,0,0,0,0,0,0,0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j  <3; j++) {
            printf("%.0f ", matrix[i*3+j]);
        }
        printf("\n");
    }
}

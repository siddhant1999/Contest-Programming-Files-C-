//
//  main.cpp
//  Quadtree
//
//  Created by Siddhant Jain on 2/21/2014.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//


#include <stdio.h>
FILE *in,*out;

#define max(x,y) (x)>(y)?(x):(y)

int matrix[33][33],matrix2[33][33];
char string[128],string2[128];
int string_i;

void recurse( int i, int j, int len ){
    int x,y;
    
    string_i++;
    switch( string[string_i-1] ){
        case 'p':
            recurse( i, j+len/2, len/2 );
            recurse( i, j, len/2 );
            //string_i++;
            
            //string_i++;
            recurse( i+len/2, j, len/2 );
            //string_i++;
            recurse( i+len/2, j+len/2, len/2 );
            //string_i++;
            break;
            
        case 'f':
            for ( x=j; x<j+len; x++ )
                for ( y=i; y<i+len; y++ )
                    matrix[y][x]=1;
            break;
            
        case 'e':
            for ( x=j; x<j+len; x++ )
                for ( y=i; y<i+len; y++ )
                    matrix[y][x]=0;
            break;
    }
    
}

void recurse2( int i, int j, int len ){
    int x,y;
    
    string_i++;
    switch( string2[string_i-1] ){
        case 'p':
            //string_i++;
            recurse2( i, j+len/2, len/2 );
            recurse2( i, j, len/2 );
            //string_i++;
            
            //string_i++;
            recurse2( i+len/2, j, len/2 );
            //string_i++;
            recurse2( i+len/2, j+len/2, len/2 );
            //string_i++;
            break;
            
        case 'f':
            for ( x=j; x<j+len; x++ )
                for ( y=i; y<i+len; y++ )
                    matrix2[y][x]=1;
            break;
            
        case 'e':
            for ( x=j; x<j+len; x++ )
                for ( y=i; y<i+len; y++ )
                    matrix2[y][x]=0;
            break;
    }
    
}

int main( void ){
    in=stdin; //fopen( "quad.in", "r" );
    out=stdout; //fopen( "quad.out", "w" );
    
    int cases,i,j,k;
    
    fscanf( in, "%d", &cases );
    
    while ( cases-- ){
        fscanf( in, "%s %s", string, string2 );
        string_i=0;
        recurse( 1,1,32 );
        string_i=0;
        recurse2( 1,1,32 );
        int count=0;
        fputc( '\n', out );
        for ( i=1; i<=32; i++ ){
            for ( j=1; j<=32; j++ ){
                int val=max( matrix[i][j], matrix2[i][j] );
                printf( "%d", val );
                count+=val;
                
            }
                
                //fprintf( out, "%d", matrix[i][j] );
            
            fputc( '\n', out );
        }
        fputc( '\n', out );
        
        fprintf( out, "there are %d black pixels\n", count );
    }
    
}
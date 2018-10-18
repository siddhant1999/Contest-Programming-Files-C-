int swap(int *a, int *b){
    printf("%d %d\n", &a, *b);
    int c= *a;
    *a=*b;
    *b=c;
    //printf("%d %d\n", &a, &b);
    return 1;
}

void main(int argc,char *argv[]){
    int a=100,x=100;
    int b=1000,y=1000;
    int r;
    float score=0, total=0;
    
    total += 100;
    r=swap(&x,&y);
    printf("%d\n", r);
    printf("%d\n", x);
    printf("%d\n", y);
    if ( (x==b) && (y==a) ){
        score +=100;
        printf("here");
    }
    
    
    printf("SCORE:\"%s\",%d\n",argv[1],(int)(score*100/total));
}


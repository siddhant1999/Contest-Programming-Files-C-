#include<stdio.h>
#include<stdlib.h>

struct bondNode;
struct atom;

struct bondNode {
    int strength;
    struct atom *pAtom;
    struct bondNode *pNext;
};

struct atom {
    int atomicNumber;
    struct bondNode *bondList;
};

typedef struct bondNode bondNode;
typedef struct atom atom;

int addBond(atom *pAtom, int strength, atom *pAtom2);
atom *createAtom(int atomicNumber);
int bondList_add(bondNode **ppList, int strength, atom *pAtom);
int printAtom(atom *pAtom,int n);
int printBonds(bondNode *pList,int n);

atom *createAtom(int atomicNumber) {
    atom *p=(atom *)malloc(sizeof(atom));
    p->atomicNumber = atomicNumber;
    p->bondList = NULL;
    return p;
}

int bondList_add(bondNode **ppList, int strength, atom *pAtom) {
    if (ppList == NULL) { return -1; }
    if (*ppList == NULL) {
        *ppList = (bondNode *)malloc(sizeof(bondNode));
        (*ppList)->strength=strength;
        (*ppList)->pAtom=pAtom;
        (*ppList)->pNext=NULL;
        return 0;
    } else {
        return bondList_add( &((*ppList)->pNext), strength, pAtom );
    }
}

int addBond(atom *pAtom, int strength, atom *pAtom2) {
    if (pAtom == NULL) { return -1; }
    
    return bondList_add( &(pAtom->bondList), strength, pAtom2);
}

int printAtom(atom *pAtom,int n) {
    int i;
    if (pAtom == NULL) {
        printf("black hole sun...\n");
    } else {
        for(i=0;i<n;i=i+1) {
            printf("   ");
        }
        printf("-> atomic number=%d: bonded to:\n",pAtom->atomicNumber);
        for(i=0;i<n;i=i+1) {
            printf("   ");
        }
        printf("<- atomic number=%d\n",pAtom->atomicNumber);
        
    }
    return 0;
}

int printBonds(bondNode *pList,int n) {
    int i;
    for(i=0;i<n;i=i+1) {
        printf("   ");
    }
    if (pList == NULL) {
        printf("no bonds\n");
    } else {
        printf("strength=%d connected to:\n",pList->strength);
        printAtom(pList->pAtom,n+1);
        printBonds(pList->pNext,n);
    }
    return 0;
}
int counter = 1;

int* reall(int **p, int* s){
    int y =0, j =0, i =0;
    int *op;
    for (; i<*s; i+=2) {
        if ((*p)[i] == 0) {
            y=i;
            break;
        }
    }
    *s = y;
    op = (int *) malloc(sizeof(int)*y);
    for (; j < y; j++) {
        (op)[j] = (*p)[j];
    }
    return op;
}

int** allocate(int ** op, int *s){
    int i = 0;
    *op = (int *) malloc(sizeof(int)*100);
    s = (int*) malloc(sizeof(int));
    *s = 100;
    
    
    for (; i < *s; i++) {
        (*op)[i]= 0;
    }
    return op;
}
int first = 1;

int genFormula(atom *pAtom,int **output, int *size)
{
    int isfirst = 0;
    int at = pAtom->atomicNumber;
    int i, j,swapped = 1, li = -1, exists=0, temp, tt;
    bondNode *jamesbond;
    
    if (first) {
        output =allocate(output, size);
        *size =1000;
        isfirst = 1;
    }
    first = 0;
    
    
    if (pAtom == NULL) return -1;
    if (output == NULL) return -1;
    if (*size%2 || size == NULL ) return -1;
    
    
    for (i = 0; i < *size; i+=2) {
        if ((*output)[i] == at) {
            (*output)[i+1]++;
            exists =1;
            break;
        }
        if ((*output)[i+1] != 0) {
            li = i+1;
        }
    }
    li++;
    
    if (!exists) {
        (*output)[li]=at;
        (*output)[li+1]=1;
    }
    
    while (swapped) {
        swapped = 0;
        for (j = 0; j < *size-2; j+=2) {
            if ((*output)[j] > (*output)[j+2] && (*output)[j+2] != 0) {
                temp = (*output)[j];
                tt = (*output)[j+1];
                (*output)[j] = (*output)[j+2];
                (*output)[j+1] = (*output)[j+3];
                (*output)[j+2] = temp;
                (*output)[j+3] = tt;
                
                swapped = 1;
            }
        }
    }
    if (pAtom->bondList == NULL) return 0;
    
    
    jamesbond = pAtom->bondList->pNext;
    
    while (jamesbond != NULL) {
        genFormula((jamesbond->pAtom), output, size);
        jamesbond = jamesbond->pNext;
    }
    if (pAtom->bondList->pAtom != NULL) {
        genFormula((pAtom->bondList->pAtom), output, size);
    }
    if (isfirst) {
        *output =reall(output, size);
    }
    return 0;
}


int main(void) {
    int r=0;
    atom *S;
    int i;
    atom *tmp1,*tmp2;
    int *output = NULL;
    int s;
    S = createAtom(16);
    
    tmp1=createAtom(8);
    r=addBond(S,2,tmp1);
    
    tmp1=createAtom(8);
    r=addBond(S,2,tmp1);
    
    tmp1=createAtom(8);
    tmp2=createAtom(1);
    r=addBond(tmp1,1,tmp2);
    r=addBond(S,1,tmp1);
    
    tmp1=createAtom(8);
    tmp2=createAtom(1);
    r=addBond(tmp1,1,tmp2);
    r=addBond(S,1,tmp1);
    
    genFormula(S,&output, &s);
    for (i = 0; i < s; i++) {
        printf("%d: %d\n", i,output[i]);
    }
    return 0;
}

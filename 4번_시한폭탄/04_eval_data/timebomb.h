#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int N, b, Limit, called = 0;
int* Box;

void box_ready(){
	int ddd;
	scanf("%d", &ddd);
    scanf("%d", &N);
	scanf("%d", &ddd);
    Limit = N + (int)ceil(log(N) / log(2)) + 3;
    Box = (int*)malloc(sizeof(int) * (N + 1));
	scanf("%d", &ddd);
    for (int i = 1; i <= N; i++){
        scanf("%d", &b);
        Box[i] = b;
    }
	scanf("%d", &ddd);
}

int box_size(){ return N; }

int box_comp(int i , int  j){
    called = called + 1;
    if (called > Limit){
        printf("Function call limit over");
        free(Box);
        exit(0);
    }
    
    if (i <= 0 || i > N || j <= 0 || j > N) {
        printf("index out of range : box_comp(%d, %d)\n",i,j);
        return 0;
    }
    if (Box[i] < Box[j])
        return -1;
    else if (Box[i] > Box[j])
        return 1;
    return 0;
}

void box_report(int w){
	printf("%d", w);
	free(Box);
    exit(0);
}
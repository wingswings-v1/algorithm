/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

//combination 조합 : nCr n개중 r개의 요소를 선택하는 경우의 수 
// 모든 조합의 경우의 수는 : 2의 n승 
#define N 3

char array[N] = {'A','B','C'};
// 공집합, A, B, C, AB, AC, BC, ABC
// 0, 001, 010, 100, 011, 101, 110, 111
// 2*3 2*2 2*1 2*0 
// 8 4 2 1 

// 1  --> 001
// 2  --> 010
// 3  --> 011
// 4  --> 100
// 5  --> 101
// 6  --> 110
// 7  --> 111
// 8  --> 1000

//3개의 원소 중 2 요소를 선택해 조합을 만드는 경우의 수 
void combination_v1(){
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            printf("{%c%c}\n", array[i], array[j]);
        }
    }
}
//모든 조합의 경우의 수를 구하는 경우의 수
void combination_v2(){
    for(int i=0; i<(1<<N); i++){
        int bit = i;
        int idx = 0;
        printf("{");
        while(bit){
            if(bit&1){
                printf("%c", array[idx]);
            }
            idx++;
            bit = bit >> 1;
        }
        printf("}\n");
    }
}

int main()
{
    //combination_v1();
    combination_v2();

    return 0;
}

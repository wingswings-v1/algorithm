/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>

//순열 permutation --> nPr = nCr * rPr 
//  설명1: n개중 r을 선택해 조합을 만들고 그 조합의 요소의 순서가 다른 경우의 수를 만드는 것이다.
//  키포인트: 순서가 다르다는 것 / n!의 경우의 수를 갖는다.
// 방법 1 for문 사용하기 / 방법 2 재귀함수 사용하기 / 방법 3 재귀함수와 bit 연산자 이용하기 
#define N 3

char array[N] = {'A','B','C'}; // ABC, ACB, BAC, BCA, CAB, CBA 
void permutation_v1(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i == j) continue;
            for(int k=0; k<N; k++){
                if(i == k || j == k) continue;
                    printf("{%c%c%c}\n", array[i], array[j], array[k]);
            }
        }
    }
}

char visit[3] = {-1,};
int visit_count = 0;
int chk_visit(char visit[3], int index){
        for(int k=1; k<=visit_count; k++){
            if(visit[k] == index)  return 0;
        }
        return 1;
}

void permutation_v2(char visit[3], int visit_count){
    if(visit_count == (N+1)){
        printf("{");
        for(int i=N; i>=1; i--){
            printf("%c", array[visit[i]]);
        }
        printf("}\n");
        return;
    }
    for(int j=0; j<N; j++){
        int result = chk_visit(visit, j);
        if(result == 0) continue;
        visit[visit_count++] = j;
        permutation_v2(visit,visit_count);
        visit_count--;
    }
}

void permutation_v3(){
    
}

int main()
{
    permutation_v1();
    
    /*visit_count = 1;
    for(int i=0; i<N; i++){
        visit[visit_count] = i;
        visit_count++;
        permutation_v2(visit, visit_count);
        visit_count--;
    }*/

    permutation_v3();
    return 0;
}

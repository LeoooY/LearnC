#include <stdio.h>

void Print_Factorial ( const int N );

int main()
{
    int N;
	
    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

/* 你的代码将被嵌在这里 */
void Print_Factorial ( const int N ){
    long rs=1;
    int n=N;
    if(N<0){
        printf("Invalid input");
        return ;
    }
    while(n>0){
        rs*=n--;
    }
    printf("%ld\n",rs);
}
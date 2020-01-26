#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;
	
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

/* 你的代码将被嵌在这里 */
int Count_Digit ( const int N, const int D ){
    int n=N;
    if(n<0){
        n=-N;
    }
    if(n==0 && D==0){
        return 1;
    }

    int cnt=0;
    while(n>0){
        n%10==D && cnt++;
        n=n/10;
    }
    return cnt;
}
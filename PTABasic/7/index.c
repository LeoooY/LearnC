#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;
	
    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

/* 你的代码将被嵌在这里 */
int IsTheNumber ( const int N ){
    int sqNumber=isSqureNumber(N);
    if(sqNumber<1){
        return 0;
    }            

    return hasTowSameNum(N);
};

int isSqureNumber(int N){
    double s=sqrt(N);
    int n=s;
    return n==s?1:0;
}

int hasTowSameNum(int N){
    int numArr[10];
    int len=getNumList(numArr,N);
    int cnt=0;
    for(int x=0;x<len;x++){        
        for(int y=x+1;y<len;y++){
            if(numArr[x]==numArr[y]){cnt++;}
        }
    }
    return cnt>=1?1:0;
}

int getNumList(int *arr,int N){
    int i=0;
    while(N>0){
        arr[i++]=N%10;
        N=N/10;        
    }            
    return i;
}
#include <stdio.h>
#include <math.h>

int prime( int p );
int PrimeSum( int m, int n );

int main()
{
    int m, n, p;

    scanf("%d %d", &m, &n);
    printf("Sum of ( ");
    for( p=m; p<=n; p++ ) {
        if( prime(p) != 0 )
            printf("%d ", p);
    }
    printf(") = %d\n", PrimeSum(m, n));

    return 0;
}

/* 你的代码将被嵌在这里 */

int prime( int p ){
    int isPrime=1;
    if(p<=1){
        return 0;
    }
    
    for(float i=2.0;i<p;i++){

        float tmp=p / i;
        // printf("tmp: %f, int tmp: %d",tmp, (int) tmp );
        if(tmp == (int) tmp){
            isPrime=0;
            break;
        }
    }
    return isPrime;
}

int PrimeSum( int m, int n ){
    int rs=0;
    for(int i=m;i<=n;i++){
        if(prime(i)){
            rs+=i;
        }        
    }
    return rs;
}
#include <stdio.h>
#include <math.h>

int prime( int p );
void Goldbach( int n );

int main()
{
    int m, n, i, cnt;

    scanf("%d %d", &m, &n);
    if ( prime(m) != 0 ) printf("%d is a prime number\n", m);
    if ( m < 6 ) m = 6;
    if ( m%2 ) m++;
    cnt = 0;
    for( i=m; i<=n; i+=2 ) {
        Goldbach(i);
        cnt++;
        if ( cnt%5 ) printf(", ");
        else printf("\n");
    }

    return 0;
}

/* 你的代码将被嵌在这里 */
int prime( int p ){
    if(p<=1){
        return 0;
    }    
    
    int isPrime=1;

    for(float i=2.0; i<p ; i++ ){
        float tmp= p / i;        
        if(tmp == (int) tmp){
            isPrime=0;
            break;
        }
    }
    
    return isPrime;    
}

void Goldbach( int n ){

}
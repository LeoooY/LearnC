#include <stdio.h>

#define MAXN 10

double f( int n, double a[], double x );

int main()
{
    int n=2, i;
    double a[MAXN], x=1.1;
	
    a[0]=1;
    a[1]=2.5;
    a[2]=-38.7;

    // scanf("%d %lf", &n, &x);
    // for ( i=0; i<=n; i++ ){
    //     scanf("%lf" , &a[i]);
    // }        
    printf("%.1f\n", f(n, a, x));
    return 0;
}

/* 你的代码将被嵌在这里 */

#include<math.h>

double f( int n, double a[], double x ){
    double rs=0.0;

    for(int i=0;i<=n;i++){
        rs+=(double) (a[i]*pow(x, (double) i));
                
    }

    return rs;
}
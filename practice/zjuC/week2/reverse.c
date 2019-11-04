#include <stdio.h>

int main(){
    int input;
    scanf("%d",&input);
    
    int _0=input%10;
    int _1=input/10%10;
    int _2=input/100%10;

    printf("input:%d,%d,%d,%d\n",input,_0,_1,_2);
    int rs=_0*100+_1*10+_2;

    printf("%d",rs);

    return 0;
}
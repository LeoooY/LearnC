#include <math.h>
#include <stdio.h>

int IsTheNumber(const int N);

int main() {
    int n1, n2, i, cnt;

    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for (i = n1; i <= n2; i++) {
        if (IsTheNumber(i)) cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

int isTheSame(int N) {
    int len=0,tmpN=N;

    while(tmpN>0){
        len++;
        tmpN/=10;
    }
    printf("\n\nnum length,%d \n",len);

    int arr[len];
    int i = 0;
    while (N / (int)(pow(10, i)) > 0) {
        int tmp=N / (int)(pow(10, i)) % 10;
        arr[i] =tmp;
        i++;
    }

    int size=sizeof(arr)/sizeof(arr[0]);
    printf("num size: %d\n",size);

    // 先排序 再计数
    for(int j=0;j<size;j++){
        printf("num[%d]: %d ",j,arr[j]);
    }


}

int IsTheNumber(const int N) {
    isTheSame(N);    
    return 0;
}
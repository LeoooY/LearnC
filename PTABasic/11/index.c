#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median(ElementType A[], int N);

int main() {
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}

void printArr(ElementType *a, int len) {
    printf("arr: ");
    for (int i = 0; i < len; i++) {
        printf(" %f ", a[i]);
    }
    printf("\n");
}

/* 你的代码将被嵌在这里 */
ElementType Median(ElementType A[], int N) {
    quickSort(&A[0],0,N);
    int idx=N/2;
    printf("idx: %d\n",idx);
    return A[idx];
}

void quickSort(ElementType *arr, int left, int right) {
    if (left >= right) {
        return;
    }
    
    int pivot = (left + right) / 2;
    swap(arr,left,pivot);
    int sorted=left;
    for(int i=left+1;i<=right;i++){
        if(arr[i]<arr[left]){
            swap(arr,++sorted,i);
        }
    }

    swap(arr,sorted,left);
    quickSort(arr,left,sorted-1);
    quickSort(arr,sorted+1,right);
}

void swap(ElementType *arr, int i, int j) {
    ElementType tmp;
    tmp=arr[i];    
    arr[i]=arr[j];
    arr[j]=tmp;
}
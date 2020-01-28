#include <stdio.h>
#define GETLEN(x) (sizeof(x) / sizeof((x)[0]))

int main() {
    printf("start: \n");
    int a[] = {7, 3, 2, 4, 9, 10, 6};
    int len = GETLEN(a);
    printf("len: %d\n\n", len);
    printf("origin arr\n");
    printArr(a, len);
    quickSort(a, 0, len);
    printf("\nsorted arr\n");
    printArr(a, len);
}

void printArr(int *a, int len) {
    printf("arr: ");
    for (int i = 0; i < len; i++) {
        printf(" %d ", a[i]);
    }
    printf("\n");
}

void quickSort(int *a, int left, int right) {

    int last;
    int pivot = (left + right) / 2;

    /* 只有一个元素，不排序 */
    if (left >= right) {
        return;
    }

    /* 将pivot放到（当前小段）数组left,然后所有元素和left比较 */
    /* left初始值为0，数组的首位 */
    swap(a, left, pivot);
    last = left;
    for (int i = left + 1; i <= right; i++) {
        if (a[i] < a[left]) {
            /* 等价于 ++last 再 swap */
            /* 第一次(若需要交换)相当于从a[1]开始swap */
            swap(a, ++last, i);
        }
    }

    /* 交换完成后，将last和left交换（因为last<left） */
    swap(a, last, left);

    /* 以last为分隔，左右递归进行 */
    quickSort(a, left, last - 1);
    quickSort(a, last + 1, right);
}

/* swap a[i] a[j] */
void swap(int *a, int i, int j) {
    int tmp;
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

#include <stdio.h>
// 题目：输入三个整数x,y,z，请把这三个数由小到大输出。

/* 智障版本 */
/* 用一个中间数tmp,将变量进行交换 */
// int main(){
//     int x,y,z,tmp;
//     printf("Input three numbers, like: 1,2,3\n");
//     scanf("%d,%d,%d",&x,&y,&z);
//     if(x>y){
//         tmp=x;x=y;y=tmp;
//     }
//     if(x>z){
//         tmp=x;x=z;z=tmp;
//     }
//     if(y>z){
//         tmp=y;y=z;z=tmp;
//     }
//     printf("\nmin to max: %d, %d, %d",x,y,z);
// }



/*  插入时候使用冒泡排序 */
/*
    每个数字的输入是O(n)的时间复杂度，在每次输入时候进行冒泡排序也是o(n)的时间复杂度
    总体复杂度O(n^2)
*/


// int main() {
//     int arr[5];
//     int input;
//     int swap;
//     printf("Input three numbers, like: 1,2,3\n");

//     for (int i = 0; i < 5; i++) {
//         printf("Input %dth number:\n ", i + 1);
//         scanf("%d", &input);
//         arr[i] = input;

//         swap = i;
//         while (swap > 0 && arr[swap] < arr[swap - 1]) {
//             int tmp = arr[swap];
//             arr[swap] = arr[swap - 1];
//             arr[swap - 1] = tmp;
//             swap--;
//         }
//     }

//     for (int i; i < 5; i++) {
//         printf("%d,", arr[i]);
//     }
// }

/*
    优化： 快排版本
    先输入再使用快排的话，复杂度为n+nlog(n)
*/

int quickSort(int *arr){
    printf("print arr %d",*arr);
    return *arr;
}

int main() {
    int arr[5];
    int input;
    
    printf("Input three numbers, like: 1,2,3\n");

    for (int i = 0; i < 5; i++) {
        printf("Input %dth number:\n ", i + 1);
        scanf("%d", &input);
        arr[i] = input;       
    }

    int *arrp=&arr[0];
    quickSort(arrp);

    for (int i; i < 5; i++) {
        printf("%d,", arr[i]);
    }
}

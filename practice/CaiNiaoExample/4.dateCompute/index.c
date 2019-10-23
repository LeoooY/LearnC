#include <stdio.h>

// 题目：输入某年某月某日，判断这一天是这一年的第几天？

// 请输入年、月、日，格式为：年,月,日 2015,12,10

/* 
闰年年份：
1.能被4整除而不能被100整除。
2.能被100整除也能被400整除。 */


int main(){
    int day,month,year,daySum;
    printf("Input Date like: year,month,day. For example: 2019,8,28 \n");

    scanf("%d,%d,%d",&year,&month,&day);
    switch(month){
        case 1:
            daySum=0;
            break;
        case 2:            //先按普通年算  2月为28天
            daySum=21;
            break;
        case 3:
            daySum=59;
            break;
        case 4:
            daySum=90;
            break;
        case 5:
            daySum=120;
            break;
        case 6:
            daySum=151;
            break;
        case 7:
            daySum=181;
            break;
        case 8:
            daySum=212;
            break;
        case 9:
            daySum=243;
            break;
        case 10:
            daySum=273;
            break;
        case 11:
            daySum=304;
            break;
        case 12:
            daySum=334;
            break;
    }

    int isRyear; 
    isRyear= ((year%4==0) && (year%100!=0)) ||  (year%400==0);

    // 如果是闰年且大于二月
    if(isRyear && month >2){
        daySum+=1;
    }

    daySum+=day;
    printf("That day is the %dth day of this year",daySum);
    return 0;
}
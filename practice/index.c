#include <stdio.h>
#include <string.h>
#define typename(x) _Generic((x),                                                 \
        _Bool: "_Bool",                  unsigned char: "unsigned char",          \
         char: "char",                     signed char: "signed char",            \
    short int: "short int",         unsigned short int: "unsigned short int",     \
          int: "int",                     unsigned int: "unsigned int",           \
     long int: "long int",           unsigned long int: "unsigned long int",      \
long long int: "long long int", unsigned long long int: "unsigned long long int", \
        float: "float",                         double: "double",                 \
  long double: "long double",                   char *: "pointer to char",        \
       void *: "pointer to void",                int *: "pointer to int",         \
      default: "other")
      
int main() {
    // printf("Hello");
    // int a = 2;
    // int *p = &a;
    // typedef struct {
    //     int age;
    //     char * name;
    // } person;
    
    // person leo;
    // leo.name="leo";
    // leo.age=23;

    // person *ps=&leo;

    // printf("value fo a, a: %d\n",a);
    // printf("value of p, *p: %d\n",*p);
    // printf("address of p, p: %p\n",p);
    // printf("address of a, &a: %p\n",&a);
    // printf("address of &p, &p: %p\n",&p);
    // ps->age=24;
    // ps->name="leoy";
    // printf("leo.age: %d\n", ps->age);
    // printf("leo.age: %s\n", ps->name);
    // char *str="hello str pointer";
    // str="hello";
    // printf("str: %s\n", str);
    // *str="hello";
    // printf("str: %s\n", *str);

    char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    printf("type: %s\n",typename(vowels));
    char *pvowels = vowels;
    int i;
    for (i = 0; i < 5; i++) {
        printf("vowels[%d]: %c, *(pvowels + %d): %c, *(vowels + %d): %c\n", i, vowels[i], i, *(pvowels + i), i, *(vowels + i));
    }    
    return 0;
}

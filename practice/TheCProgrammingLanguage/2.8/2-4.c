#include <stdio.h>

void squeeze(char *s1, char *s2) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (s1[i]) {
        while (s2[j]) {
            if (s1[i] == s2[j]) {
                break;                
            }
            j++;
        }
        if(!s2[j]){
            s1[k++] = s1[i];
        }        
        i++;
        j=0;
    }

    s1[k]='\0';
}

int main() {
    char s1[] = "helloworld";
    char s2[] = "wh";
    squeeze(s1, s2);
    printf("s1: %s,s2: %s \n", s1, s2);
    return 0;
}

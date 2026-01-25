#include <stdio.h>
void move(int n,char a,char b);
int main() {
    int n;
    scanf("%d", &n);
    move(n,'A','C');
    return 0;
}
void move(int n,char a,char b) {
    if(n==1)printf("%c -> %c\n",a,b);
    else {
        move(n-1,a,'A'+'B'+'C'-a-b);
        printf("%c -> %c\n",a,b);
        move(n-1,'A'+'B'+'C'-a-b,b);
    }
}
#include <stdio.h>
int fab(int n,int a,int b);
int main()
{
    int n,a=0,b=1;
    printf("请输入一个正整数：");
    scanf("%d",&n);
    printf("%d",fab(n,a,b));
}
int fab(int n,int a,int b){
    if(n==0) return a;
    return n==1?a:fab(n-1,b,a+b);
}
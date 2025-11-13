#include <stdio.h>
int isUgly(int num);
int main(void){
    int ugly[1000]={1};
    int count=1;
    for(int i=2;i<2000;i++){
    if(i%2==0||i%3==0||i%5==0)
        if(isUgly(i)){
            ugly[count++]=i;
        }
    }
    printf("%d",ugly[100-1]);
}
int isUgly(int num){
    while(num%2==0)num/=2;
    while(num%3==0)num/=3;
    while(num%5==0)num/=5;
    return num==1;
}
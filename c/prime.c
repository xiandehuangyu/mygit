#include<stdio.h>
#include<math.h>
int CanBeDivided(int dividend, int divisor);
int IsPrime(int a);
int main(void){
    int n;
    scanf("%d",&n);
    printf("%d",IsPrime(n));
    return 0;
}
int CanBeDivided(int dividend, int divisor){
    if(dividend%divisor==0){
        return 1;
    }
    else{
        return 0;
    }
}
int IsPrime(int a){
    int i;
    if(a<2){
        return 0;
    }
    for(i=2;i<=sqrt(a);i++){
        if(CanBeDivided(a,i)){
            return 0;
        }
    }
    return 1;
}
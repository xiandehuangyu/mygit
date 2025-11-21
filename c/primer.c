#include <stdio.h>
#include <math.h>
int IsPrime(int n);
int canbedivided(int a,int b);
int main(){
    int n;
    scanf("%d",&n);
    int b=(int)sqrt(n);
    int answer=canbedivided(n,b);
    printf("%d",answer);
    return 0;
}
int canbedivided(int a,int b){
    if(b==1)return 1;
    if(a%b==0)return 0;
    else return canbedivided(a,b-1);
}
int IsPrime(int n){
        if(canbedivided(n,(int)sqrt(n))==0){
            return 0;
        }
    return 1;
}
#include <stdio.h>
int prime(int n){
    if(n<2)return 0;
    if(n==2)return 1;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return 0;
    }
    return 1;
}
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main(void){
    int k[10]={0};
    for(int i=0;i<10;i++){
        scanf("%d",&k[i]);
    }
    int shusu[10]={0};
    for(int i=0;i<10;i++){
        if(prime(k[i])){
            shusu[i]=1;
        }
    }
    for(int i=0,j=9;i<j;){
        if(shusu[i]==0){
            i++;
            continue;
        }
        if(shusu[j]==0){
            j--;
            continue;
        }
        if(shusu[i]==1&&shusu[j]==1){
                swap(&k[i],&k[j]);
                i++;
                j--;
            }
    }
    for(int i=0;i<10;i++){
            printf("%d ",k[i]);
    }
}
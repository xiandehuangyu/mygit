#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int sum=1;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){sum+=n/i;
        sum+=i;
        if(i*i==n)sum-=i;}
    }
    printf("%d", sum);
    return 0;
}
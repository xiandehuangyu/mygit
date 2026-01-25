#include <stdio.h>

int main() {
    int a[5][5];
    int k[1000]= {0};
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            scanf("%d", &a[i][j]);
            k[a[i][j]]++;
        }
    }
    for(int i=0;i<1000;i++){
        if(k[i]==5){
            printf("%d ",i);
        }
    }
return 0;
}
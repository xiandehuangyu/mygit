#include <stdio.h>
int main(){
    int a[5][5];
    for(int i=0;i<5;i++){
        scanf("%d %d %d %d %d", &a[i][0],&a[i][1],&a[i][2],&a[i][3],&a[i][4]);
    }
    int rowsum[5]={0};
    for(int i=0;i<5;i++){
        int sum=0;
        for(int j=0;j<5;j++){
            sum=sum+a[i][j];
        }
        rowsum[i]=sum;
        a[i][4-i]=sum;
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(j!=4-i){
                a[i][j]=0;
            }
        }
    }
    int b[5];
    for(int i=0;i<5;i++){
        b[i]=a[i][4-i];
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(b[j]>b[j+1]){
                int temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
    }
    for(int i=0;i<5;i++){
        a[i][4-i]=b[i];
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
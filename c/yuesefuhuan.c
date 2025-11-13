#include <stdio.h>
int main() {
    int m,n,k=0,j=1,i1=0;
    scanf("%d%d",&m,&n);
    int s[m];
    for(int i=0;i<m;i++){s[m]=1;}
    int anwser[m];
    while(k<m){
        i1++;
        i1%=m;
        while(s[i1]==0){i1++;i1%=m;}
        j++;
        if(j==n){
            s[i1]=0;
            anwser[k]=i1;
            k++;
            j=0;
        }
    }
    for(int i=0;i<m;i++){printf("%d ",anwser[i]);}
    return 0;
}
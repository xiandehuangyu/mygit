#include <stdio.h>
#include <string.h>
void fun(char xx[]);
int main(){
    char w[100]={0};
    char c;
    int m=0;
    while((c=getchar())!='\n'){  
                w[m]= c;
                m++;
    }
    w[m]='\0';
    fun(w);
    printf("%s\n",w);
    return 0;
}
void fun(char xx[]){
    int len=strlen(xx);
    for(int i=0; i<len; i++){
        if(xx[i]>='0'&&xx[i]<='9'){
            for(int j=len;j>i; j--){
                xx[j]=xx[j-1];
            }
            len++;
            xx[i]='$';
            i++;
        }
    }
}
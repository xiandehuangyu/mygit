#include <stdio.h>
#include <string.h>
#include <ctype.h>
int FindNoVowel(char *str[],int num,char res[][20]){
    int count=0;
    for(int i=0;i<num;i++){
        int k=0;
        for(int j=0;j<strlen(str[i]);j++){
            char ch=tolower(str[i][j]);
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                k=1;
                break;
            }
        }
        if(!k){
            printf("%s ",str[i]);
            count++;
        }
    }
    return count;
}
void sortWords(char words[][20], int num) {
    char temp[20];
    for(int i=0; i<num-1; i++){
        for(int j=0; j<num-1-i; j++){
            char str1[20], str2[20];
            strcpy(str1, words[j]);
            strcpy(str2, words[j+1]);
            for(int k=0; k<strlen(str1); k++) str1[k] = tolower(str1[k]);
            for(int k=0; k<strlen(str2); k++) str2[k] = tolower(str2[k]);
            if(strcmp(str1, str2) > 0){
                strcpy(temp, words[j]);
                strcpy(words[j], words[j+1]);
                strcpy(words[j+1], temp);
            }
        }
    }
}
int main() {
    char w[10][20] = {0};
    char *str[]={w[0],w[1],w[2],w[3],w[4],w[5],w[6],w[7],w[8],w[9]};
    int q=0;
    int l=0, m=0;
    char c;
    while((c=getchar())!='\n') {    
        if (isalpha(c)||isdigit(c)) {
            w[m][l]=c;
            l++;
            q=1;
        } else {if(q){
                w[m][l]='\0';
                m++;
                l=0;
                q=0;
                }
            }
        }
    if(q){
        w[m][l]='\0';
        m++;
    }
    sortWords(w, m);
    int b=FindNoVowel(str,m,w);
    return 0;
}
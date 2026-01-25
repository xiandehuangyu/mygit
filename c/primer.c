#include <stdio.h>
#include <string.h>
#include <ctype.h>

int FindNoVowel(char *str[],int num,char res[][20]){
    int count=0;
    // 限制i不超过str数组长度（10），避免指针越界//
    int max_i = (num > 10) ? 10 : num;
    for(int i=0;i<max_i;i++){
        // 强制检查字符串终止符，避免strlen访问非法内存//
        if(str[i] == NULL || strlen(str[i]) == 0) continue;
        int k=0;
        for(int j=0;j<strlen(str[i]);j++){
            char ch=tolower(str[i][j]);
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                k=1;
                break;
            }
        }
        if(!k){
            // 安全拷贝，强制终止字符串//
            strncpy(res[count], str[i], 19);
            res[count][19] = '\0';
            count++;
            // 限制结果不超过res数组容量//
            if(count >= 10) break;
        }
    }
    return count;
}

int main() {
    char w[10][20] = {0}; // 全0初始化，确保默认有\0//
    char *str[]={w[0],w[1],w[2],w[3],w[4],w[5],w[6],w[7],w[8],w[9]};
    int q=0;
    int l=0, m=0;
    char c;

    while((c=getchar())!='\n') {    
        if (isalpha(c)||isdigit(c)) {
            // 严格限制单词长度，避免越界//
            if(l < 19 && m < 10){
                w[m][l] = c;
                l++;
            }
            q=1;
        } else {
            if(q && m < 10){ // 限制m不超过9（str数组最大索引）//
                w[m][l] = '\0'; // 强制加终止符//
                m++;
                l=0;
                q=0;
            }
        }
    }
    // 处理最后一个单词，且限制m不越界//
    if(q && m < 10){
        w[m][l] = '\0';
        m++;
    }

    int b=FindNoVowel(str, m, w);
    for(int i=0;i<b;i++){
        printf("%s ",w[i]);
    }
    printf("\n"); // 补充换行，优化输出//
    return 0;
}
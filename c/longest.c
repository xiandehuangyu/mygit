#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char w[100][10] = {0};
    int l=0, m=0,max=0,maxi=0;
    char c;
    while((c=getchar())!='\n') {  
        if (isalpha(c)) {
                w[m][l] = c;
                l++;
        } else {
                w[m][l] = '\0';
                m++;
                l = 0;
                if (m >= 99) break;
        }
    }
    for(int i=0; i<m; i++){
        int len = strlen(w[i]);
        if (len > max) {
            max = len;
            maxi = i;
        }
    }
    printf("%s\n",w[maxi]);
    return 0;
}
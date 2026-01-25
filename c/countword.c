#include <stdio.h>
#include <string.h>
#include <ctype.h>
void count(char a[], char w[][10], int n, int b[]);
int splitWords(char a[], char words_all[][10], int max_words) {
    int word_idx = 0;
    int char_idx = 0;
    int in_word = 0; 
    for (int i = 0; a[i] != '\0'; i++) {
        if (isalpha(a[i])) {
            words_all[word_idx][char_idx++] = a[i];
            in_word = 1;
            if (char_idx >= 9) char_idx = 9;
        } else {
            if (in_word) {
                words_all[word_idx][char_idx] = '\0';
                word_idx++;
                char_idx = 0;
                in_word = 0;
                if (word_idx >= max_words) break;
            }
        }
    }
    if (in_word && word_idx < max_words) {
        words_all[word_idx][char_idx] = '\0';
        word_idx++;
    }
    return word_idx;
}
void count(char a[], char w[][10], int n, int b[]) {
    for (int i = 0; i < n; i++) {
        b[i] = 0;
    }
    char all_words[100][10];
    int total_words = splitWords(a, all_words, 100);
    for (int i = 0; i < n; i++) {
        if (w[i][0] == '\0') continue;
        for (int j = 0; j < total_words; j++) {
            if (strcmp(w[i], all_words[j]) == 0) {
                b[i]++;
            }
        }
    }
}
int main() {
    char a[1000], w[100][10] = {0};
    int b[100] = {0};
    int l=0, m=0, k=0;
    char c;
    int in_word = 0;
    while((c=getchar())!='\n' && k < 999) {
        a[k] = c;
        k++;     
        if (isalpha(c)) {
            if (l < 9) {
                w[m][l] = c;
                l++;
            }
            in_word = 1;
        } else {
            if (in_word) {
                w[m][l] = '\0';
                m++;
                l = 0;
                in_word = 0;
                if (m >= 99) break;
            }
        }
    }
    a[k] = '\0';
    if (in_word && m < 99) {
        w[m][l] = '\0';
        m++;
    }
    count(a, w, m, b);
    if (m >= 1) {
        printf("%s:%d", w[0], b[0]);
        if (m >= 2) {
            printf(" %s:%d", w[1], b[1]);
        }
    }
    printf("\n");
    return 0;
}
#include <stdio.h>
int isPalindrome(long n);
long reverseNumber(long n);
int fun(long n, long *hw);
int main(void) {
    long a, b;
    int c;      
    scanf("%ld", &a);
    c = fun(a, &b);
    if (c == -1) {
        printf("error\n");
    } else if (c == 0) {
        printf("%ld,0\n",b);
    } else {
        printf("%ld,%d\n",b,c);
    }
    return 0;
}
int isPalindrome(long n) {
    return n == reverseNumber(n);
}
long reverseNumber(long n) {
    long reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}
int fun(long n, long *hw) {
    int count = 0;  
    long current = n;
    if (isPalindrome(current)) {
        *hw = current;
        return 0;
    }
    while (count < 10000) {
        long reversed = reverseNumber(current); 
        current += reversed;                    
        count++;                                
        if (isPalindrome(current)) {
            *hw = current;  
            return count;   
        }
    }
    return -1;
}
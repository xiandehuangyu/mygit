#include "booksystem.h"

void clearScreen() {
    system("clear");
}

int isBookExist(const char *bookId) {
    FILE *fp = fopen(BOOK_FILE, "r");
    if (fp == NULL) return 0;
    Book temp;
    while (fscanf(fp, "%s %s %s %f %d", temp.id, temp.name, temp.author, &temp.price, &temp.stock) != EOF)
    {
        if(strcmp(temp.id, bookId) == 0) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
    
void pauseprogram(){
    printf("按回车键继续...");
    while(getchar() != '\n');
    getchar();
}
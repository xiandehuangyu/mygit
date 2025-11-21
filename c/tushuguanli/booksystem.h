#ifndef BOOK_SYSTEM_H  
#define BOOK_SYSTEM_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BOOK_FILE "books.txt"
typedef struct Book {
    char id[20];       
    char name[50];     
    char author[30];   
    float price;       
    int stock;         
} Book;
void clearScreen(); 
int isBookExist(const char *bookId); 
void addBook();                    
void showAllBooks();                
void queryBookById();               
void modifyBookById();              
void deleteBookById();              
void pauseprogram();

#endif 
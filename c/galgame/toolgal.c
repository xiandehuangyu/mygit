#include "galsystem.h"
void clearScreen() {
    system("clear");
}
    
void pauseprogram(){
    printf("按回车键继续...");
    while(getchar() != '\n');
    getchar();
}
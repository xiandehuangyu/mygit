#include "booksystem.h"

int main() {
    int choice;
    while(1){
        clearScreen();
        printf("===== 图书管理系统 =====\n");
        printf("1. 添加图书\n");
        printf("2. 显示所有图书\n");
        printf("3. 查询图书信息\n");
        printf("4. 修改图书信息\n");
        printf("5. 删除图书信息\n");
        printf("0. 退出系统\n");
        printf("========================\n");
        printf("请选择操作(0-5): ");
        scanf("%d", &choice);
        switch(choice){
            case 1:addBook();break;
            case 2:showAllBooks();break;
            case 3:queryBookById();break;
            case 4:modifyBookById();break;
            case 5:deleteBookById();break;
            case 0:printf("感谢使用图书管理系统！再见！\n");return 0;
            default:printf("无效的选择，请重新输入！\n");system("pause");
        }
    }
}
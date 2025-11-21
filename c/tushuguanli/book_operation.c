#include "booksystem.h"

void addBook(){
    clearScreen();
    Book newBook;
    FILE *fp = fopen(BOOK_FILE, "a+");
    if(fp == NULL){
        printf("文件打开失败！\n");
        return;
    }
    printf("=== 添加新图书 ===\n");
    printf("请输入图书ID: ");
    scanf("%s", newBook.id);
    getchar();
    if(isBookExist(newBook.id)){
        printf("图书ID已存在!\n");
        fclose(fp);
        pauseprogram();
        return;
    }
    printf("请输入图书名称: ");
    fgets(newBook.name, sizeof(newBook.name), stdin);
    newBook.name[strcspn(newBook.name, "\n")] = '\0';
    printf("请输入图书作者: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';
    printf("请输入图书价格: ");
    scanf("%f", &newBook.price);
    printf("请输入图书库存: ");
    scanf("%d", &newBook.stock);
    fprintf(fp, "%s %s %s %f %d\n", newBook.id, newBook.name, newBook.author, newBook.price, newBook.stock);
    printf("图书添加成功！\n");
    fclose(fp);
    pauseprogram();
}

void showAllBooks(){
    clearScreen();
    Book temp;
    FILE *fp = fopen(BOOK_FILE, "r");
    if(fp == NULL){
        printf("暂无图书数据!\n");
        pauseprogram();
        return;
    }
    printf("=== 所有图书信息===\n");
    printf("%-10s %-20s %-15s %-8s %-5s\n", "编号", "名称", "作者", "价格", "库存");  
    printf("--------------------------------------------------------\n");
    int count = 0;
    while(fscanf(fp, "%s %s %s %f %d", temp.id, temp.name, temp.author, &temp.price, &temp.stock) != EOF){
        printf("%-10s %-20s %-15s %-8.2f %-5d\n", temp.id, temp.name, temp.author, temp.price, temp.stock);
        count++;
    }

    if(count == 0){
        printf("暂无图书数据!\n");
    }else{
        printf("--------------------------------------------------------\n");
        printf("共查询到%d本图书\n", count);
    }
    fclose(fp);
    pauseprogram();
}

void queryBookById(){
    clearScreen();
    char targetId[20];
    Book temp;
    FILE *fp = fopen(BOOK_FILE, "r");
    if(fp == NULL){
        printf("暂无图书数据!\n");
        pauseprogram();
        return;
    }
    printf("=== 查询图书信息 ===\n");
    printf("请输入要查询的图书ID: ");
    scanf("%s", targetId);
    int found = 0;
    while(fscanf(fp, "%s %s %s %f %d", temp.id, temp.name, temp.author, &temp.price, &temp.stock) != EOF){
        if(strcmp(temp.id, targetId) == 0){
            printf("\n图书信息如下:\n");
            printf("编号: %s\n", temp.id);
            printf("名称: %s\n", temp.name);
            printf("作者: %s\n", temp.author);
            printf("价格: %.2f\n", temp.price);
            printf("库存: %d\n", temp.stock);
            found = 1;
        }
    }

    if(!found){
        printf("未找到编号为%s的图书!\n", targetId);
    }
    fclose(fp);
    pauseprogram();
}

void modifyBookById(){
    clearScreen();
    char targetId[20];
    Book temp;
    FILE *fp = fopen(BOOK_FILE, "r");
    FILE *tempFp = fopen("temp.txt", "w");
    if(fp == NULL || tempFp == NULL){
        printf("文件打开失败！\n");
        fclose(fp);
        fclose(tempFp);
        pauseprogram();
        return;
    }
    printf("=== 修改图书信息 ===\n");
    printf("请输入要修改的图书ID: ");
    scanf("%s", targetId);
    getchar();
    if(!isBookExist(targetId)){
        printf("未找到编号为%s的图书!\n", targetId);
        fclose(fp);
        fclose(tempFp);
        remove("temp.txt");
        pauseprogram();
        return;
    }
    while(fscanf(fp, "%s %s %s %f %d", temp.id, temp.name, temp.author, &temp.price, &temp.stock) != EOF){
        if(strcmp(temp.id, targetId) == 0){
            printf("请输入新的图书名称: ");
            fgets(temp.name, sizeof(temp.name), stdin);
            temp.name[strcspn(temp.name, "\n")] = '\0';
            printf("请输入新的图书作者: ");
            fgets(temp.author, sizeof(temp.author), stdin);
            temp.author[strcspn(temp.author, "\n")] = '\0';
            printf("请输入新的图书价格: ");
            scanf("%f", &temp.price);
            printf("请输入新的图书库存: ");
            scanf("%d", &temp.stock);
        }
        fprintf(tempFp, "%s %s %s %f %d\n", temp.id, temp.name, temp.author, temp.price, temp.stock);
    }
    fclose(fp);
    fclose(tempFp);
    remove(BOOK_FILE);
    rename("temp.txt", BOOK_FILE);
    printf("图书信息修改成功！\n");
    pauseprogram();
}

void deleteBookById(){
    clearScreen();
    char targetId[20];
    Book temp;
    FILE *fp = fopen(BOOK_FILE, "r");
    FILE *tempFp = fopen("temp.txt", "w");
    if(fp == NULL || tempFp == NULL){
        printf("文件打开失败！\n");
        fclose(fp);
        fclose(tempFp);
        pauseprogram();
        return;
    }
    printf("=== 删除图书信息 ===\n");
    printf("请输入要删除的图书ID: ");
    scanf("%s", targetId);
    getchar();
    if(!isBookExist(targetId)){
        printf("未找到编号为%s的图书!\n", targetId);
        fclose(fp);
        fclose(tempFp);
        remove("temp.txt");
        pauseprogram();
        return;
    }
    while(fscanf(fp, "%s %s %s %f %d", temp.id, temp.name, temp.author, &temp.price, &temp.stock) != EOF){
        if(strcmp(temp.id, targetId) != 0){
            fprintf(tempFp, "%s %s %s %f %d\n", temp.id, temp.name, temp.author, temp.price, temp.stock);
        }
    }
    fclose(fp);
    fclose(tempFp);
    remove(BOOK_FILE);
    rename("temp.txt", BOOK_FILE);
    printf("图书信息删除成功！\n");
    pauseprogram();
}
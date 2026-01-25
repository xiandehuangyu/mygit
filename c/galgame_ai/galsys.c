/* galsys.c - 主程序 */
#include "galsys.h"

// 全局变量定义
StoryNode* headNode = NULL;
Character* headChar = NULL;

// --- 子菜单 ---

void handleCharMenu() {
    int choice;
    while(1) { // 无限循环，直到用户选择返回
        system(CLEAR_SCREEN); // 清屏
        printf("\n=== 人物操作菜单 ===\n");
        printf("1. 添加人物\n");
        printf("2. 删除人物\n");
        printf("3. 修改人物\n");
        printf("4. 显示所有人物\n");
        printf("0. 返回上级\n");
        printf("请选择: ");
        
        if (scanf("%d", &choice) != 1) {
            clearBuffer(); continue; // 清除缓冲区
        }

        switch(choice) { // 字面意思
            case 1: addCharacter(); pauseWait(); break;
            case 2: deleteCharacter(); pauseWait(); break;
            case 3: modifyCharacter(); pauseWait(); break;
            case 4: printAllCharsDetailed(); pauseWait(); break;
            case 0: return;
            default: printf("无效输入\n"); pauseWait();
        }
    }
}

void handleStoryMenu() { //字面意思
    int choice;
    while(1) {
        system(CLEAR_SCREEN);
        printf("\n=== 剧情操作菜单 ===\n");
        printf("1. 添加剧情节点\n");
        printf("2. 修改节点\n");
        printf("3. 修改节点跳转 (ID连接)\n");
        printf("4. 删除节点\n");
        printf("5. 显示所有剧情\n");
        printf("0. 返回上级\n");
        printf("请选择: ");

        if (scanf("%d", &choice) != 1) {
            clearBuffer(); continue;
        }

        switch(choice) {
            case 1: createNode(); break;
            case 2: modifyNode(); pauseWait(); break;
            case 3: modifyNodeNextId(); pauseWait(); break;
            case 4: deleteNode(); pauseWait(); break;
            case 5: printAllNodes(); pauseWait(); break;
            case 0: return;
            default: printf("无效输入\n"); pauseWait();
        }
    }
}

// --- 主函数 ---

int main() {
    // 启动时自动加载
    loadStory("story.txt");
    loadChars("char.txt");

    int choice;
    while (1) {
        system(CLEAR_SCREEN);
        printf("\n================================\n");
        printf("   Galgame 编辑器 & 模拟器 \n");
        printf("================================\n");
        printf("1. 人物操作 \n");
        printf("2. 剧情操作 \n");
        printf("3. 运行模拟 \n");
        printf("4. 加载文件 \n");
        printf("5. 保存文件 \n");
        printf("0. 退出程序 \n");
        printf("--------------------------------\n");
        printf("请选择: ");

        if (scanf("%d", &choice) != 1) {
            clearBuffer();
            continue;
        }

        switch (choice) {
            case 1: handleCharMenu(); break;
            case 2: handleStoryMenu(); break;
            case 3: 
                clearBuffer(); // 清除残留换行符，为游戏内的fgets做准备
                runGame(); 
                break;
            case 4: 
                loadStory("story.txt"); 
                loadChars("char.txt"); 
                pauseWait();
                break;
            case 5: 
                saveStory("story.txt"); 
                saveChars("char.txt"); 
                pauseWait();
                break;
            case 0:
                printf("正在保存并退出...\n");
                saveStory("story.txt"); 
                saveChars("char.txt");
                return 0;
            default: printf("无效输入。\n"); pauseWait();
        }
    }
    return 0;
}
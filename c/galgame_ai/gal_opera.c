/* gal_opera.c - 模拟运行 */
#include "galsys.h"

// 内部函数：应用选项效果
void applyEffect(char* targetName, int loveVal, char* newHobby) {
    if (strcmp(targetName, STR_NONE) == 0) return; 

    Character* c = findCharByName(targetName);
    if (c == NULL) return; 

    // 1. 好感度
    if (loveVal != 0) {
        c->loveLevel += loveVal;
        printf("\n>>> [%s] 好感度变化: %d (当前: %d)\n", c->name, loveVal, c->loveLevel);
    }

    // 2. 爱好
    if (strcmp(newHobby, STR_NONE) != 0) {
        if (strcmp(c->hobby, newHobby) != 0) {
            strcpy(c->hobby, newHobby);
            printf(">>> 发现了 [%s] 的新爱好: %s !\n", c->name, c->hobby);
        }
    }
}

// 内部函数：重置游戏
void resetGame() {
    printf("\n正在重置游戏数据...\n");
    // 1. 重新读取文件 (为了获取那些被保存下来的“初始值”字段)
    loadStory("story.txt");
    loadChars("char.txt");
    // 2. 关键步骤：即便读取了文件（文件中可能存的是玩了一半的进度），
    //    我们也强制把“当前值”覆盖为“初始值”。
    resetCharsToInitial(); 
    printf("重置完成！回到起点。\n");
    pauseWait();
}
void runGame() {
    if (headNode == NULL) {
        // 尝试自动加载
        loadStory("story.txt");
        loadChars("char.txt");
        if (headNode == NULL) {
            printf("无剧情数据，请先编辑。\n");
            pauseWait();
            return;
        }
    }

    int currentId = headNode->id; 
    
    while (currentId != -1) {
        StoryNode* node = findNodeById(currentId);
        if (node == NULL) {
            printf("错误：节点 %d 丢失。\n", currentId);
            break;
        }

        system(CLEAR_SCREEN); 
        
        // --- 界面显示 ---
        printf("========================================\n");
        printf("   [剧情 ID: %d]\n", node->id);
        printf("   %s\n", node->content);
        printf("========================================\n");

        // --- 普通节点 ---
        if (node->type == NODE_NORMAL) {
            printf("\n[操作]: Enter继续 | c:看人物 | r:重开 | q:退出\n");
            printf(">> ");
            
            char cmd[20];
            fgets(cmd, sizeof(cmd), stdin); // 读取整行

            if (cmd[0] == 'c' || cmd[0] == 'C') {
                printAllChars();
                pauseWait();
                continue; // 重新显示当前节点
            }
            else if (cmd[0] == 'r' || cmd[0] == 'R') {
                resetGame();
                currentId = headNode->id;
                continue;
            }
            else if (cmd[0] == 'q' || cmd[0] == 'Q') {
                break;
            }
            else {
                currentId = node->nextId;
            }
        } 
        // --- 分支节点 ---
        else if (node->type == NODE_BRANCH) {
            printf("\n请做出选择:\n");
            printf("   1. %s\n", node->opt1Text);
            printf("   2. %s\n", node->opt2Text);
            printf("\n[功能]: 9.查看人物 | 0.重开\n");
            printf("输入选项: ");
            
            int choice;
            char buf[50];
            fgets(buf, sizeof(buf), stdin);
            if (sscanf(buf, "%d", &choice) != 1) choice = -1;
            
            if (choice == 1) {
                applyEffect(node->opt1Target, node->opt1LoveVal, node->opt1NewHobby);
                currentId = node->opt1NextId;
                pauseWait(); 
            }
            else if (choice == 2) {
                applyEffect(node->opt2Target, node->opt2LoveVal, node->opt2NewHobby);
                currentId = node->opt2NextId;
                pauseWait();
            }
            else if (choice == 9) {
                printAllChars();
                pauseWait();
                continue;
            }
            else if (choice == 0) {
                resetGame();
                currentId = headNode->id;
                continue;
            }
            else {
                printf("无效输入。\n");
                pauseWait();
                continue;
            }
        }
    }
    
    if (currentId == -1) {
        printf("\n=== 游戏结束 ===\n");
        printf("按 Enter 返回菜单...");
        clearBuffer();
        getchar();
    }
}

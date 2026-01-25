#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// ===================== 数据结构定义 =====================
// 人物信息结构体（链表存储）
typedef struct Character {
    char name[50];      // 姓名
    int age;            // 年龄
    char hobby[100];    // 爱好
    char intro[200];    // 简介
    struct Character *next; // 下一个人物节点
} Character;

// 剧情节点结构体（支持分支，链表存储+ID索引）
typedef struct StoryNode {
    int id;                     // 节点唯一ID
    char speaker[50];           // 说话人姓名
    char content[500];          // 对话内容
    int branchCount;            // 分支数量（最多10个）
    char branchTexts[10][100];  // 分支显示文本
    int branchTargets[10];      // 分支对应的目标节点ID
    int nextId;                 // 无分支时的默认下一个节点ID
    struct StoryNode *next;     // 剧情链表节点
} StoryNode;

// ===================== 全局常量 =====================
#define CHAR_FILE "characters.txt"  // 人物存储文件
#define STORY_FILE "story.txt"      // 剧情存储文件
#define MAX_BRANCH 10               // 最大分支数

// ===================== 辅助函数 =====================
// 清空Mac终端输入缓冲区（解决换行符残留问题）
void clearInputBuffer() {
    while (getchar() != '\n'); // 清空缓冲区所有字符
}

// ===================== 人物管理模块 =====================
// 从TXT加载人物列表
Character* loadCharacters(const char *filename) {
    Character *head = NULL;
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("⚠️  人物文件不存在，将创建新文件\n");
        return NULL;
    }

    char line[512];
    while (fgets(line, sizeof(line), fp)) {
        // 去除换行符
        line[strcspn(line, "\n")] = '\0';
        if (strlen(line) == 0) continue;

        // 分割字段：姓名|年龄|爱好|简介
        Character *newChar = (Character*)malloc(sizeof(Character));
        char *token = strtok(line, "|");
        strcpy(newChar->name, token ? token : "未知");
        
        token = strtok(NULL, "|");
        newChar->age = token ? atoi(token) : 0;
        
        token = strtok(NULL, "|");
        strcpy(newChar->hobby, token ? token : "无");
        
        token = strtok(NULL, "|");
        strcpy(newChar->intro, token ? token : "无简介");

        // 插入链表头部
        newChar->next = head;
        head = newChar;
    }
    fclose(fp);
    printf("✅ 成功加载%d个人物（输入0查看）\n", head ? 1 : 0); // 简化计数，可扩展
    return head;
}

// 保存人物列表到TXT
void saveCharacters(Character *head, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("❌ 人物文件打开失败！\n");
        return;
    }

    Character *cur = head;
    while (cur) {
        fprintf(fp, "%s|%d|%s|%s\n", 
                cur->name, cur->age, cur->hobby, cur->intro);
        cur = cur->next;
    }
    fclose(fp);
    printf("✅ 人物已保存到 %s\n", filename);
}

// 添加新人物
void addCharacter(Character **head) {
    Character *newChar = (Character*)malloc(sizeof(Character));
    printf("\n===== 添加新人物 =====\n");
    
    printf("请输入姓名：");
    fgets(newChar->name, sizeof(newChar->name), stdin);
    newChar->name[strcspn(newChar->name, "\n")] = '\0'; // 去除换行
    
    printf("请输入年龄：");
    char ageStr[10];
    fgets(ageStr, sizeof(ageStr), stdin);
    newChar->age = atoi(ageStr);
    
    printf("请输入爱好：");
    fgets(newChar->hobby, sizeof(newChar->hobby), stdin);
    newChar->hobby[strcspn(newChar->hobby, "\n")] = '\0';
    
    printf("请输入简介：");
    fgets(newChar->intro, sizeof(newChar->intro), stdin);
    newChar->intro[strcspn(newChar->intro, "\n")] = '\0';

    // 插入链表
    newChar->next = *head;
    *head = newChar;
    
    saveCharacters(*head, CHAR_FILE); // 自动保存
    printf("✅ 人物【%s】添加成功！\n", newChar->name);
}

// 修改人物信息
void modifyCharacter(Character *head) {
    if (!head) {
        printf("❌ 暂无人物数据！\n");
        return;
    }

    char targetName[50];
    printf("\n===== 修改人物 =====\n");
    printf("请输入要修改的人物姓名：");
    fgets(targetName, sizeof(targetName), stdin);
    targetName[strcspn(targetName, "\n")] = '\0';

    // 查找人物
    Character *cur = head;
    while (cur) {
        if (strcmp(cur->name, targetName) == 0) {
            printf("当前信息：\n");
            printf("姓名：%s | 年龄：%d | 爱好：%s | 简介：%s\n",
                   cur->name, cur->age, cur->hobby, cur->intro);
            
            printf("输入新姓名（回车保留原姓名）：");
            char newName[50];
            fgets(newName, sizeof(newName), stdin);
            newName[strcspn(newName, "\n")] = '\0';
            if (strlen(newName) > 0) strcpy(cur->name, newName);

            printf("输入新年龄（回车保留原年龄）：");
            char newAge[10];
            fgets(newAge, sizeof(newAge), stdin);
            newAge[strcspn(newAge, "\n")] = '\0';
            if (strlen(newAge) > 0) cur->age = atoi(newAge);

            printf("输入新爱好（回车保留原爱好）：");
            char newHobby[100];
            fgets(newHobby, sizeof(newHobby), stdin);
            newHobby[strcspn(newHobby, "\n")] = '\0';
            if (strlen(newHobby) > 0) strcpy(cur->hobby, newHobby);

            printf("输入新简介（回车保留原简介）：");
            char newIntro[200];
            fgets(newIntro, sizeof(newIntro), stdin);
            newIntro[strcspn(newIntro, "\n")] = '\0';
            if (strlen(newIntro) > 0) strcpy(cur->intro, newIntro);

            saveCharacters(head, CHAR_FILE);
            printf("✅ 人物【%s】修改成功！\n", cur->name);
            return;
        }
        cur = cur->next;
    }
    printf("❌ 未找到人物【%s】！\n", targetName);
}

// 删除人物
void deleteCharacter(Character **head) {
    if (!*head) {
        printf("❌ 暂无人物数据！\n");
        return;
    }

    char targetName[50];
    printf("\n===== 删除人物 =====\n");
    printf("请输入要删除的人物姓名：");
    fgets(targetName, sizeof(targetName), stdin);
    targetName[strcspn(targetName, "\n")] = '\0';

    // 查找并删除节点
    Character *cur = *head, *prev = NULL;
    while (cur && strcmp(cur->name, targetName) != 0) {
        prev = cur;
        cur = cur->next;
    }

    if (!cur) {
        printf("❌ 未找到人物【%s】！\n", targetName);
        return;
    }

    // 调整链表指针
    if (prev) prev->next = cur->next;
    else *head = cur->next;

    free(cur);
    saveCharacters(*head, CHAR_FILE);
    printf("✅ 人物【%s】删除成功！\n", targetName);
}

// 打印所有人物
void printCharacters(Character *head) {
    if (!head) {
        printf("📜 暂无人物数据\n");
        return;
    }

    printf("\n===== 人物列表 =====\n");
    Character *cur = head;
    int idx = 1;
    while (cur) {
        printf("【%d】姓名：%s\n", idx++, cur->name);
        printf("   年龄：%d | 爱好：%s\n", cur->age, cur->hobby);
        printf("   简介：%s\n\n", cur->intro);
        cur = cur->next;
    }
}

// 释放人物链表内存
void freeCharacters(Character *head) {
    Character *cur = head, *tmp;
    while (cur) {
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
}

// ===================== 剧情管理模块 =====================
// 从TXT加载剧情节点
StoryNode* loadStory(const char *filename) {
    StoryNode *head = NULL;
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("⚠️  剧情文件不存在，将创建新文件\n");
        return NULL;
    }

    StoryNode *curNode = NULL;
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = '\0';
        if (strlen(line) == 0) continue;

        // 节点分隔符
        if (strcmp(line, "---") == 0) {
            if (curNode) {
                curNode->next = head;
                head = curNode;
                curNode = NULL;
            }
            continue;
        }

        // 初始化新节点
        if (!curNode) {
            curNode = (StoryNode*)malloc(sizeof(StoryNode));
            memset(curNode, 0, sizeof(StoryNode)); // 初始化所有字段为0
        }

        // 解析字段
        char *key = strtok(line, ":");
        char *value = strtok(NULL, ":");
        if (!key || !value) continue;

        if (strcmp(key, "ID") == 0) {
            curNode->id = atoi(value);
        } else if (strcmp(key, "Speaker") == 0) {
            strcpy(curNode->speaker, value);
        } else if (strcmp(key, "Content") == 0) {
            strcpy(curNode->content, value);
        } else if (strcmp(key, "BranchCount") == 0) {
            curNode->branchCount = atoi(value);
        } else if (strstr(key, "Branch") != NULL) {
            // 解析分支：BranchX:文本|目标ID
            int branchIdx = atoi(key + 6) - 1; // Branch1 → 索引0
            if (branchIdx >= 0 && branchIdx < MAX_BRANCH) {
                char *text = strtok(value, "|");
                char *target = strtok(NULL, "|");
                if (text) strcpy(curNode->branchTexts[branchIdx], text);
                if (target) curNode->branchTargets[branchIdx] = atoi(target);
            }
        } else if (strcmp(key, "Next") == 0) {
            curNode->nextId = atoi(value);
        }
    }

    // 处理最后一个节点
    if (curNode) {
        curNode->next = head;
        head = curNode;
    }

    fclose(fp);
    printf("✅ 成功加载剧情节点（输入0查看）\n");
    return head;
}

// 保存剧情节点到TXT
void saveStory(StoryNode *head, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("❌ 剧情文件打开失败！\n");
        return;
    }

    StoryNode *cur = head;
    while (cur) {
        fprintf(fp, "ID:%d\n", cur->id);
        fprintf(fp, "Speaker:%s\n", cur->speaker);
        fprintf(fp, "Content:%s\n", cur->content);
        fprintf(fp, "BranchCount:%d\n", cur->branchCount);
        
        // 保存分支
        for (int i = 0; i < cur->branchCount; i++) {
            fprintf(fp, "Branch%d:%s|%d\n", 
                    i+1, cur->branchTexts[i], cur->branchTargets[i]);
        }
        
        fprintf(fp, "Next:%d\n", cur->nextId);
        fprintf(fp, "---\n"); // 节点分隔符
        cur = cur->next;
    }

    fclose(fp);
    printf("✅ 剧情已保存到 %s\n", filename);
}

// 获取新的剧情节点ID（自增）
int getNewStoryId(StoryNode *head) {
    int maxId = 0;
    StoryNode *cur = head;
    while (cur) {
        if (cur->id > maxId) maxId = cur->id;
        cur = cur->next;
    }
    return maxId + 1;
}

// 通过ID查找剧情节点
StoryNode* findStoryNodeById(StoryNode *head, int id) {
    StoryNode *cur = head;
    while (cur) {
        if (cur->id == id) return cur;
        cur = cur->next;
    }
    return NULL;
}

// 添加新剧情节点
void addStoryNode(StoryNode **head) {
    StoryNode *newNode = (StoryNode*)malloc(sizeof(StoryNode));
    memset(newNode, 0, sizeof(StoryNode));
    
    printf("\n===== 添加剧情节点 =====\n");
    newNode->id = getNewStoryId(*head);
    printf("自动分配节点ID：%d\n", newNode->id);
    
    printf("请输入说话人姓名：");
    fgets(newNode->speaker, sizeof(newNode->speaker), stdin);
    newNode->speaker[strcspn(newNode->speaker, "\n")] = '\0';
    
    printf("请输入对话内容：");
    fgets(newNode->content, sizeof(newNode->content), stdin);
    newNode->content[strcspn(newNode->content, "\n")] = '\0';
    
    printf("请输入默认下一个节点ID（无则输0）：");
    char nextIdStr[10];
    fgets(nextIdStr, sizeof(nextIdStr), stdin);
    newNode->nextId = atoi(nextIdStr);
    
    newNode->branchCount = 0; // 初始无分支，后续可添加

    // 插入链表
    newNode->next = *head;
    *head = newNode;
    
    saveStory(*head, STORY_FILE);
    printf("✅ 剧情节点【ID:%d】添加成功！\n", newNode->id);
}

// 给剧情节点添加分支
void addBranchToStoryNode(StoryNode *head) {
    if (!head) {
        printf("❌ 暂无剧情节点！\n");
        return;
    }

    int targetId;
    printf("\n===== 添加剧情分支 =====\n");
    printf("请输入要添加分支的节点ID：");
    scanf("%d", &targetId);
    clearInputBuffer(); // 清空输入缓冲区

    StoryNode *node = findStoryNodeById(head, targetId);
    if (!node) {
        printf("❌ 未找到ID为%d的剧情节点！\n", targetId);
        return;
    }

    if (node->branchCount >= MAX_BRANCH) {
        printf("❌ 该节点已达最大分支数（%d）！\n", MAX_BRANCH);
        return;
    }

    int branchIdx = node->branchCount;
    printf("当前分支数：%d，新增第%d个分支\n", branchIdx, branchIdx+1);
    
    printf("请输入分支显示文本：");
    fgets(node->branchTexts[branchIdx], sizeof(node->branchTexts[branchIdx]), stdin);
    node->branchTexts[branchIdx][strcspn(node->branchTexts[branchIdx], "\n")] = '\0';
    
    printf("请输入分支目标节点ID：");
    char targetStr[10];
    fgets(targetStr, sizeof(targetStr), stdin);
    node->branchTargets[branchIdx] = atoi(targetStr);
    
    node->branchCount++; // 分支数+1

    saveStory(head, STORY_FILE);
    printf("✅ 分支添加成功！当前节点分支数：%d\n", node->branchCount);
}

// 释放剧情链表内存
void freeStory(StoryNode *head) {
    StoryNode *cur = head, *tmp;
    while (cur) {
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
}

// ===================== 模拟器运行模块 =====================
void runGalgame(StoryNode *storyHead, Character *charHead) {
    if (!storyHead) {
        printf("❌ 暂无剧情数据！\n");
        return;
    }

    // 从ID=1的节点开始（默认根节点）
    StoryNode *curNode = findStoryNodeById(storyHead, 1);
    if (!curNode) {
        printf("❌ 未找到根节点（ID=1），请先创建！\n");
        return;
    }

    printf("\n==================== GALGAME 模拟器 ====================\n");
    printf("🎮 按提示选择分支（输入数字），输入0退出模拟器\n\n");

    while (curNode) {
        // 显示说话人信息（如果存在）
        printf("【%s】\n", curNode->speaker);
        printf("└─ %s\n", curNode->content);
        
        // 显示分支选项
        if (curNode->branchCount > 0) {
            printf("\n请选择：\n");
            for (int i = 0; i < curNode->branchCount; i++) {
                printf("  %d. %s\n", i+1, curNode->branchTexts[i]);
            }
            printf("  0. 退出游戏\n");
            
            int choice;
            printf("你的选择：");
            scanf("%d", &choice);
            clearInputBuffer();

            if (choice == 0) break;
            if (choice < 1 || choice > curNode->branchCount) {
                printf("❌ 无效选择，跳过该节点\n");
                curNode = NULL;
                continue;
            }

            // 跳转到分支目标节点
            int targetId = curNode->branchTargets[choice-1];
            curNode = findStoryNodeById(storyHead, targetId);
        } else {
            // 无分支，跳转到默认下一个节点
            printf("\n按回车继续（输入0退出）...");
            char input[10];
            fgets(input, sizeof(input), stdin);
            if (strcmp(input, "0\n") == 0) break;

            int targetId = curNode->nextId;
            curNode = findStoryNodeById(storyHead, targetId);
        }

        if (!curNode) {
            printf("\n🎉 剧情结束！\n");
            break;
        }
        printf("\n----------------------------------------------------\n");
    }

    printf("\n👋 模拟器已退出\n");
}

// ===================== 主菜单 =====================
void showMainMenu() {
    printf("\n==================== GALGAME 编辑/模拟器 ====================\n");
    printf("1. 人物管理\n");
    printf("2. 剧情管理\n");
    printf("3. 运行GALGAME\n");
    printf("0. 退出程序\n");
    printf("============================================================\n");
    printf("请选择操作（0-3）：");
}

void showCharMenu() {
    printf("\n===== 人物管理 =====\n");
    printf("1. 添加人物\n");
    printf("2. 修改人物\n");
    printf("3. 删除人物\n");
    printf("4. 查看所有人物\n");
    printf("0. 返回主菜单\n");
    printf("请选择操作（0-4）：");
}

void showStoryMenu() {
    printf("\n===== 剧情管理 =====\n");
    printf("1. 添加剧情节点\n");
    printf("2. 给节点添加分支\n");
    printf("0. 返回主菜单\n");
    printf("请选择操作（0-2）：");
}

int main() {
    // 初始化：加载人物和剧情
    Character *charHead = loadCharacters(CHAR_FILE);
    StoryNode *storyHead = loadStory(STORY_FILE);

    int mainChoice, subChoice;
    while (true) {
        showMainMenu();
        scanf("%d", &mainChoice);
        clearInputBuffer(); // 清空输入缓冲区

        switch (mainChoice) {
            case 1: // 人物管理
                while (true) {
                    showCharMenu();
                    scanf("%d", &subChoice);
                    clearInputBuffer();

                    switch (subChoice) {
                        case 1: addCharacter(&charHead); break;
                        case 2: modifyCharacter(charHead); break;
                        case 3: deleteCharacter(&charHead); break;
                        case 4: printCharacters(charHead); break;
                        case 0: goto MAIN_MENU; // 返回主菜单
                        default: printf("❌ 无效选择！\n");
                    }
                }
                MAIN_MENU: break;

            case 2: // 剧情管理
                while (true) {
                    showStoryMenu();
                    scanf("%d", &subChoice);
                    clearInputBuffer();

                    switch (subChoice) {
                        case 1: addStoryNode(&storyHead); break;
                        case 2: addBranchToStoryNode(storyHead); break;
                        case 0: goto MAIN_MENU2; // 返回主菜单
                        default: printf("❌ 无效选择！\n");
                    }
                }
                MAIN_MENU2: break;

            case 3: // 运行模拟器
                runGalgame(storyHead, charHead);
                break;

            case 0: // 退出
                printf("\n👋 程序退出，正在保存数据...\n");
                saveCharacters(charHead, CHAR_FILE);
                saveStory(storyHead, STORY_FILE);
                freeCharacters(charHead);
                freeStory(storyHead);
                printf("✅ 数据已保存，内存已释放！\n");
                return 0;

            default:
                printf("❌ 无效选择，请重新输入！\n");
        }
    }
    system("pause");
    return 0;
}
/* galtool.c - 编辑器工具与文件操作 */
#include "galsys.h"

// --- 辅助工具 ---
void clearBuffer() {
    int c;//用int是因为EOF是-1,而char无法表示
    while ((c = getchar()) != '\n' && c != EOF);//一直读取缓冲区，直到遇到换行或文件结束，从而清除缓冲区
} //EOF是文件结束符

void pauseWait() {
    printf("\n按 Enter 键继续...");
    clearBuffer();
    getchar(); // 等待用户按下Enter，因为前面会清空缓冲区，留下一个换行符直接被读取
}

StoryNode* findNodeById(int id) { //标准从头到尾用ID找剧情节点
    StoryNode* current = headNode;
    while (current != NULL) {
        if (current->id == id) return current;
        current = current->next;
    }
    return NULL;
}

Character* findCharByName(char* name) { //从头到尾用名字找角色
    Character* c = headChar;
    while (c) {
        if (strcmp(c->name, name) == 0) return c;
        c = c->next;
    }
    return NULL;
}

StoryNode* getLastNode() { //获取链表最后一个节点
    if (headNode == NULL) return NULL;
    StoryNode* current = headNode;
    while (current->next != NULL) {
        current = current->next;
    }
    return current;
}

// --- 剧情操作 ---

void createNode() {
    system(CLEAR_SCREEN);
    printf("=== 创建新节点 ===\n");
    StoryNode* newNode = (StoryNode*)calloc(1, sizeof(StoryNode)); 
    
    StoryNode* last = getLastNode();
    if (last == NULL) {
        newNode->id = 1;
        headNode = newNode;
    } else {
        newNode->id = last->id + 1;
        last->next = newNode;
        
        // --- 自动修复逻辑连接 ---
        if (last->type == NODE_NORMAL && last->nextId == -1) {
            last->nextId = newNode->id;
            printf(">> [自动连接] 上一个剧情(ID:%d) 已指向新节点(ID:%d)\n", last->id, newNode->id);
        }
    }

    printf("节点 ID: %d\n", newNode->id);
    printf("剧情内容(请勿输入空格): "); scanf("%s", newNode->content); 
    
    printf("类型 (0:普通, 1:选项): ");
    int typeInput;
    scanf("%d", &typeInput);
    newNode->type = (typeInput == 1) ? NODE_BRANCH : NODE_NORMAL;

    // 预设默认值
    strcpy(newNode->opt1Target, STR_NONE);
    strcpy(newNode->opt1NewHobby, STR_NONE);
    strcpy(newNode->opt2Target, STR_NONE);
    strcpy(newNode->opt2NewHobby, STR_NONE);

    if (newNode->type == NODE_NORMAL) {
        // 修改提示：如果是连续写剧情，通常这里直接填 -1 即可，因为下一个节点创建时会自动连上它
        printf("下一剧情ID (输入 -1，后续创建新节点会自动连接): ");
        scanf("%d", &newNode->nextId);
        
        newNode->opt1NextId = -1;
        newNode->opt2NextId = -1;
        strcpy(newNode->opt1Text, STR_NONE);
        strcpy(newNode->opt2Text, STR_NONE);
    } else {
        newNode->nextId = -1; 
        
        // --- 选项 1 ---
        printf("\n[选项 1 设置]\n");
        printf("  描述: "); scanf("%s", newNode->opt1Text);
        printf("  跳转ID: "); scanf("%d", &newNode->opt1NextId);
        
        char hasEffect;
        printf("  是否影响人物? (y/n): ");
        clearBuffer(); scanf("%c", &hasEffect);
        if (hasEffect == 'y' || hasEffect == 'Y') {
            printf("  目标人物名: "); scanf("%s", newNode->opt1Target);
            printf("  好感度变更(如 10 或 -5): "); scanf("%d", &newNode->opt1LoveVal);
            printf("  解锁新爱好(输入NONE不解锁): "); scanf("%s", newNode->opt1NewHobby);
        }

        // --- 选项 2 ---
        printf("\n[选项 2 设置]\n");
        printf("  描述: "); scanf("%s", newNode->opt2Text);
        printf("  跳转ID: "); scanf("%d", &newNode->opt2NextId);
        
        printf("  是否影响人物? (y/n): ");
        clearBuffer(); scanf("%c", &hasEffect);
        if (hasEffect == 'y' || hasEffect == 'Y') {
            printf("  目标人物名: "); scanf("%s", newNode->opt2Target);
            printf("  好感度变更: "); scanf("%d", &newNode->opt2LoveVal);
            printf("  解锁新爱好(输入NONE不解锁): "); scanf("%s", newNode->opt2NewHobby);
        }
    }

    printf("创建成功！\n");
    printf("继续添加? (y/n): ");
    char choice;
    clearBuffer();
    scanf("%c", &choice);
    if (choice == 'y' || choice == 'Y') createNode();
}

void modifyNode() {
    int id;
    printf("输入要修改内容的节点ID: ");
    scanf("%d", &id);
    StoryNode* node = findNodeById(id);
    if (node == NULL) { printf("ID不存在。\n"); return; }
    
    printf("旧内容: %s\n", node->content);
    printf("新内容: "); scanf("%s", node->content);
    printf("修改完成。\n");
}

// 修改节点跳转关系
void modifyNodeNextId() {
    int id;
    printf("输入要修改跳转关系的节点ID: ");
    scanf("%d", &id);
    StoryNode* node = findNodeById(id);
    if (node == NULL) { 
        printf("ID不存在。\n"); 
        return; 
    }

    if (node->type == NODE_NORMAL) {
        // 普通剧情节点
        printf("当前跳转指向: %d\n", node->nextId);
        printf("请输入新的下一剧情ID (-1表示结束): ");
        scanf("%d", &node->nextId);
    } 
    else {
        // 分支选项节点
        printf("当前跳转指向 -> 选项1去往: %d | 选项2去往: %d\n", 
               node->opt1NextId, node->opt2NextId);
        printf("你要修改哪个选项的跳转? (输入 1 或 2): ");
        int choice;
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("请输入选项1的新跳转ID: ");
            scanf("%d", &node->opt1NextId);
        } else if (choice == 2) {
            printf("请输入选项2的新跳转ID: ");
            scanf("%d", &node->opt2NextId);
        } else {
            printf("无效选择。\n");
            return;
        }
    }
    printf("跳转关系修改完成！\n");
}

void deleteNode() {
    int id;
    printf("输入要删除的节点ID: ");
    scanf("%d", &id);
    StoryNode *current = headNode, *prev = NULL;
    while (current != NULL) {
        if (current->id == id) {
            if (prev == NULL) headNode = current->next;
            else prev->next = current->next;
            free(current);
            printf("节点 %d 已删除。\n", id);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("未找到节点。\n");
}

void printAllNodes() {
    system(CLEAR_SCREEN);
    printf("=== 所有剧情节点 ===\n");
    StoryNode* curr = headNode;
    while (curr) {
        printf("[ID:%d] %s\n", curr->id, curr->content);
        if (curr->type == NODE_BRANCH) {
            printf("  选项1: %s (跳到:%d) -> 影响人物:%s 好感度变化:%d 爱好解锁:%s\n", 
                curr->opt1Text, curr->opt1NextId, curr->opt1Target, curr->opt1LoveVal, curr->opt1NewHobby);
            printf("  选项2: %s (跳到:%d) -> 影响人物:%s 好感度变化:%d 爱好解锁:%s\n", 
                curr->opt2Text, curr->opt2NextId, curr->opt2Target, curr->opt2LoveVal, curr->opt2NewHobby);
        } else {
            printf("  下一剧情: %d\n", curr->nextId);
        }
        printf("-------------------\n");
        curr = curr->next;
    }
}

// --- 人物操作 ---

void addCharacter() {
    Character* newChar = (Character*)malloc(sizeof(Character));
    printf("人物名字: "); scanf("%s", newChar->name);
    printf("初始好感度: "); scanf("%d", &newChar->loveLevel);
    newChar->initLove = newChar->loveLevel; // 创建时，初始值 = 当前值
    printf("初始爱好 (未知填 ???): "); scanf("%s", newChar->hobby);
    strcpy(newChar->initHobby, newChar->hobby); // 创建时，初始值 = 当前值
    printf("一句话简介: "); scanf("%s", newChar->desc);
    newChar->next = headChar;
    headChar = newChar;
    printf("人物 %s 已添加。\n", newChar->name);
}

void deleteCharacter() {
    char name[MAX_NAME];
    printf("输入要删除的人名: "); scanf("%s", name);
    Character *current = headChar, *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) headChar = current->next;
            else prev->next = current->next;
            free(current);
            printf("已删除。\n"); return;
        }
        prev = current; current = current->next;
    }
    printf("未找到。\n");
}

void modifyCharacter() {
    char name[MAX_NAME];
    printf("输入要修改的人名: "); scanf("%s", name);
    Character *c = findCharByName(name);
    if(c) {
        printf("当前: 好感[%d] 爱好[%s] 简介[%s]\n", c->loveLevel, c->hobby, c->desc);
        printf("新好感度: "); scanf("%d", &c->loveLevel);
        printf("新爱好: "); scanf("%s", c->hobby);
        printf("新简介: "); scanf("%s", c->desc);
        printf("修改成功。\n");
    } else {
        printf("未找到。\n");
    }
}

void printAllChars() {
    printf("\n=== 人物状态列表 ===\n");
    Character* c = headChar;
    if(!c) printf("暂无人物。\n");
    while (c) {
        printf("姓名: %-8s | 好感度: %d| 爱好: %s | %s\n", 
            c->name, c->loveLevel, c->hobby, c->desc);
        c = c->next;
    }
}

void printAllCharsDetailed() {
    printf("\n=== 人物列表 (开发者详细模式) ===\n");
    printf("格式: 姓名 | 当前好感(初始) | 当前爱好(初始) | 简介\n");
    Character* c = headChar;
    if(!c) printf("暂无人物。\n");
    while (c) {
        printf("%-8s | %3d (%3d)   | %-6s (%-6s) | %s\n", 
            c->name, 
            c->loveLevel, c->initLove, 
            c->hobby, c->initHobby, 
            c->desc);
        c = c->next;
    }
}


// --- 文件操作 ---

void saveStory(const char* filename) {
    FILE* fp = fopen(filename, "w");
    if (!fp) { perror("无法保存"); return; }
    StoryNode* c = headNode;
    while (c) {
        // 多行存储格式
        fprintf(fp, "%d %d %d %s\n", c->id, c->type, c->nextId, c->content);
        fprintf(fp, "%s %d %s %d %s\n", 
            c->opt1Text, c->opt1NextId, c->opt1Target, c->opt1LoveVal, c->opt1NewHobby);
        fprintf(fp, "%s %d %s %d %s\n", 
            c->opt2Text, c->opt2NextId, c->opt2Target, c->opt2LoveVal, c->opt2NewHobby);
        c = c->next;
    }
    fclose(fp);
    printf("剧情已保存至 %s\n", filename);
}

void loadStory(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) { printf("未找到剧情文件 %s。\n", filename); return; }
    headNode = NULL; 
    
    while (!feof(fp)) {
        StoryNode* node = (StoryNode*)calloc(1, sizeof(StoryNode));
        int count = fscanf(fp, "%d %d %d %s", &node->id, (int*)&node->type, &node->nextId, node->content);
        if (count < 4) { free(node); break; }
        
        fscanf(fp, "%s %d %s %d %s", 
            node->opt1Text, &node->opt1NextId, node->opt1Target, &node->opt1LoveVal, node->opt1NewHobby);
        fscanf(fp, "%s %d %s %d %s", 
            node->opt2Text, &node->opt2NextId, node->opt2Target, &node->opt2LoveVal, node->opt2NewHobby);

        node->next = NULL;
        StoryNode* last = getLastNode();
        if (!last) headNode = node;
        else last->next = node;
    }
    fclose(fp);
    printf("剧情已加载。\n");
}

void saveChars(const char* filename) {
    FILE* fp = fopen(filename, "w");
    if (!fp) return;
    Character* c = headChar;
    while(c) {
        // 保存格式：名字 当前好感 初始好感 当前爱好 初始爱好 简介
        fprintf(fp, "%s %d %d %s %s %s\n", 
            c->name, c->loveLevel, c->initLove, c->hobby, c->initHobby, c->desc);
        c = c->next;
    }
    fclose(fp);
    printf("人物已保存至 %s\n", filename);
}

void loadChars(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) { printf("未找到人物文件 %s (可忽略)。\n", filename); return; }
    headChar = NULL;
    while(!feof(fp)) {
        Character* newChar = (Character*)malloc(sizeof(Character));
        // 读取格式必须和保存格式一致
        int count = fscanf(fp, "%s %d %d %s %s %s", 
            newChar->name, 
            &newChar->loveLevel, &newChar->initLove, 
            newChar->hobby, newChar->initHobby, 
            newChar->desc);
            
        if(count < 6) { free(newChar); break; } // 如果读不到6个数据，说明行不完整
        
        newChar->next = headChar;
        headChar = newChar;
    }
    fclose(fp);
    printf("人物已加载。\n");
}

void resetCharsToInitial() {
    Character* c = headChar;
    while (c) {
        c->loveLevel = c->initLove;       // 还原好感
        strcpy(c->hobby, c->initHobby);   // 还原爱好
        c = c->next;
    }
    printf(">> 所有人物状态已重置为初始值。\n");
}
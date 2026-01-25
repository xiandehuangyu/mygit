/* galsys.h - 头文件 */
#ifndef GALSYS_H
#define GALSYS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- 跨平台兼容设置 ---
#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif

// --- 常量定义 ---
#define MAX_CONTENT 512 // 节点内容最大长度
#define MAX_NAME 50     // 角色名最大长度
#define MAX_OPT 100     // 选项文本最大长度
#define STR_NONE "NONE" // 用于文件存储时的空占位符

// --- 节点类型枚举 ---
typedef enum {
    NODE_NORMAL = 0, // 普通剧情（按回车继续）
    NODE_BRANCH = 1  // 分支剧情（需要选择）
} NodeType;

// --- 剧情节点结构体 ---
typedef struct StoryNode {
    int id;
    char content[MAX_CONTENT];
    NodeType type;
    
    int nextId; // 普通节点的下一跳

    // --- 选项 1 数据 ---
    char opt1Text[MAX_OPT]; //文本
    int opt1NextId;         //跳转ID
    // 选项1的影响
    char opt1Target[MAX_NAME];    // 影响的角色名
    int opt1LoveVal;              // 好感度变化值
    char opt1NewHobby[MAX_OPT];   // 解锁的爱好

    // --- 选项 2 数据 ---
    char opt2Text[MAX_OPT]; //文本
    int opt2NextId;         //跳转ID
    // 选项2的影响
    char opt2Target[MAX_NAME]; //影响的角色名
    int opt2LoveVal;           //好感度变化值
    char opt2NewHobby[MAX_OPT];//解锁的爱好

    struct StoryNode* next; // 链表指针
} StoryNode;

// --- 人物结构体 ---
typedef struct Character {
    char name[MAX_NAME];
    int loveLevel;          // 当前好感度 (会变)
    int initLove;           // 初始好感度 (永远不变，用于重置)
    char hobby[MAX_OPT];    // 当前爱好 (会变)
    char initHobby[MAX_OPT];// 初始爱好 (永远不变，用于重置)
    char desc[MAX_CONTENT]; // 简单介绍
    struct Character* next; 
} Character;

// --- 全局变量声明 ---
extern StoryNode* headNode;
extern Character* headChar;

// --- galtool.c 函数声明 (工具与文件) ---
void loadStory(const char* filename);//读取
void saveStory(const char* filename);//保存
void loadChars(const char* filename);//读取
void saveChars(const char* filename);//保存
void resetCharsToInitial(); // 重置所有角色到初始状态

void createNode();      // 添加节点
void modifyNode();      // 修改节点内容
void modifyNodeNextId();// 修改节点跳转关系
void deleteNode();      // 删除节点
void printAllNodes();   // 显示所有节点

void addCharacter();    // 添加角色
void deleteCharacter(); // 删除角色
void modifyCharacter(); // 修改角色
void printAllChars();   // 显示所有角色
void printAllCharsDetailed();// 显示所有角色详细信息

// 辅助函数
StoryNode* findNodeById(int id);       // 根据ID查找节点
Character* findCharByName(char* name); // 根据名字查找角色
void clearBuffer();                    // 清空输入缓冲区
void pauseWait();                      // 暂停等待输入

// --- gal_opera.c 函数声明 (运行模拟) ---
void runGame(); // 运行游戏

#endif
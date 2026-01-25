#ifndef GAL_SYSTEM_H  
#define GAL_SYSTEM_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHARACTER_FILE "character.txt"
#define SPOT_FILE "spot.txt"
typedef struct Character {       
    char name[30];     
    char hobby[30];          
    int age;
    char jieshao[100];
} Character;

typedef struct StoryNode {
    int id;
    char speaker[50];
    char content[500];
    int branchCount;
    char branchTexts[10][100];
    int branchTargets[10];
    int nextId;
    struct StoryNode *next;
} StoryNode;

void clearScreen(); 
void addCharacter();                    
void showAllCharacters();                                             
void deleteCharacterById();              
void pauseprogram();
void addSpot();
#endif 
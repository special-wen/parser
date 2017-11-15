//
// Created by zxw on 17-11-13.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//所有的文法
typedef struct Program{
    int id;
    char letter;
    struct Program *next;
}program;

typedef struct Left{
    int idLeft;
    char leftLetter;
    struct Left *next;
}left;

typedef struct Right{
    int idRight;
    char rightLetter;
    struct Right *next;
}right;

//遍历文法
int searchProgram(program *headProgram);
char search(int num,program *headProgram);

//判断什么类型的左递归
int typeElimination(char program);
//直接消除左递归
int directElimination(char program);

int insertProgram(char letter,program *headProgram);

//左部插入
int insertLeft(char letter,left *headLeft);
//右部插入
int insertRight(char letter,right *headRight);
//分析右部
int analysisRight(right *headRight);

program *headProgram;
left *headLeft;
right *headRight;
int main(int argc,char *argv[]){
    int length = 0;
    char fileName[20];
    FILE *fp;
    char buffer[200];
    char ch;
    headProgram = malloc(sizeof(program));
    headProgram -> next = NULL;
    headProgram ->id = 0;
    headLeft = malloc(sizeof(left));
    headLeft -> next = NULL;
    headLeft->idLeft = 0;
    headRight = malloc(sizeof(right));
    headRight -> next = NULL;
    headLeft->idLeft = 0;
    //文法
    printf("请输入文法所在的文件地址：");
    scanf("%s",fileName);
    fp = fopen(fileName,"r");
    //按行读取文法：
    while (fgets(buffer, sizeof(buffer),fp)){
        int i = 0;
        while (buffer[i] != '\0'){
            ch = buffer[i];
            insertProgram(ch,headProgram);
            //printf(" %c",ch);
            i++;
        }
        //printf("%d \n",i-1);
    }
    fclose(fp);
}

//进行插入
int insertProgram(char letter,program *headProgram){
    if(letter != '\n'){
        program *temp;
        program *newProgram;
        temp = headProgram;
        while (temp -> next != NULL){
            temp = temp->next;
        }
        newProgram = malloc(sizeof(program));
        newProgram ->next = temp->next;
        temp->next = newProgram;
        newProgram -> id = temp->id+1;
        newProgram->letter = letter;
        printf("%c %d\n",newProgram->letter,newProgram->id);
        return newProgram->id;
    }
}

//遍历找到分隔符位置
int searchProgram(program *headProgram){
    headProgram *temp;
    headProgram *flag;
    temp = headProgram->next;
    while (temp != NULL){
        if(temp->next -> letter == '-'){
            flag = temp->next;
            if(flag->next ->letter == '>') {
                return flag->id;
            }
        }
    }
}

//分割左右部分
char search(int num,program *headProgram){
    program *temp;
    temp = headProgram->next;
    while (temp != NULL){
        if(temp->id < num){
            insertLeft(temp->letter,*headLeft);
        }
        if(temp ->id +1 > num){
            insertRight(temp->letter,*headRight);
        }
        temp = temp->next;
    }
}

//判断是否为直接左递归
int typeElimination(){


}

//直接消除左递归
int directElimination(left *headLeft,int flag){

}

//左部插入
int insertLeft(char letter,left *headLeft){
    left *temp,*flag;
    temp = headLeft;
    while (temp->next!=NULL){
        temp = temp->next;
    }
    flag = malloc(sizeof(left));
    flag->next = temp->next;
    temp->next = flag;
    flag->id = temp->id+1;
    flag->leftLetter =letter;
    return flag->id;
}
//右部插入
int insertRight(char letter,right *headRight){
    right *temp,*flag;
    temp = headRight;
    while (temp->next!=NULL){
        temp = temp->next;
    }
    flag = malloc(sizeof(right));
    flag->next = temp->next;
    temp->next = flag;
    flag->id = temp->id+1;
    flag->rightLetter = letter;
    return flag->id;
}

//分析右部
int analysisRight(left *headLight,right *headRight){
    left *temp;
    right *flag;
    temp = headLight->next;
    flag = headRight->next;
    char let;
    while (temp != NULL){
        let = temp->leftLetter;
        while (flag != NULL){
            //找到直接左递归
            if(let == flag->rightLetter){
                flag = flag->next;
                while (flag != NULL){
                    if(flag->rightLetter == '|'){
                        return flag->id;
                    }
                }
            }
            //简接左递归
            else{

            }
        }
    }
}
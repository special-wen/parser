//
// Created by zxw on 17-11-15.
//

//
// Created by zxw on 17-11-13.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
//判断什么类型的左递归
int typeElimination(char program);
//直接消除左递归
int directElimination(char program);

//左部插入
int insertLeft(char letter,left *headLeft);
//右部插入
int insertRight(char letter,right *headRight);

int insert(char letter,left *headLeft,right *headRight);

left *headLeft;
right *headRight;
int main(int argc,char *argv[]){
    int length = 0;
    char fileName[20];
    FILE *fp;
    char buffer[200];
    char ch;
    headLeft = malloc(sizeof(left));
    headLeft -> next = NULL;
    headLeft->idLeft = 0;
    headRight = malloc(sizeof(right));
    headRight -> next = NULL;
    headLeft->idRight = 0;
    //文法
    printf("请输入文法所在的文件地址：");
    scanf("%s",fileName);
    fp = fopen(fileName,"r");
    //按行读取文法：
    while (fgets(buffer, sizeof(buffer),fp)){
        int i = 0;
        while (buffer[i] != '\0'){
            ch = buffer[i];
            insert(ch,headLeft,headRight);
            printf(" %c",ch);
            i++;
        }
        printf("%d \n",i-1);
    }
    fclose(fp);

}

//进行插入
int insert(char letter,left *headLeft,right *headRight){
    int temp = 0;
    left *flagLeft;
    flagLeft = headLeft;
    while (flagLeft -> next != NULL){
        flagLeft = flagLeft->next;
    }
    if(headLeft->idLeft == 0){
        while (letter > 'a' && letter < 'z' || letter >'A' && letter<'Z'){
            temp++;

        }
        if(letter == '>'){

        }
    }

    //insertLeft(letter);

}

//判断是否为直接左递归
int typeElimination(){

}

//直接消除左递归
int directElimination(){

}

//左部插入
int insertLeft(char letter,left *headLeft){

}
//右部插入
int insertRight(char letter,right *headRight);
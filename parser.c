//
// Created by zxw on 17-11-13.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
    int length = 0;
    char fileName[20];
    FILE *fp;
    char buffer[200];
    //文法
    printf("请输入文法所在的文件地址：");
    scanf("%s",fileName);
    fp = fopen(fileName,"r");
    //按行读取文法：
    while (fgets(buffer, sizeof(buffer),fp)){
        length++;
    }
    fclose(fp);
    printf("%d\n",length);
}


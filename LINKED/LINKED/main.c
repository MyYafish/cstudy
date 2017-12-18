//
//  main.c
//  LINKED
//
//  Created by 吴鹏 on 2017/12/18.
//  Copyright © 2017年 Peng Wu. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <mm_malloc.h>


typedef struct Node {
    int data ;
    struct Node * pNext;
} Node , *pNode;

pNode _create_list(){
    int len , i;
    printf("请输入长度\n");
    scanf("%d",&len);
    pNode phead = malloc(sizeof(Node));
    phead->pNext = NULL;
    pNode pTail = phead;
    for(i = 0; i < len ;i++){
        pNode pnew = malloc(sizeof(Node));
        pnew->data = i;
        pnew->pNext=NULL;
        pTail->pNext = pnew;
        pTail = pnew;
    }
    return phead;
}

int main(int argc, const char * argv[]) {
    pNode node  =  _create_list();
    return 0;
}

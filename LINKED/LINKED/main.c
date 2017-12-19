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


pNode _initLinked(){
    pNode node = malloc(sizeof(node));
    node->pNext = NULL;
    return node;
}

pNode _creatLinkedInsterFromHead(){
    pNode node = _initLinked();
    int len , i;
    scanf("%d",&len);
    for(i = 0 ; i < len ; i++){
        pNode p = _initLinked();
        p->data = i;
        p->pNext = node;
        node = p;
    }
    return node;
}

pNode _creatLinkedInsterFromTail(){
    pNode node = _initLinked();
    pNode r = _initLinked();
    r = node;
    int len ,i ;
    scanf("%d",&len);
    for (i = 0 ; i < len; i++) {
        pNode p = _initLinked();
        p->data = i;
        r->pNext = p;//head ->0 ->1 ->2 ->NULL
        r = p;
    }
    r->pNext = NULL;
    return node;
}

pNode _linkedInsterItem(pNode node , int location , int data){
    pNode pp = node;
    for (int i =  1; i<location; i++) {
        pp = pp->pNext;
    }
    pNode  p = _initLinked();
    p->data = data;
    p->pNext = pp->pNext;
    pp->pNext = p;
    
    return node;
}

pNode _linkedDeleItem(pNode node , int data ){
    pNode p,pp = NULL;
    p = node->pNext;
    while (p->data != data) {
        pp = p;
        p = p->pNext;
    }
    pp->pNext = p->pNext;
    free(p);
    return node;
}

void _cleraLinked(pNode node){
    if(node == NULL){
        return;
    }
    pNode p;
    while (node->pNext != NULL) {
        p = node->pNext;
        free(node);
        node = p;
    }
}

int  _linkedSize(pNode node){
    int size = 0;
    while (node->pNext != NULL) {
        size ++;
        node = node->pNext;
    }
    return size;
}

int _getLinkedItem(pNode node , int location){
    int i = 0 ;
    while (node->pNext != NULL) {
        node = node->pNext;
        ++i;
        if(location == i){
            return node->data;
        }
    }
    return node->data;
}

void _linkedInsterItemHeader(pNode * node , int dataa){
    pNode p = _initLinked();
    p->data = dataa;
    p->pNext = (*node)->pNext;
    *node = p;
}

void _linkedInsterItemTail(pNode node , int data){
    pNode p = _initLinked();
    p->data = data;
    p->pNext = NULL;
    while (node->pNext != NULL) {
        node = node->pNext;
    }
    node->pNext = p;
}

void _printLinked(pNode node){
    if(node != NULL){
        do {
            printf(" %d ",node->data);
            node = node->pNext;
        } while (node!=NULL);
    }
}

void _linkedReplace(pNode node , int data  , int replacedata){
    while (node->pNext != NULL) {
        if(node->data == data){
            node->data = replacedata;
            return;
        }
        node = node->pNext;
    }
}

void _linkedRplaceWithTag(pNode node , int tag , int replaceData){
    int size = 1;
    while (node->pNext != NULL) {
        if(size == tag){
            node->data = replaceData;
            return;
        }
        size++;
        node = node->pNext;
    }
}

int main(int argc, const char * argv[]) {
    pNode list;
    list = _creatLinkedInsterFromTail();
    list = _linkedInsterItem(list, 5, 6);
    list = _linkedDeleItem(list, 6);
    _linkedInsterItemHeader(&list, 111);
    _linkedInsterItemTail(list, 22);
    _linkedReplace(list, 2 ,33);
    _linkedRplaceWithTag(list, 1, 44);
    _printLinked(list);
    _cleraLinked(list);
    return 0;
}

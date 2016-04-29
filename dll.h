#ifndef _DLL_H
#define _DLL_H
#include <stdio.h>
#include <stdlib.h>

struct dnode {
        int value;
        struct dnode *next;
        struct dnode *prev;
};
typedef struct dnode Node;

struct list {
        struct dnode *start;
        struct dnode *end;
	int qty;
};
typedef struct list List;

List *append(List * myList, Node * place, Node * newNode);
List *getNode(List * myList, Node ** place);
List *build();
List *insert(List * myList, Node * place, Node * newNode);
void displayf(List * myList);
void displayb(List * myList);
List *sortList(List * myList);
List *mklist();
Node *create();
#endif

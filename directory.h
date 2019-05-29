#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct list{
    int ID;
    char name[30];
    char phone[30];
    char Email[50];
};
typedef struct list List;

struct node{
	List directory;
    struct node *nextPtr;
};
typedef struct node Node; 

int isEmpty(Node *startPtr);

void printList(Node **startPtr);

void insert(Node **startPtr);

void del(Node **startPtr);

void search(Node **startPtr);

void modify(Node **startPtr);

void clear(Node **startPtr);

void output(Node **startPtr);

void input(Node **startPtr);

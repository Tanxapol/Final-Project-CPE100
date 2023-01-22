#ifndef BOOK_H
#define BOOK_H

//  [ kong borrow ] -> [ mix borrow ] -> [ sorn borrow ] -> NULL

//  "Doubly Linked List"
//  [ kong borrow ] -> <- [ mix borrow ] -> <- [ sorn borrow ] -> NULL

// print
// HISTORY_T* listhead = &[ kong borrow ]
// HISTORY_T* curNode = listhead;
// while(curNode != NULL)
//   printf("history = %s\n", curNode->history);
//   curNode = listhead->next;

typedef struct _node{
  char history[50];
  struct _node* next; 
} HISTORYNODE_T;

typedef struct{
  HISTORYNODE_T* head;
} HISTORY_T;

typedef struct {
    char namebook[100];
    char author[50];
    char year[10];
    char status[10];
    HISTORY_T* history;
} DATABOOK_T;

typedef struct {
    DATABOOK_T* data;
    int currentSize;
    int maxSize;
} STORE_T;

STORE_T* libraryCreate(int count);
void bookCreate(STORE_T* store, DATABOOK_T* databook);
int historyAppend(HISTORY_T* list, char* data); 

#endif
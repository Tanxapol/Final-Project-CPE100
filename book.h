#ifndef BOOK_H
#define BOOK_H

/*
 * struct to keep the state history
 */
typedef struct _node {
  char history[100];
  struct _node* next;
  struct _node* prev;
} HISTORYNODE_T;

/*
 * struct to keep history node head
*/
typedef struct {
  HISTORYNODE_T* head;
} HISTORY_T;

/* 
 * struct to keep data for book
*/
typedef struct {
  char namebook[100];
  char author[100];
  char year[10];
  char status[10];
  char borrowName[90];
  HISTORY_T* history;
} DATABOOK_T;

/*
 * struct for keeping data of books and its size and current member count
*/
typedef struct {
  DATABOOK_T* data;
  int currentSize;
  int maxSize;
} STORE_T;

/* Expand the size of available memory for DATABOOK_T inside STORE_T of its current size 
 * Arguments 
 *  store - pointer to store 
 * Returns nothing
 */
STORE_T* libraryCreate(int count);

/* Create new book with its memory allocated
 * Arguments
 *  store - pointer to store
 *  databook - pointer to databook
 * Returns nothing
 */
void bookCreate(STORE_T* store, DATABOOK_T* databook);

/* get a data into HISTORYNODE_T and append to HISTORY_T
 * Arguments
 *  list - HISTORY_T that is going to be appended
 *  data - appending str
 * Returns 1 if there was no error
 */
int historyAppend(HISTORY_T* list, char* data);

#endif
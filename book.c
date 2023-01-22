#include "book.h"
#include <stdlib.h>
#include <string.h>

/* Expand the size of available memory for DATABOOK_T inside STORE_T of its current size 
 * Arguments 
 *  store - pointer to store 
 * Returns nothing
 */
void listExpand(STORE_T* store) {
  DATABOOK_T* temp = (DATABOOK_T*)calloc(store->maxSize * 2, sizeof(DATABOOK_T));
  for (int i = 0; i < store->currentSize; i++) {
    temp[i] = store->data[i];
  }
  free(store->data);
  store->data = temp;
  store->maxSize *= 2;
}

/*-------------------------------------------------------*/

/* Create a STORE_T with its memory calloced
 * Arguments
 *   count - size of array of DATABOOK_T
 * Returns pointer to the STORE_T that is calloced
 */
STORE_T* libraryCreate(int count) {
  STORE_T* store = (STORE_T*)calloc(1, sizeof(STORE_T));
  store->data = (DATABOOK_T*)calloc(count, sizeof(DATABOOK_T));
  store->data->history = (HISTORY_T*)calloc(1, sizeof(HISTORY_T));
  store->currentSize = 0;
  store->maxSize = count;
  return store;
}

/* Create new book with its memory allocated
 * Arguments
 *  store - pointer to store
 *  databook - pointer to databook
 * Returns nothing
 */
void bookCreate(STORE_T* store, DATABOOK_T* databook) {
  if (store->currentSize == store->maxSize) {
    listExpand(store);
  }
  store->data[store->currentSize] = *databook;
  store->data[store->currentSize].history = (HISTORYNODE_T*)calloc(1, sizeof(HISTORYNODE_T));
  store->currentSize++;
}

/* get a data into HISTORYNODE_T and append to HISTORY_T
 * Arguments
 *  list - HISTORY_T that is going to be appended
 *  data - appending str
 * Returns 1 if there was no error
 */
int historyAppend(HISTORY_T* list, char* data) {
  HISTORYNODE_T* node = (HISTORYNODE_T*)calloc(1, sizeof(HISTORYNODE_T));
  strcpy(node->history, data);
  node->next = (list->head);
  node->prev = NULL;
  if (list->head != NULL) {
    list->head->prev = node;
  }
  list->head = node;
  return 1;
}
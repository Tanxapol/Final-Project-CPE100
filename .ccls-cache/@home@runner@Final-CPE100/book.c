#include"book.h"
#include<stdlib.h>
#include<string.h>

void listExpand(STORE_T* store){
    DATABOOK_T* tmp = (DATABOOK_T*)calloc(store->maxSize * 2, sizeof(DATABOOK_T));
    for (int i=0; i<store->currentSize; i++){
      tmp[i] = store->data[i];
    }
    free(store->data);
    store->data = tmp;
    store->maxSize *= 2;
}

HISTORY_T* historyCreate(){
    HISTORY_T* list = (HISTORY_T *) calloc(1, sizeof(HISTORY_T));
    return list;
}

STORE_T* libraryCreate(int count){
    STORE_T* store = (STORE_T*)calloc(1, sizeof(STORE_T));
    store->data = (DATABOOK_T*)calloc(count, sizeof(DATABOOK_T));
    store->data->history = historyCreate();
    store->currentSize = 0;
    store->maxSize = count;
    return store;
}

int historyAppend(HISTORY_T* list, char* data){
  HISTORYNODE_T* node = (HISTORYNODE_T*) calloc(1, sizeof(HISTORYNODE_T));
  strcpy(node->history, data);
  if(list->head == NULL){
    list->head = node;
  }
  return 1;
}

void bookCreate(STORE_T* store, DATABOOK_T* databook){
  if (store->currentSize == store->maxSize){
    listExpand(store);
  }
  store->data[store->currentSize] = *databook;
  store->currentSize++;
}
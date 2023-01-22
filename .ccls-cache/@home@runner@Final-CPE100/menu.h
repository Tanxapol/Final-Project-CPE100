#ifndef MENU_H
#define MENU_H

int addBook(STORE_T* store);
int removeBook(STORE_T* store);
int editBook(STORE_T* store);
int showAllBooks(STORE_T* store);
int searchBook(STORE_T* store);
int borrowBook(STORE_T* store);
int returnBook(STORE_T* store);

#endif
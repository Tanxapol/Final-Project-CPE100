#include "book.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

/* Print the control menu and get input from user
 * Returns integer representing user's choice
 */
int getSelectMenu() {
  printf("\n");
  printf("Menu\n");
  printf("1) Add book\n");
  printf("2) Remove book\n");
  printf("3) Edit book\n");
  printf("4) Show all book\n");
  printf("5) Search book\n");
  printf("6) Borrow book\n");
  printf("7) Return book\n");
  printf("8) Exit\n");
  int selectMenu;
  scanf("%d", &selectMenu);
  fgetc(stdin);
  printf("\n");
  return selectMenu;
}

int main() {
  /* Create a store */
  STORE_T* store = libraryCreate(1);

  /* Load the data from storeData.txt into store */
  loadFile(store);

  printf("Welcome to Library Management System\n");
  int selectMenu = getSelectMenu();

  /* Loop until user choose to exit and run function of user's choice */
  while (selectMenu != 8) {
    if (selectMenu == 1) {
      addBook(store);
    } else if (selectMenu == 2) {
      removeBook(store);
    } else if (selectMenu == 3) {
      editBook(store);
    } else if (selectMenu == 4) {
      showAllBooks(store);
    } else if (selectMenu == 5) {
      searchBook(store);
    } else if (selectMenu == 6) {
      borrowBook(store);
    } else if (selectMenu == 7) {
      returnBook(store);
    }
    selectMenu = getSelectMenu();
  }

  /* Save store data into storeData.txt */
  saveFile(store);

  printf("Thank you");
  return 0;
}
#include "book.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 101

/* Print out a specific book
 * Arguments
 *  store - pointer to store
 *  index - book index
 * Returns nothing
*/
int printBook(STORE_T* store, int index) {
  printf("Title: %s\n", store->data[index].namebook);
  printf("Author Name: %s\n", store->data[index].author);
  printf("Publish year: %s\n", store->data[index].year);
  printf("Status: %s\n", store->data[index].status);
  printf("Borrowing History: \n");
  historyPrint(store->data[index].history);
  printf("\n");
}

/* Find the index of a book with a specific name
 * Arguments
 *    store - store that is being searched
 *    namebook - the name of the book
 * Returns the index to the book with the specified name
 *         -1 if there's no match
*/
int findIndexBook(STORE_T* store, char* namebook) {
  for (int i = 0; i < store->currentSize; i++) {
    if (strcmp(store->data[i].namebook, namebook) == 0) {
      return i;
    }
  }
  return -1;
}

/* Delete \n from the end of an input
 * Arguments
 *    str - string input from user
 * Returns nothing
*/
void deleteN(char* str) {
  if (str[strlen(str) - 1] == '\n') {
    str[strlen(str) - 1] = '\0';
  }
}

/* Check if string is composed only of number
 * Arguments
 *    str - string input from user
 * Returns 0 if string isn't composed only of number
 *         1 if string is composed only of number
*/
int checkDigit(char* str) {
  for (int i = 0; i < strlen(str); i++) {
    if (isdigit(str[i]) == 0) {
      return 0;
    }
  }
  return 1;
}

/* Print the entire history
 * Arguments
 *    list - HISTORY_T that we want to print out
 * Returns nothing
*/
int historyPrint(HISTORY_T* list) {
  HISTORYNODE_T *node = list->head;
  while (node != NULL) {
    printf("- %s\n", node->history);
    node = node->next;
  }
}

/*----------------------------------------------------------*/

/* Add a new book into store
 * Arguments
 *    store - pointer to store
 * Returns nothing
*/
int addBook(STORE_T* store) {
  DATABOOK_T* dataBook = (DATABOOK_T*)calloc(1, sizeof(DATABOOK_T));
  
  //get a valid book title
  printf("Enter title: ");
  fgets(dataBook->namebook, MAX_NAME, stdin);
  deleteN(dataBook->namebook);
  while (dataBook->namebook[0] == '\0' || findIndexBook(store, dataBook->namebook) != -1) {
    printf("Invalid title\n");
    printf("Enter title: ");
    fgets(dataBook->namebook, MAX_NAME, stdin);
    deleteN(dataBook->namebook);
  }

  //get book author
  printf("Enter author: ");
  fgets(dataBook->author, MAX_NAME, stdin);
  deleteN(dataBook->author);

  //get a valid book publish year
  printf("Enter publish year: ");
  fgets(dataBook->year, MAX_NAME, stdin);
  deleteN(dataBook->year);
  while (checkDigit(dataBook->year) == 0) {
    printf("Invalid publish year\n");
    printf("Enter publish year: ");
    fgets(dataBook->year, MAX_NAME, stdin);
    deleteN(dataBook->year);
  }

  //set initial book status to Available
  strcpy(dataBook->status, "Available");

  bookCreate(store, dataBook);
  printf("Book added successfully\n");
  free(dataBook);
}

/* Remove specific books from the store
 * Arguments
 *    store - pointer to store
 * Returns 0 when obtained invalid input
*/
int removeBook(STORE_T* store) {
  char title[MAX_NAME];
  printf("Enter title to be removed: ");
  fgets(title, MAX_NAME, stdin);
  deleteN(title);

  //input a book title 
  int index = findIndexBook(store, title);
  if (index == -1) {
    printf("Invalid title\n");
    return 0;
  }

  //overwrite data with the previous book
  for (int i = index; i < store->currentSize - 1; i++) {
    store->data[i] = store->data[i + 1];
  }
  store->currentSize--;
  printf("Book removed successfully\n");
}

/* Edit the book by overwriting its current state
 * Arguments
 *    store - pointer to store
 * Returns 0 when obtained invalid input
*/
int editBook(STORE_T* store) {
  char title[MAX_NAME], tempName[MAX_NAME], tempAuthor[MAX_NAME],
      tempYear[MAX_NAME];
  //get a title to edit
  printf("Enter title to edit: ");
  fgets(title, MAX_NAME, stdin);
  deleteN(title);
  
  //get an index of the target book
  int index = findIndexBook(store, title);
  if (index == -1) {
    printf("Invalid title\n");
    return 0;
  }
  
  //get the new book title
  printf("New title (leave blank to retain old value): ");
  fgets(tempName, MAX_NAME, stdin);
  deleteN(tempName);

  //get the new author name
  printf("New author name (leave blank to retain old value): ");
  fgets(tempAuthor, MAX_NAME, stdin);
  deleteN(tempAuthor);

  //get the new publish year
  printf("New publish year (leave blank to retain old value): ");
  fgets(tempYear, MAX_NAME, stdin);
  deleteN(tempYear);
  
  //If left a field is left empty that data would the retain old value
  //set the book's title to new title
  if (strcmp(tempName, "") != 0) {
    strcpy(store->data[index].namebook, tempName);
  }
  //set the book's author to new author
  if (strcmp(tempAuthor, "") != 0) {
    strcpy(store->data[index].author, tempAuthor);
  }
  //set the book's publish year to new publish year
  if (strcmp(tempYear, "") != 0) {
    strcpy(store->data[index].year, tempYear);
  }
  printf("Book edited successfully\n");
}

/* Print out all the stored books
 * Arguments
 *    store - pointer to store
 * Returns nothing
*/
int showAllBooks(STORE_T* store) {
  for (int i = 0; i < store->currentSize; i++) {
    printBook(store, i);
  }
}

/* Search book by the inputed title or author name
 * Arguments
 *    store - pointer to store
 * Returns nothing
*/
int searchBook(STORE_T* store) {
  char title[MAX_NAME], author[MAX_NAME];
  
  //get the book title 
  printf("Enter title (leave blank to include all titles): ");
  fgets(title, MAX_NAME, stdin);
  deleteN(title);

  //get the author name
  printf("Enter author name (leave blank to include all authors): ");
  fgets(author, MAX_NAME, stdin);
  deleteN(author);
  printf("\n");

  for (int i = 0; i < store->currentSize; i++) {
    if (strcmp(title, "") == 0 && strcmp(author, "") == 0) {
      printBook(store, i);
    } else if (strcmp(title, "") == 0 &&
               strstr(store->data[i].author, author) != NULL) {
      printBook(store, i);
    } else if (strstr(store->data[i].namebook, title) != NULL &&
               strcmp(author, "") == 0) {
      printBook(store, i);
    } else if (strstr(store->data[i].namebook, title) != NULL &&
               strstr(store->data[i].author, author) != NULL) {
      printBook(store, i);
    } else {
      printf("No book found\n");
      break;
    }
  }
}

/* Borrow a book from the store and update its state
 * Arguments
 *    store - pointer to store
 * Returns nothing
*/
int borrowBook(STORE_T* store) {
  char name[MAX_NAME], title[MAX_NAME], text[MAX_NAME] = "Borrow by ";

  //get the borrower name
  printf("Enter borrower name: ");
  fgets(name, MAX_NAME, stdin);
  deleteN(name);

  //get the borrowed book title
  printf("Enter book title: ");
  fgets(title, MAX_NAME, stdin);
  deleteN(title);

  //search and get the book index
  int index = findIndexBook(store, title);
  if (index == -1) {
    printf("Book not found\n");
    return 0;
  }

  //change the status to "borrowed" and update the history
  //if the book is already borrowed, console will display "Book is not available"
  if (strcmp(store->data[index].status, "Available") == 0) {
    strcpy(store->data[index].status, "Borrowed");
    strcat(text, name);
    strcpy(store->data[index].borrowName, name);
    historyAppend(store->data[index].history, text);
  } else {
    printf("Book is not available\n");
  }
  printf("Book borrowed successfully\n");
}

/* Return the borrowed book and update its state
 * Arguments
 *    store - pointer to store
 * Returns nothing
*/
int returnBook(STORE_T* store) {
  char title[MAX_NAME], text[MAX_NAME] = "Return by ";
  
  //get the book title
  printf("Enter title to return: ");
  fgets(title, MAX_NAME, stdin);
  deleteN(title);

  //search and get the book index
  int index = findIndexBook(store, title);
  if (index == -1) {
    printf("Book not found\n");
    return 0;
  }

  //change the status to "available" and update the history
  //if the book has not been borrowed, the console will display "Book is not //Borrowed" 
  if (strcmp(store->data[index].status, "Borrowed") == 0) {
    strcpy(store->data[index].status, "Available");
    strcat(text, store->data[index].borrowName);
    strcpy(store->data[index].borrowName, "");
    historyAppend(store->data[index].history, text);
  } else {
    printf("Book is not Borrowed\n");
  }
  printf("Book returned successfully\n");
}

/*-------------------------------------------------------------------*/

/* Save all stored data in to a file
 * Arguments
 *    store - STORE_T variable that will be saved to a file
 * Returns 0 if storeData.txt couldn't be opened
*/
int saveFile(STORE_T* store) {
  HISTORYNODE_T *node = (HISTORYNODE_T *)calloc(1, sizeof(HISTORYNODE_T));
  FILE *fp = fopen("storeData.txt", "w");
  if (fp == NULL) {
    printf("Cannot open file\n");
    return 0;
  }

  for (int i = 0; i < store->currentSize; i++) {
    //write the namebook of book into storeData.txt
    fprintf(fp, "%s\n", store->data[i].namebook);
    //write the author of book into storeData.txt
    fprintf(fp, "%s\n", store->data[i].author);
    //write the year of book into storeData.txt
    fprintf(fp, "%s\n", store->data[i].year);
    //write the status of book into storeData.txt
    fprintf(fp, "%s\n", store->data[i].status);
    //write the borrowName of book into storeData.txt
    fprintf(fp, "%s\n", store->data[i].borrowName);

    //go through history node and write into storeData.txt
    node = store->data[i].history->head;
    while (node != NULL) {
      fprintf(fp, "%s\n", node->history);
      node = node->next;
    }
    //put an end signifier
    fprintf(fp, "%s", "end\n");
  }
  fclose(fp);
  printf("Save complete\n");
  free(node);
}

/* Load a stored STORE_T into a variable
 * Arguments
 *    store - STORE_T variable that is being loaded into
 * Returns 0 if storeData.txt couldn't be opened
*/
int loadFile(STORE_T* store) {
  FILE* fp = fopen("storeData.txt", "r");
  //create a temporary dataBook
  DATABOOK_T* dataBook = (DATABOOK_T *)calloc(1, sizeof(DATABOOK_T));
  char text[MAX_NAME];
  if (fp == NULL) {
    printf("Cannot open file\n");
    return 0;
  }

  int index = 0;
  //Read the data from storeData.txt
  while (fgets(text, MAX_NAME, fp) != NULL) {
    //set namebook of dataBook to the read input
    deleteN(text);
    strcpy(dataBook->namebook, text);

    //set author of dataBook to the read input
    fgets(text, MAX_NAME, fp);
    deleteN(text);
    strcpy(dataBook->author, text);

    //set year of dataBook to the read input
    fgets(text, MAX_NAME, fp);
    deleteN(text);
    strcpy(dataBook->year, text);

    //set status of dataBook to the read input
    fgets(text, MAX_NAME, fp);
    deleteN(text);
    strcpy(dataBook->status, text);

    //set borrowName of dataBook to the read input
    fgets(text, MAX_NAME, fp);
    deleteN(text);
    strcpy(dataBook->borrowName, text);

    //Creat a new dataBook with data of the temporary dataBook in store
    bookCreate(store, dataBook);

    //Read borrowing history then set into the book
    while (fgets(text, MAX_NAME, fp) != NULL) {
      deleteN(text);
      if (strcmp(text, "end") == 0) {
        break;
      }
      historyAppend(store->data[index].history, text);
    }
    index++;
  }
  fclose(fp);
  free(dataBook);
}
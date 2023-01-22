#include"book.h"
#include"menu.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>


#define MAX_NAME 50

int findIndexBook(STORE_T* store, char* namebook){
    for (int i=0; i<store->currentSize; i++){
        if (strcmp(store->data[i].namebook, namebook) == 0){
            return i;
        }
    }
    return -1;
}

void deleteN(char* str){
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
}

int checkDigit(char* str){
    for (int i=0; i<strlen(str); i++){
        if (isdigit(str[i]) == 0){
            return 0;
        }
    }
    return 1;
}

int addBook(STORE_T* store){
    DATABOOK_T* databook = (DATABOOK_T*)calloc(1, sizeof(DATABOOK_T));

    printf("Enter title: ");
    fgets(databook->namebook, MAX_NAME, stdin);
    deleteN(databook->namebook);
    while (databook->namebook[0] == '\0' || findIndexBook(store, databook->namebook) != -1){
        printf("Invalid title\n");
        printf("Enter title: ");
        fgets(databook->namebook, MAX_NAME, stdin);
        deleteN(databook->namebook);
    } 

    printf("Enter author: ");
    fgets(databook->author, MAX_NAME, stdin);
    deleteN(databook->author);
    
    printf("Enter publish year: ");
    fgets(databook->year, MAX_NAME, stdin);
    deleteN(databook->year);
    while (checkDigit(databook->year) == 0){
        printf("Invalid publish year\n");
        printf("Enter publish year: ");
        fgets(databook->year, MAX_NAME, stdin);
        deleteN(databook->year);
    }



    strcpy(databook->status, "available");

    
    bookCreate(store, databook);
    free(databook);
}



int removeBook(STORE_T* store){
    char title[MAX_NAME];
    printf("Enter title to be removed: ");
    scanf("%s", title);

    int index = findIndexBook(store, title);
    if (index == -1){
        printf("Invalid title\n");
        return 0;
    }

    for (int i=index; i<store->currentSize-1; i++){
        store->data[i] = store->data[i+1];
    }
    store->currentSize--;
}

int editBook(STORE_T* store){
    char title[MAX_NAME], tempName[MAX_NAME], tempAuthor[MAX_NAME], tempYear[MAX_NAME];
    printf("Enter title to edit: ");
    scanf("%s", title);

    int index = findIndexBook(store, title);
    if (index == -1){
        printf("Invalid title\n");
        return 0;
    }
    fgetc(stdin);

    printf("New title (leave blank to retain old value): ");
    fgets(tempName, MAX_NAME, stdin);
    deleteN(tempName);

    printf("New author name (leave blank to retain old value): ");
    fgets(tempAuthor, MAX_NAME, stdin);
    deleteN(tempAuthor);

    printf("New publish year (leave blank to retain old value): ");
    fgets(tempYear, MAX_NAME, stdin);
    deleteN(tempYear);

    if (strcmp(tempName, "") != 0){
        strcpy(store->data[index].namebook, tempName);
    }
    if (strcmp(tempAuthor, "") != 0){
        strcpy(store->data[index].author, tempAuthor);
    }
    if (strcmp(tempYear, "") != 0){
        strcpy(store->data[index].year, tempYear);
    }
}

int showAllBooks(STORE_T* store){
    for (int i=0; i<store->currentSize; i++){
        printf("Title: %s\n", store->data[i].namebook);
        printf("Author Name: %s\n", store->data[i].author);
        printf("Publish year: %s\n", store->data[i].year);
        printf("Status: %s\n", store->data[i].status);
        printf("Borrowing History: \n");
        //printhistory
        printf("\n");
    }
}

int searchBook(STORE_T* store){

}

int borrowBook(STORE_T* store){
    char name[MAX_NAME], title[MAX_NAME], text[MAX_NAME] = "Borrowed by ";
    
    printf("Enter borrower name: ");
    scanf("%s", name);
    printf("Enter book title: ");
    scanf("%s", title);

    int index = findIndexBook(store, title);
    if (index == -1){
        printf("Book not found\n");
        return 0;
    }

    if (strcmp(store->data[index].status, "available") == 0){
        strcpy(store->data[index].status, "borrowed");
        strcat(text, name);
        historyAppend(store->data[index].history, text);
    }
}

int returnBook(STORE_T* store){
    char title[MAX_NAME], text[MAX_NAME] = "Return by ";
    printf("Enter title to return: ");
    scanf("%s", title);

    int index = findIndexBook(store, title);
    if (index == -1){
        printf("Book not found\n");
        return 0;
    }

    if (strcmp(store->data[index].status, "borrowed") == 0){
        strcpy(store->data[index].status, "available");
        historyAppend(store->data[index].history, text);
    }
}
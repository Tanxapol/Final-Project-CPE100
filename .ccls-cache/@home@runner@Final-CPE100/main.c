#include<stdio.h>
#include<stdlib.h>
#include"book.h"
#include"menu.h"

int getSelectMenu(){
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
    scanf("%d",&selectMenu);
    printf("\n");
    return selectMenu;
}

int main(){
    STORE_T* store = libraryCreate(1);
    printf("Welcome to Library Management System\n");
    int selectMenu = getSelectMenu();

    while (selectMenu != 8){
        if (selectMenu == 1){
            addBook(store);
            printf("Add book\n");
        }else if (selectMenu == 2){
            printf("Remove book\n");
        }else if (selectMenu == 3){
            printf("Edit book\n");
        }else if (selectMenu == 4){
            showAllBooks(store);
            printf("Show all book\n");
        }else if (selectMenu == 5){
            printf("Search book\n");
        }else if (selectMenu == 6){
            borrowBook(store);
            printf("Borrow book\n");
        }else if (selectMenu == 7){
            printf("Return book\n");
        }
        selectMenu = getSelectMenu();
    }
    printf("Thank you");
    return 0;
}



/*
> ./main
Welcome to CPE Library Management System
Menu
1)Add book
2)Remove book
3)Edit book
4)Show all book
5)Search book
6)Borrow book
7)Return book
8)Exit
> 4

Title: Harry Potter and the Philosopher's Stone
Author Name: J. K. Rowling
Publish Year: 1997
Status: Available
Borrowing History:
- Return by Tim Jobs
- Borrow by Tim Jobs
- Return by Steve Cook
- Borrow by Steve Cook

Title: Harry Potter and the Chamber of Secrets
Author Name: J. K. Rowling
Publish Year: 1998
Status: Borrowed
Borrowing History:
- Borrow by Mary Zu

Menu
1)Add book
2)Remove book
3)Edit book
4)Show all book
5)Search book
6)Borrow book
7)Return book
8)Exit
> 1

Enter title:
Invalid title
Enter title: Harry Potter and the Chamber of Secrets
Invalid title
Enter title: Harry Potter and the Prisoner of Azkaban
Enter author name: J. K. Rowling
Enter publish year: 199a
Invalid publish year
Enter publish year: 2000

Menu
1)Add book
2)Remove book
3)Edit book
4)Show all book
5)Search book
6)Borrow book
7)Return book
8)Exit
> 2

Enter title to be removed: Harry Potter and
Invalid title

Menu
1)Add book
2)Remove book
3)Edit book
4)Show all book
5)Search book
6)Borrow book
7)Return book
8)Exit
> 2

Enter title to be removed: Harry Potter and the Philosopher's Stone

Menu
1)Add book
2)Remove book
3)Edit book
4)Show all book
5)Search book
6)Borrow book
7)Return book
8)Exit
> 7

Enter title to return: Harry Potter and the Chamber of Secrets

Menu
1)Add book
2)Remove book
3)Edit book
4)Show all book
5)Search book
6)Borrow book
7)Return book
8)Exit
> 6

Enter borrower name: Jack Gates
Enter title to borrow: Harry Potter and the Prisoner of Azkaban

Menu
1)Add book
2)Remove book
3)Edit book
4)Show all book
5)Search book
6)Borrow book
7)Return book
8)Exit
> 3

Enter title to edit: Harry Potter and the Prisoner of Azkaban
New title (leave blank to retain old value):
New author name (leave blank to retain old value):
New publish year (leave blank to retain old value): 1999

Menu
1)Add book
2)Remove book
3)Edit book
4)Show all book
5)Search book
6)Borrow book
7)Return book
8)Exit
> 4

Title: Harry Potter and the Chamber of Secrets
Author Name: J. K. Rowling
Publish Year: 1998
Status: Available
Borrowing History:
- Return by Mary Zu
- Borrow by Mary Zu

Title: Harry Potter and the Prisoner of Azkaban
Author Name: J. K. Rowling
Publish Year: 1999
Status: Borrowed
Borrowing History:
- Borrow by Jack Gates

Menu
1)Add book
2)Remove book
3)Edit book
4)Show all book
5)Search book
6)Borrow book
7)Return book
8)Exit
> 5

Enter title (leave blank to include all titles): Chamber
Enter author name (leave blank to include all author names):

Title: Harry Potter and the Chamber of Secrets
Author Name: J. K. Rowling
Publish Year: 1998
Status: Available
Borrowing History:
- Return by Mary Zu
- Borrow by Mary Zu

Menu
1)Add book
2)Remove book
3)Edit book
4)Show all book
5)Search book
6)Borrow book
7)Return book
8)Exit
> 5

Enter title (leave blank to include all titles): Chamber
Enter author name (leave blank to include all author names): A

Not Found

Menu
1)Add book
2)Remove book
3)Edit book
4)Show all book
5)Search book
6)Borrow book
7)Return book
8)Exit
> 8

Thank you
*/
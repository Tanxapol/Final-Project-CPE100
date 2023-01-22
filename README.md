**<center>FINAL PROJECT CPE100</center>**
                                      
65070501022	Thanachot	Chinvattanchot <br>
65070501024	Tanapol	Nuatho <br>
65070501026	Thanniti	Leelapattanaputichot <br>
***
**Directory/File Structure**

| file | Purpose |
| --- | --- |
| main.c | Run the user-end interaction. Getting inputs from user to modify or read something for output. |
| book.c | Locate the functions that used to manage the book, libary and borrowed histories. |
| book.h | Locate the program data structure. |
| menu.c, menu.h | locate all the functions that used to manage the defined data structure (store) |

***
**Program Data Structure**

This defined data structure is used to store groups of data that are essential to the library, which facilitates access and manipulation. It is defined and located in the `book.h` file and be utilized to construct all the functions in the `menu.h` file.

Here a list of all the defined struct

- `STORE_T`
  <br>to keep the data of each books and its size with current member count </br>
  - Content of each book
  - Current size (number of books that currently stored)
  - Maximum size (maximum number of books that can be stored)
```c
typedef struct {
  DATABOOK_T* data;
  int currentSize;
  int maxSize;
} STORE_T;
```

- `DATABOOK_T`
  <br>to keep the book data</br>
  - Book title *(100 characters)*
  - Author name *(100 characters)*
  - Publish year *(10 charactors)*
  - Available or borrowed status *(10 charactors)*
  - If borrowed, borrower name *(90 charactors)*
  - History
```c
typedef struct {
  char namebook[100];
  char author[100];
  char year[10];
  char status[10];
  char borrowName[90];
  HISTORY_T* history;
} DATABOOK_T;
```

- `HISTORY_T`
  <br>to keep the history node head</br>
```c
typedef struct {
  HISTORYNODE_T* head;
} HISTORY_T;
```

- `HISTORYNODE_T`
  <br>to keep the borrowed histories *(100 charactors)* </br>
```c
typedef struct _node {
  char history[100];
  struct _node* next;
  struct _node* prev;
} HISTORYNODE_T;
```

***
**The file type used (Text File / Binary File) and the format for storing data in the file**<br>

We use `Text Files` to store our library data. Because of their simplicity, text files are commonly used for storing information. They avoid some of the problems encountered with other file formats, such as endianness, padding bytes, or differences in the number of bytes in a machine word.

- `Format`
```
data[0]->namebook\n
data[0]->author\n
data[0]->year\n
data[0]->status\n
data[0]->borrowName\n
data[0]->history->head->history\n
data[0]->history->head->prev->history\n
data[0]->history->head->prev->prev->history\n
data[0]->history->head->prev->prev->prev->history\n
  .
  .
  .
data[0]->history->head->prev [length of history chain] ->history\n
end\n
data[1]->namebook\n
data[1]->author\n
data[1]->year\n
data[1]->status\n
data[1]->borrowName\n
data[1]->history->head->history\n
data[1]->history->head->prev->history\n
data[1]->history->head->prev->prev->history\n
data[1]->history->head->prev->prev->prev->history\n
  .
  .
  .
data[1]->history->head->prev [length of history chain] ->history\n
end\n
  .
  .
  .
data[n]->namebook\n
data[n]->author\n
data[n]->year\n
data[n]->status\n
data[n]->borrowName\n
data[n]->history->head->history\n
data[n]->history->head->prev->history\n
data[n]->history->head->prev->prev->history\n
data[n]->history->head->prev->prev->prev->history\n
  .
  .
  .
data[n]->history->head->prev [length of history chain] ->history\n
end\n
```
***

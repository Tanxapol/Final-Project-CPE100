#ifndef MENU_H
#define MENU_H

/* Add a new book into store
 * Arguments
 *    store - pointer to store
 * Returns nothing
*/
int addBook(STORE_T* store);

/* Remove specific books from the store
 * Arguments
 *    store - pointer to store
 * Returns 0 when obtained invalid input
*/
int removeBook(STORE_T* store);

/* Edit the book by overwriting its current state
 * Arguments
 *    store - pointer to store
 * Returns 0 when obtained invalid input
*/
int editBook(STORE_T* store);

/* Print out all the stored books
 * Arguments
 *    store - pointer to store
 * Returns nothing
*/
int showAllBooks(STORE_T* store);

/* Search book by the inputed title or author name
 * Arguments
 *    store - pointer to store
 * Returns nothing
*/
int searchBook(STORE_T* store);

/* Borrow a book from the store and update its state
 * Arguments
 *    store - pointer to store
 * Returns nothing
*/
int borrowBook(STORE_T* store);

/* Return the borrowed book and update its state
 * Arguments
 *    store - pointer to store
 * Returns nothing
*/
int returnBook(STORE_T* store);

/* Save all stored data in to a file
 * Arguments
 *    store - STORE_T variable that will be saved to a file
 * Returns 0 if storeData.txt couldn't be opened
*/
int saveFile(STORE_T* store);

/* Load a stored STORE_T into a variable
 * Arguments
 *    store - STORE_T variable that is being loaded into
 * Returns 0 if storeData.txt couldn't be opened
*/
int loadFile(STORE_T* store);

#endif
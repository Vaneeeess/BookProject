#ifndef Book_H
#define Book_H

typedef struct {
    char isbn[13];
    char title[50];
    char author[50];
    int yearpublished;
    int copiesavailable;
} Book;

typedef struct {
    Book book;
    char username[50];
    char dueDate[12];
    char borrowedDate[12];
    float lateFee;
} BorrowedBook;


void addBook(Book books[], int *count,Book newBook);
int searchAuthor(char author[], Book books[], int count);
int searchBook(char title[], Book books[], int count);
void displayBookByYear(Book books[], int count);
void updateBook(Book books[], int *count, Book updateBook);
void deleteBook(char title[], Book books[], int *count);
int isBookAvailable(char title[], Book books[], int count);
void borrowBooks(char title[], Book books[], int *count, char username[], BorrowedBook borrow[], int *countBorrowed);
void returnBooks(char title[], Book books[], int *count, BorrowedBook borrow[], int *countBorrowed);
#endif

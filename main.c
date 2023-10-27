#include "book.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main() {
    int choice;
    Book books[100];
    int count = 0;
    BorrowedBook borrowed[100];
    int countBorrowed = 0;
    char title[50], author[50], username[50];
    Book newBook, updateBook;
    
    //const char *tics = "\t\t\tHello and Welcome to CIT Library where you can borrow, return and read Books\n\t\t\tfor free This is made my me so enjoy in CIT library\n\t\t\tHave a Nice day!";
   	//printdisplay(tics,100000);

    do {
    	
        printf("\n\n1 - Add new book mah boi\n");
        //sleep(1);
        printf("2 - Search by Author\n");
        //sleep(1);
        printf("3 - Search by Book\n");
        //sleep(1);
        printf("4 - Display books by year\n");
        //sleep(1);
        printf("5 - Update book\n");
        //sleep(1);
        printf("6 - Delete book\n");
        //sleep(1);
        printf("7 - Available book\n");
        //sleep(1);
        printf("8 - Borrow\n");
        //sleep(1);
        printf("9 - Return\n");
        //sleep(1);
        printf("10 - Exit\n");
        //sleep(1);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter ISBN: ");
                scanf("%s", newBook.isbn);
                printf("Enter title: ");
                scanf("%s", newBook.title);
                printf("Enter author: ");
                scanf("%s", newBook.author);
                printf("Enter year published: ");
                scanf("%d", &newBook.yearpublished);
                printf("Enter copies available: ");
                scanf("%d", &newBook.copiesavailable);
                addBook(books, &count, newBook);
                break;
            case 2:
                printf("Enter author: ");
                scanf("%s", author);
                searchAuthor(author, books, count);
                break;
            case 3:
                printf("Enter title: ");
                scanf("%s", title);
                searchBook(title, books, count);
                break;
            case 4:
                displayBooksByYear(books, count);
                break;
            case 5:
                printf("Enter ISBN: ");
                scanf("%s", updateBook.isbn);
                printf("Enter title: ");
                scanf("%s", updateBook.title);
                printf("Enter author: ");
                scanf("%s", updateBook.author);
                printf("Enter year published: ");
                scanf("%d", &updateBook.yearpublished);
                printf("Enter copies available: ");
                scanf("%d", &updateBook.copiesavailable);
                updateNewBook(books, &count, updateBook);
                break;
            case 6:
                printf("Enter title: ");
                scanf("%s", title);
                deleteBook(title, books, &count);
                break;
            case 7:
                printf("Enter title: ");
                scanf("%s", title);
                isBookAvailable(title, books, count);
                break;
            case 8:
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter username: ");
                scanf("%s", username);
                borrowBooks(title, books, &count, username, borrowed, &countBorrowed);
                break;
            case 9:
                printf("Enter title: ");
                scanf("%s", title);
                returnBooks(title, books, &count, borrowed, &countBorrowed);
                break;
            case 10:
                printf("Exit the program.");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 10);

    return 0;
}

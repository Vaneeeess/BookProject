#include <stdio.h>
#include <string.h>
#include "book.h"
#include <unistd.h>


void display(unsigned int wew) {
	
	usleep(wew);
}

void printdisplay(const char *tics, unsigned int facs) {
	
	int length = strlen(tics);
	for(int i = 0; i < length; i++) {
		printf("%c", tics[i]);
		fflush(stdout);
		display(facs);
	}
}
void addBook(Book books[], int *count, Book newBook) {
	
	for(int i = 0; i < *count; i++) {
		if(strcmp(books[i].isbn, newBook.isbn) == 0) {
			printf("\nThe isbn must be unique boy.");
			return;
		}
	}
	
	books[*count] = newBook;
	(*count)++;
	printf("\nThe book is succesfully added....\n");
}

int searchAuthor(char author[], Book books[], int count) {
	
	int found = 0;
	for(int i = 0; i < count; i++) {
		if(strcmp(books[i].author, author) == 0) {
			printf("Copies Available: %d\n", books[i].copiesavailable);
			printf("Title of the Book: %s\n", books[i].title);
			printf("Year published: %d\n", books[i].yearpublished);
			printf("Name of the Author: %s\n", books[i].author);
			found = 1;
		}
	}
	
	if(!found) {
		printf("\nThere is no name %s\n", author);
	}
	
	return found;
}

int searchBook(char title[], Book books[], int count) {
	for(int i = 0; i < count; i++) {
		if(strcmp(books[i].title, title) == 0) {
			printf("\nThe book is found!\n");
			return i;
		}
	}
	//printf("\nThere is no Book by this title %s\n", title);
	return -1;
}

void displayBooksByYear(Book books[], int count) {
    int minYearIndex;
    for(int i = 0; i < count; i++) {
        minYearIndex = i;// start with i 
        for(int j = i+1; j < count; j++) {
            if(books[j].yearpublished < books[minYearIndex].yearpublished) { // we iterate if we found smaller than minyear then we update
                minYearIndex = j;
            }
        }
        printf("Book Year Published: %d\n", books[minYearIndex].yearpublished);
        printf("Book Title: %s\n", books[minYearIndex].title);
        Book temp = books[i];// then we swap the book i with book i minyear.
        books[i] = books[minYearIndex];
        books[minYearIndex] = temp;
    }
}

void updateNewBook(Book books[], int *count, Book updateBook) {
	
	int wew = searchBook(updateBook.title, books, *count);
	if(wew == -1) {
		printf("%s is not exisitng. Do you want to add this book? (Y/N): ", updateBook.title);
		char choice;
		scanf(" %c", &choice);
		if(choice == 'y' || choice == 'Y') {
			addBook(books, count, updateBook);
		}
	} else {
		books[wew] = updateBook;
		printf("The book has been upadated succesfully\n");
	}
}

void deleteBook(char title[], Book books[], int *count) {
	
	int ticks = searchBook(title, books, *count);
	if(ticks == -1) {
		printf("Title not existing.\n");
	} else {
		for(int i = ticks; i < *count; i++) {
			books[i] = books[i + 1];
		}
		(*count)++;
		printf("The book has been deleted.\n");
	}
}

int isBookAvailable(char title[],Book books[], int count) {
	
	int lol = searchBook(title, books, count);
	if(lol == -1 || books[lol].copiesavailable == 0) {
		printf("\nThis book is not available for borrowing sorry.\n");
		return 0;
	} else {
		printf("\nThis book is good for borrowing.\n");
		return 1;
	}
}


void borrowBooks(char title[], Book books[], int *count, char username[], BorrowedBook borrow[], int *countBorrowed) {
	
	
	int lol = searchBook(title, books, *count);
	if(lol == -1 || books[lol].copiesavailable <= 0) {
		printf("Book not available sorry..");
	} else {
		BorrowedBook newBorrow;
		newBorrow.book = books[lol];
		strcpy(newBorrow.username, username);
		printf("Enter due date: ");
		scanf("%s", newBorrow.dueDate);
		printf("Enter borrowed date: ");
		scanf("%s", newBorrow.borrowedDate);
		newBorrow.lateFee = 0;
		
		borrow[*countBorrowed] = newBorrow;
		(*countBorrowed)++;
		
		books[lol].copiesavailable--;
		printf("The book %s has been successfully borrowed.\n", title);
	}	
}

void returnBooks(char title[], Book books[], int *count, BorrowedBook borrow[], int *countBorrowed) {
	
	int lol = -1;
	for(int i = 0; i < *countBorrowed; i++) {
		if(strcmp(borrow[i].book.title, title) == 0) {
			lol = i;
			break;
		}
	}
	
	if(lol == -1) { 
		printf("Book not borrowed\n");	
	} else {
		for(int i = lol; i < *countBorrowed - 1; i++) {
			borrow[i] = borrow[i + 1];
		}
		(*countBorrowed)--;
		int wew = searchBook(title, books, *count);
		
		books[wew].copiesavailable++;
		printf("The book has been successfully return\n");
	}
}

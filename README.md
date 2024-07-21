# Library-Management-System
The Library Management System (LMS) is a C++ project designed to manage a library's inventory of books. It provides functionalities to add, search, issue, return, and delete books. This project demonstrates the use of object-oriented programming, linked lists, and basic file I/O operations in C++.
Features
Add Book: Add new books to the library with unique IDs, titles, and authors.
Search Book: Search for books by ID or title.
Issue Book: Issue a book to a student, changing its status to issued.
Return Book: Return a book, changing its status to available.
Delete Book: Remove a book from the library.
List All Books: Display details of all books in the library.
Implementation Details
Data Structure
The library uses a singly linked list to store book records. Each book is represented as a BookNode struct, which contains:

id: Unique identifier for the book.
title: Title of the book.
author: Author of the book.
isIssued: Boolean flag indicating if the book is issued.
issuedTo: Name of the student to whom the book is issued.
next: Pointer to the next book node in the list.
Class Structure
LibraryManagementSystem Class
This class encapsulates all functionalities of the library system, including methods for adding, searching, issuing, returning, and deleting books.

Private Member:

BookNode* head: Pointer to the first book in the linked list.
Public Methods:

LibraryManagementSystem(): Constructor initializing the library with a few books.
int addBook(int id, string title, string author): Adds a new book to the library.
void searchBookByID(int id): Searches for a book by its ID.
void searchBookByTitle(const string& title): Searches for a book by its title.
void displayBookDetails(BookNode* book): Displays the details of a book.
int issueBook(int id, string student): Issues a book to a student.
int returnBook(int id): Returns a book to the library.
int deleteBook(int id): Deletes a book from the library.
void listAllBooks(): Lists all books in the library.
bool isPresent(string s, int id = -1): Checks if a book is already present in the library.
Utility Function
void printLine(): Prints a formatted line for output.

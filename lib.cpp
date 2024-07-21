#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void printLine();

struct BookNode {
    int id;
    string title;
    string author;
    bool isIssued;
    string issuedTo;
    BookNode* next;
};

class LibraryManagementSystem {
private:
    BookNode* head;

public:
    LibraryManagementSystem() : head(nullptr) {
        // Adding some book records initially
        string books[] = {"Anna Karenina", "Madame Bovary", "War and Peace", "The Great Gatsby", "Lolita"};
        string authors[] = {"Leo Tolstoy", "Gustave Flaubert", "Leo Tolstoy", "F. Scott Fitzgerald", "Vladimir Nabokov"};
        
        for (int i = 0; i < 5; i++) {
            addBook(i + 1, books[i], authors[i]);
        }
    }

    // Method to add Book record
    int addBook(int id, string title, string author) {
        if (isPresent(title, id)) {
            return 0;
        }
        
        BookNode* newBook = new BookNode;
        newBook->id = id;
        newBook->title = title;
        newBook->author = author;
        newBook->isIssued = false;
        newBook->issuedTo = "";
        newBook->next = nullptr;

        if (head == nullptr) {
            head = newBook;
        } else {
            BookNode* ptr = head;
            while (ptr->next != nullptr) {
                ptr = ptr->next;
            }
            ptr->next = newBook;
        }

        return 1;
    }

    // Method to search a book by id
    void searchBookByID(int id) {
        BookNode* ptr = head;
        while (ptr != nullptr) {
            if (ptr->id == id) {
                displayBookDetails(ptr);
                return;
            }
            ptr = ptr->next;
        }
        cout << "Book not found!" << endl;
    }

    // Method to search a book by title
    void searchBookByTitle(const string& title) {
        BookNode* ptr = head;
        while (ptr != nullptr) {
            if (ptr->title == title) {
                displayBookDetails(ptr);
                return;
            }
            ptr = ptr->next;
        }
        cout << "Book not found!" << endl;
    }

    // Method to display the details of a book at a node
    void displayBookDetails(BookNode* book) {
        cout << endl;
        printLine();
        cout << left << setw(10) << "ID" << setw(25) << "TITLE" << setw(25) << "AUTHOR" << setw(15) << "STATUS" << "ISSUED TO" << endl;
        printLine();
        cout << left << setw(10) << book->id << setw(25) << book->title << setw(25) << book->author << setw(15) << (book->isIssued ? "Issued" : "Available") << (book->isIssued ? book->issuedTo : "-") << endl;
        printLine();
    }

    // Method to issue any book
    int issueBook(int id, string student) {
        BookNode* ptr = head;
        while (ptr != nullptr) {
            if (ptr->id == id) {
                if (ptr->isIssued) {
                    return -1;
                } else {
                    ptr->isIssued = true;
                    ptr->issuedTo = student;
                    return 1;
                }
            }
            ptr = ptr->next;
        }
        return 0;
    }

    // Method to return any book
    int returnBook(int id) {
        BookNode* ptr = head;
        while (ptr != nullptr) {
            if (ptr->id == id) {
                if (!ptr->isIssued) {
                    return -1;
                } else {
                    ptr->isIssued = false;
                    ptr->issuedTo = "";
                    return 1;
                }
            }
            ptr = ptr->next;
        }
        return 0;
    }

    // Method to delete a book record
    int deleteBook(int id) {
        if (head == nullptr) {
            return 0;
        }
        if (head->id == id) {
            BookNode* temp = head;
            head = head->next;
            delete temp;
            return 1;
        }
        BookNode* pre = nullptr;
        BookNode* ptr = head;
        while (ptr != nullptr && ptr->id != id) {
            pre = ptr;
            ptr = ptr->next;
        }
        if (ptr == nullptr) {
            return 0;
        } else {
            pre->next = ptr->next;
            delete ptr;
            return 1;
        }
    }

    // Method to list all books details
    void listAllBooks() {
        BookNode* ptr = head;
        cout << endl;
        printLine();
        cout << left << setw(10) << "ID" << setw(25) << "TITLE" << setw(25) << "AUTHOR" << setw(15) << "STATUS" << "ISSUED TO" << endl;
        printLine();
        while (ptr != nullptr) {
            cout << left << setw(10) << ptr->id << setw(25) << ptr->title << setw(25) << ptr->author << setw(15) << (ptr->isIssued ? "Issued" : "Available") << (ptr->isIssued ? ptr->issuedTo : "-") << endl;
            printLine();
            ptr = ptr->next;
        }
        cout << endl;
    }

    // Method to check whether a book detail is present or not
    bool isPresent(string s, int id = -1) {
        BookNode* ptr = head;
        while (ptr != nullptr) {
            if (ptr->title == s || ptr->id == id) {
                return true;
            }
            ptr = ptr->next;
        }
        return false;
    }
};

// Function to print a line for output formatting
void printLine() {
    for (int i = 0; i < 90; i++) cout << "-";
    cout << endl;
}

int main() {
    LibraryManagementSystem library;

    printLine();
    cout << "Library Management System" << endl;
    printLine();

    bool flag = true;
    while (flag) {
        cout << endl << "Choose one of the operations mentioned below:" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Search Book" << endl;
        cout << "3. Issue a Book" << endl;
        cout << "4. Return a Book" << endl;
        cout << "5. Delete a Book" << endl;
        cout << "6. List all Books" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;

        string title, author, studentName;
        int id, i;

        switch (choice) {
        case 1:
            cout << "Id of Book: "; 
            cin >> id;
            cout << "Name of Book: ";
            cin.ignore();
            getline(cin, title);
            cout << "Author of Book: ";
            getline(cin, author);
            i = library.addBook(id, title, author);
            if (i == 0) {
                cout << "Book is already present (Same ID or Title)" << endl;
            } else {
                cout << "Book added successfully" << endl;
            }
            break;

        case 2:
            int c;
            cout << "Enter 1 for Search by ID or 2 for Search by Title: ";
            cin >> c;
            if (c == 1) {
                cout << "Enter the ID: ";
                cin >> id;
                library.searchBookByID(id);
            } else {
                cout << "Enter the Title: "; 
                cin.ignore();
                getline(cin, title);
                library.searchBookByTitle(title);
            }
            break;

        case 3:
            cout << "Enter the ID of Book: ";
            cin >> id;
            cout << "Enter the name of Student: ";
            cin.ignore();
            getline(cin, studentName);
            i = library.issueBook(id, studentName);
            if (i == 0) {
                cout << "Book not found!" << endl;
            } else if (i == -1) {
                cout << "Book is already issued!" << endl;
            } else {
                cout << "Book issued!" << endl;
            }
            break;

        case 4:
            cout << "Enter the ID of the Book: "; 
            cin >> id; 
            i = library.returnBook(id); 
            if (i == 0) {
                cout << "Book not found!" << endl;
            } else if (i == -1) {
                cout << "Book is not issued!" << endl;
            } else {
                cout << "Book returned!" << endl;
            }
            break;

        case 5:
            cout << "Enter the ID of the Book: "; 
            cin >> id; 
            i = library.deleteBook(id); 
            if (i == 0) {
                cout << "Book not found!" << endl;
            } else {
                cout << "Book deleted successfully!" << endl;
            }
            break;

        case 6:
            library.listAllBooks();
            break;

        case 7:
            cout << "Thank you for using LMS" << endl;
            flag = false;
            break;

        default:
            cout << "Wrong Choice!!" << endl;
        }
    }

    return 0;
}
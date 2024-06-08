#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Book
{
    int ISBN;
    string title;
    string author;
    string publisher;
};

class Books
{
public:
    static int count;

    void addBook()
    {
        count++;

        Book book;
        book.ISBN = count;

        cout << "\tEnter title: ";
        cin >> book.title;

        cout << "\tEnter author: ";
        cin >> book.author;

        cout << "\tEnter publisher: ";
        cin >> book.publisher;

        ofstream file;
        file.open("./books/all-books-list.txt", ios::app);

        file << book.ISBN << " " << book.title << " " << book.author << " " << book.publisher << endl;
        file.close();
    }

    void deleteBook()
    {
        // TODO: if file gets opened but has no data at all
        ifstream inFile;
        ofstream outFile;

        inFile.open("./books/all-books-list.txt");
        outFile.open("./books/temp.txt");

        // if system fails to open the original file
        if (!inFile)
        {
            cout << "\nNo books exit to delete." << endl;
            return;
        }

        if (!outFile)
        {
            cout << "\nSystem is getting internal error in deleting book. Try again later." << endl;
            return;
        }

        int ISBN;
        cout << "\tEnter ISBN of the book to delete: ";
        cin >> ISBN;

        // if ISBN is below 1000
        while (ISBN <= 1000)
        {
            cout << "\n\tWrong ISBN. Enter again: ";
            cin >> ISBN;
        }

        Book book;

        while (inFile >> book.ISBN >> book.title >> book.author >> book.publisher)
        {
            if (book.ISBN != ISBN)
                outFile << book.ISBN << " " << book.title << " " << book.author << " " << book.publisher << endl;
        }

        inFile.close();
        outFile.close();

        remove("./books/all-books-list.txt");
        rename("./books/temp.txt", "./books/all-books-list.txt");

        cout << "\nBook with ISBN - " << ISBN << " deleted successfully!!" << endl;
    }

    void deleteAllBooks()
    {
        ifstream file("./books/all-books-list.txt");

        // TODO: if file exists but has no data
        if (!file)
        {
            cout << "\nNo books exist in the system." << endl;
            return;
        }

        file.close();
        remove("./books/all-books-list.txt");

        cout << "\nAll books deleted successfully!!" << endl;
    }

    void displayAllBooks()
    {
        ifstream file;
        file.open("./books/all-books-list.txt");

        Book book;

        cout << "\nAll Books: " << endl;
        cout << "\n\tISBN\t\tTitle\t\tAuthor\t\tPublisher" << endl;

        while (file >> book.ISBN >> book.title >> book.author >> book.publisher)
        {
            cout << "\t" << book.ISBN << "\t\t" << book.title << "\t\t" << book.author << "\t\t" << book.publisher << endl;
        }

        file.close();
    }
};

int Books::count = 1000;

int main()
{
    cout << "\n** Welcome to the Library Management System **" << endl;

    Books books;
    int choice;

    // TODO: if user select multiple, and want to enter 1 books
    do
    {
        cout << "\nMenu: " << endl
             << "\t1.\tAdd a Student" << endl
             << "\t2.\tRemove a Student" << endl
             << "\t3.\tDisplay all Students" << endl
             << "\t4.\tAdd a book" << endl
             << "\t5.\tDelete a book" << endl
             << "\t6.\tDelete all books" << endl
             << "\t7.\tDisplay all books" << endl
             << "\t8.\tAllot a Book" << endl
             << "\t9.\tReturn a Book" << endl
             << "\t10.\tCheck alloted books to a student" << endl
             << "\t99.\tExit" << endl
             << "\nEnter your choice: ";

        cin >> choice;

        switch (choice)
        {
        case 4:
            books.addBook();
            break;
        case 5:
            books.deleteBook();
            break;
        case 6:
            books.deleteAllBooks();
            break;
        case 7:
            books.displayAllBooks();
            break;
        case 99:
            cout << "\n** Thanks for using the Library Management System **" << endl;
            break;
        default:
            cout << "Invalid choice , Enter again ";
        }

    } while (choice != 99);

    cout << endl;
    return 0;
}
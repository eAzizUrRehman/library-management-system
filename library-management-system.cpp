#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Student
{
    int ARID_No;
    string name;
    string fatherName;
    string contactNo;
};

class Students
{
public:
    static int count;

    void addStudent()
    {
        // TODO: if folder exists, it create file but if folder doesn't exist, it can't create file
        count++;

        Student student;
        student.ARID_No = count;

        cout << "\tEnter name: ";
        cin >> student.name;

        cout << "\tEnter father name: ";
        cin >> student.fatherName;

        cout << "\tEnter contact number: ";
        cin >> student.contactNo;

        ofstream file;
        file.open("./database/students/all-students-list.txt", ios::app);

        file << student.ARID_No << " " << student.name << " " << student.fatherName << " " << student.contactNo << endl;
        file.close();
    }

    void deleteStudent()
    {
        // TODO: if file gets opened but has no data at all
        ifstream inFile;
        ofstream outFile;

        inFile.open("./database/students/all-students-list.txt");
        outFile.open("./database/students/temp.txt");

        // if system fails to open the original file
        if (!inFile)
        {
            cout << "\nNo students exit to delete." << endl;
            return;
        }

        if (!outFile)
        {
            cout << "\nInternal system error while deleting student. Try again later." << endl;
            return;
        }

        int ARID_No;
        cout << "\tEnter ARID No of the student to delete: ";
        cin >> ARID_No;

        // if ARID_No is below 1000
        while (ARID_No <= 1000)
        {
            cout << "\n\tWrong ARID No.\nEnter again: ";
            cin >> ARID_No;
        }

        Student student;

        while (inFile >> student.ARID_No >> student.name >> student.fatherName >> student.contactNo)
        {
            if (student.ARID_No != ARID_No)
                outFile << student.ARID_No << " " << student.name << " " << student.fatherName << " " << student.contactNo << endl;
        }

        inFile.close();
        outFile.close();

        remove("./database/students/all-students-list.txt");
        rename("./database/students/temp.txt", "./database/students/all-students-list.txt");

        cout << "\nStudent with ARID No - " << ARID_No << " deleted successfully!!" << endl;
    }

    void deleteAllStudents()
    {
        ifstream file("./database/students/all-students-list.txt");

        // TODO: if file exists but has no data
        if (!file)
        {
            cout << "\nNo students exist in the system." << endl;
            return;
        }

        file.close();
        remove("./database/students/all-students-list.txt");

        cout << "\nAll students deleted successfully!!" << endl;
    }

    void displayAllStudents()
    {
        ifstream file;
        file.open("./database/students/all-students-list.txt");

        if (!file)
        {
            cout << "\nNo students exist in the system." << endl;
            return;
        }

        Student student;

        cout << "\nAll students: " << endl;
        cout << "\n\tARID No\t\tName\t\tFather Name\t\tContact No" << endl;

        while (file >> student.ARID_No >> student.name >> student.fatherName >> student.contactNo)
        {
            cout << "\t" << student.ARID_No << "\t\t" << student.name << "\t\t" << student.fatherName << "\t\t\t" << student.contactNo << endl;
        }

        file.close();
    }
};

int Students::count = 9000;

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
        file.open("./database/books/all-books-list.txt", ios::app);

        file << book.ISBN << " " << book.title << " " << book.author << " " << book.publisher << endl;
        file.close();
    }

    void deleteBook()
    {
        // TODO: if file gets opened but has no data at all
        ifstream inFile;
        ofstream outFile;

        inFile.open("./database/books/all-books-list.txt");
        outFile.open("./database/books/temp.txt");

        // if system fails to open the original file
        if (!inFile)
        {
            cout << "\nNo books exit to delete." << endl;
            return;
        }

        if (!outFile)
        {
            cout << "\nInternal system error while deleting book. Try again later." << endl;
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

        remove("./database/books/all-books-list.txt");
        rename("./database/books/temp.txt", "./database/books/all-books-list.txt");

        cout << "\nBook with ISBN - " << ISBN << " deleted successfully!!" << endl;
    }

    void deleteAllBooks()
    {
        ifstream file("./database/books/all-books-list.txt");

        // TODO: if file exists but has no data
        if (!file)
        {
            cout << "\nNo books exist in the system." << endl;
            return;
        }

        file.close();
        remove("./database/books/all-books-list.txt");

        cout << "\nAll books deleted successfully!!" << endl;
    }

    void displayAllBooks()
    {
        ifstream file;
        file.open("./database/books/all-books-list.txt");

        if (!file)
        {
            cout << "\nNo books exist in the system." << endl;
            return;
        }

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

class Library
{
public:
    void allotBook()
    {
        // opening all the files
        ifstream studentsFile("./database/students/all-students-list.txt");
        ifstream booksFile("./database/books/all-books-list.txt");
        ifstream libraryFile("./database/library/all-library-list.txt");

        if (!studentsFile || !libraryFile || !booksFile)
        {
            cout << "Internal system error while allotting the book to student. Try again later." << endl;
            return;
        }

        int ARID_No;
        cout << "\tEnter student ARID No: ";
        cin >> ARID_No;

        // check if the student exists in students file
        Student student;
        bool studentExists = false;

        while (studentsFile >> student.ARID_No >> student.name >> student.fatherName >> student.contactNo)
        {
            if (student.ARID_No == ARID_No)
            {
                studentExists = true;
                break;
            }
        }

        studentsFile.close();

        if (!studentExists)
        {
            cout << "No Student exist with the provided ARID No." << endl;
            return;
        }

        // check if the already 3 books are alloted
        int allottedARID, allottedISBN, bookCount = 0;

        while (libraryFile >> allottedARID >> allottedISBN)
        {
            if (allottedARID == ARID_No)
            {
                bookCount++;
            }
        }

        libraryFile.close();

        if (bookCount >= 3)
        {
            cout << "Student has already been allotted 3 books." << endl;
            return;
        }

        // check if the book exists in books file
        int ISBN;
        cout << "\tEnter book ISBN: ";
        cin >> ISBN;

        Book book;
        bool bookExists = false;

        while (booksFile >> book.ISBN >> book.title >> book.author >> book.publisher)
        {
            if (book.ISBN == ISBN)
            {
                bookExists = true;
                break;
            }
        }

        booksFile.close();

        if (!bookExists)
        {
            cout << "No book exist with the provided ISBN." << endl;
            return;
        }

        // check if the requested book is already alloted

        libraryFile.open("./database/library/all-library-list.txt");

        bool isBookAlreadyAlloted = false;

        while (libraryFile >> allottedARID >> allottedISBN)
        {
            if (allottedARID == ARID_No && allottedISBN == ISBN)
            {
                isBookAlreadyAlloted = true;
                break;
            }
        }

        libraryFile.close();

        if (isBookAlreadyAlloted)
        {
            cout << "The requested book is already alloted. Can't allot a book twice to a student" << endl;
            return;
        }

        // save the newly alloted book record in the file
        ofstream file;
        file.open("./database/library/all-library-list.txt", ios::app);

        if (!file)
        {
            cout << "Internal system error while allotting the book to student. Try again later." << endl;
            return;
        }

        file << ARID_No << " " << ISBN << endl;

        file.close();

        cout << "\nBook alloted to the student successfully." << endl;
    }

    void returnBook()
    {
        ifstream libraryFile("./database/library/all-library-list.txt");

        if (!libraryFile)
        {
            cout << "Internal system error while returning the book. Try again later." << endl;
            return;
        }

        int ARID_No;
        cout << "\tEnter student ARID No: ";
        cin >> ARID_No;

        int ISBN;
        cout << "\tEnter book ISBN: ";
        cin >> ISBN;

        ofstream tempFile("./database/library/temp.txt");

        if (!tempFile)
        {
            cout << "Internal system error while returning the book. Try again later." << endl;
            return;
        }

        int allottedARID, allottedISBN;
        bool recordFound = false;

        while (libraryFile >> allottedARID >> allottedISBN)
        {
            if (allottedARID == ARID_No && allottedISBN == ISBN)
            {
                recordFound = true;
            }
            else
            {
                tempFile << allottedARID << " " << allottedISBN << endl;
            }
        }

        libraryFile.close();
        tempFile.close();

        if (!recordFound)
        {
            cout << "No record found for the provided ARID No and ISBN." << endl;
            remove("./database/library/temp.txt");
            return;
        }

        remove("./database/library/all-library-list.txt");
        rename("./database/library/temp.txt", "./database/library/all-library-list.txt");

        cout << "\nBook returned successfully." << endl;
    }
};

int main()
{
    cout << "\n***** Welcome to the Library Management System *****" << endl;

    Students students;
    Books books;
    Library library;

    int choice;

    do
    {
        cout << "\nMenu: " << endl
             << "\t1.\tAdd a Student" << endl
             << "\t2.\tDelete a Student" << endl
             << "\t3.\tDelete all Students" << endl
             << "\t4.\tDisplay all Students" << endl
             << "\t5.\tAdd a book" << endl
             << "\t6.\tDelete a book" << endl
             << "\t7.\tDelete all books" << endl
             << "\t8.\tDisplay all books" << endl
             << "\t9.\tAllot a Book" << endl
             << "\t10.\tReturn a Book" << endl
             << "\t99.\tExit" << endl
             << "\nEnter your choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            students.addStudent();
            break;
        case 2:
            students.deleteStudent();
            break;
        case 3:
            students.deleteAllStudents();
            break;
        case 4:
            students.displayAllStudents();
            break;
        case 5:
            books.addBook();
            break;
        case 6:
            books.deleteBook();
            break;
        case 7:
            books.deleteAllBooks();
            break;
        case 8:
            books.displayAllBooks();
            break;
        case 9:
            library.allotBook();
            break;
        case 10:
            library.returnBook();
            break;
        case 99:
            cout << "\n***** Thanks for using the Library Management System *****" << endl;
            break;
        default:
            cout << "Invalid choice , Enter again ";
        }

    } while (choice != 99);

    cout << endl;
    return 0;
}
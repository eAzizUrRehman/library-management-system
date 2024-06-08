#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Books
{

    int ISBN = 1000;
    string title;
    string author;
    string publisher;

public:
    void addBook()
    {
        // cout << "\n\tEnter ISBN : ";
        // cin.ignore();
        // cin >> ISBN;

        ISBN++;

        cout << "\tEnter title: ";
        cin.ignore();
        cin >> title;

        cout << "\tEnter Author: ";
        cin.ignore();
        cin >> author;

        cout << "\tEnter Publisher: ";
        cin.ignore();
        cin >> publisher;

        // TODO: check if data is properly inserted into File
        // save to file
        ofstream open("book.txt", ios::out | ios::binary | ios::app);
        open.write((char *)(this), sizeof(Books));
        open.close();
    }

    void load_from_file()
    {
    }

    void remove_data_from_file()
    {
    }
    void display()
    {
        // Loading data
        ifstream fs;
        fs.open("book1.txt", ios::in | ios::binary);

        if (!fs)
        {
            cerr << "Error opening file for reading" << endl;
            return;
        }

        fs.read((char *)this, sizeof(Books));
        fs.close();

        // Printing on screen
        cout << "\tISBN: " << ISBN << endl
             << "\tTitle: " << title << endl
             << "\tAUTHOE: " << author << endl
             << "\tPUBLISHER: " << publisher << endl;
    }
};

int main()
{
    cout << "\n** Welcome to the Library Management System **" << endl;

    Books list;
    int choice;

    // TODO: if user select multiple, and want to enter 1 books
    do
    {
        cout << "\nMenu: " << endl
             << "\t1.\tAdd a single book" << endl
             << "\t2.\tAdd multiple books" << endl
             << "\t3.\tDisplay all books" << endl
             << "\t99.\tExit" << endl
             << "\nEnter your choice: ";

        cin >> choice;

        switch (choice)
        {
        1 case 1:
            list.addBook();
            break;
        case 2:
            list.display();
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
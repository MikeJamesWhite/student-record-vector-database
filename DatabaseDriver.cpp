#include <iostream>
#include <vector>
#include <cstdlib>
#include "DatabaseLib.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;

void printMenu() {
    printf("\n0: Add Student\n");
    printf("1: Read Database\n");
    printf("2: Save Database\n");
    printf("3: Display Student Data\n");
    printf("4: Grade a Student\n");
    printf("x: Exit\n");
}

void clear() {
    system("clear");
}

int main( int argc, char * argv[] ) {
    bool running = true;
    vector<WHTMIC023::StudentRecord> database;
    while(running) {
        printMenu();
        char in;
        cin >> in;
        clear();
        if (in == '0') { // add student
            string name;
            string surname;
            string studentNum;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter surname: ";
            cin >> surname;
            cout << "Enter student number: ";
            cin >> studentNum;
            WHTMIC023::addStudent(database, name, surname, studentNum);
        }
        else if (in == '1') { // read exisiting database from file
            printf("Call readDatabase()");
        }
        else if (in == '2') { // save the current database to file
            printf("Call saveDatabase()");
        }
        else if (in == '3') { // query the database for information regarding an existing student
            printf("Call queryStudent()");
        }
        else if (in == '4') { // add a grade to an existing student record
            printf("Call gradeStudent()");
        }
        else if (in == 'x') { // exit
            running = false;
        }
        else {
            printf("Unrecognized command. Try again.");
        }
        printf("\n");
    }
}
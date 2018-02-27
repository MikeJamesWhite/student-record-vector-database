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
    while(running) {
        printMenu();
        char in;
        cin >> in;
        clear();
        if (in == '0') { // add student
            string name;
            string surname;
            string studentNum;
            string classRecord = "";
            string grade;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter surname: ";
            cin >> surname;
            cout << "Enter student number: ";
            cin >> studentNum;
            while (true) { // loop until break
                cout << "Enter grade (or -1 to end grading): ";
                cin >> grade;
                if (grade == "-1")
                    break;
                else
                    classRecord += grade + " ";
            }
            WHTMIC023::addStudent(name, surname, studentNum, classRecord);
        }
        else if (in == '1') { // read exisiting database from file
            string filepath;
            cout << "Enter file path: ";
            cin >> filepath;
            WHTMIC023::readDatabase(filepath.c_str());
        }
        else if (in == '2') { // save the current database to file
            string filepath;
            cout << "Enter file path: ";
            cin >> filepath;
            WHTMIC023::saveDatabase(filepath.c_str());
        }
        else if (in == '3') { // query the database for information regarding an existing student
            string studentNum;
            cout << "Enter student number: ";
            cin >> studentNum;
            WHTMIC023::queryStudent(studentNum);
        }
        else if (in == '4') { // add a grade to an existing student record
            string grade;
            string studentNum;
            cout << "Enter student number: ";
            cin >> studentNum;
            WHTMIC023::gradeStudent(studentNum);
        }
        else if (in == 'x') { // exit
            running = false;
        }
        else {
            printf("Unrecognized command. Try again.");
        }
    }
}
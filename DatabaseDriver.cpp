#include <iostream>
using namespace std;

int printMenu() {
    printf("\n0: Add Student\n");
    printf("1: Read Database\n");
    printf("2: Save Database\n");
    printf("3: Display Student Data\n");
    printf("4: Grade a Student\n");
    printf("x: Exit\n");
}

int main( int argc, char * argv[] ) {
    bool running = true;
    while(running) {
        printMenu();
        char in;
        cin >> in;
        if (in == '0') {
            printf("Request student details and call addStudent()");
        }
        else if (in == '1') {
            printf("Call readDatabase()");
        }
        else if (in == '2') {
            printf("Call saveDatabase()");
        }
        else if (in == '3') {
            printf("Call queryStudent()");
        }
        else if (in == '4') {
            printf("Call gradeStudent()");
        }
        else if (in == 'x') {
            running = false;
        }
        else {
            printf("Unrecognized command. Try again.");
        }
        printf("\n");
    }
}
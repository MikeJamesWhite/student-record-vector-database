#include <vector>
#include <string>
#include "DatabaseLib.h"

using std::string;
using std::vector;
using WHTMIC023::StudentRecord;
 
void WHTMIC023::addStudent( vector<StudentRecord> database, string name, string surname, string studentNum ) {
    StudentRecord record = {name, surname, studentNum, ""};
    database.push_back(record);
}

void WHTMIC023::saveDatabase( string filepath ) {

}

vector<WHTMIC023::StudentRecord> WHTMIC023::readDatabase( string filepath ) {

}

void WHTMIC023::queryStudent( vector<StudentRecord> database, string studentNum ) {
    for (int i = 0; i < database.size(); i++) {
        if (database[i].studentNum == studentNum) {
            printf("Found Match!\nName: %s\nSurname: %s\nGrades: %s\n", database[i].name, database[i].surname, database[i].classRecord);
            return;
        }
    }
}

void WHTMIC023::gradeStudent( vector<StudentRecord> database, string studentNum, string grade ) {
    for (int i = 0; i < database.size(); i++) {
        if (database[i].studentNum == studentNum) {
            database[i].classRecord += (" " + grade);
            return;
        }
    }  
}
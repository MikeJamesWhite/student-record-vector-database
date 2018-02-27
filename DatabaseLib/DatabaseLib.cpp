#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "DatabaseLib.h"

using std::string;
using std::vector;
using WHTMIC023::StudentRecord;
 
void WHTMIC023::addStudent( vector<StudentRecord>& database, string name, string surname, string studentNum ) {
    StudentRecord record = {name, surname, studentNum, ""};
    database.push_back(record);
    std::cout << "Added student record to database.\n";
}

void WHTMIC023::saveDatabase( vector<StudentRecord>& database, const char* filepath ) {
    std::ofstream outFile;
    outFile.open(filepath);
    for (int i = 0; i < database.size(); i++) {
        string current = database[i].name + " " + database[i].surname + " " + database[i].studentNum + " " + database[i].classRecord;
        outFile << current << std::endl;
    }
    outFile.close();
    std::cout << "Saved database to file.";
}

vector<StudentRecord>& WHTMIC023::readDatabase( const char* filepath ) {
    vector<StudentRecord> database;
    std::ifstream inFile;
    inFile.open(filepath);
    
    inFile.close();
    return database;
}

void WHTMIC023::queryStudent( vector<StudentRecord>& database, string studentNum ) {
    std::cout << database.size() +"\n";
    for (int i = 0; i < database.size(); i++) {
        if (database[i].studentNum == studentNum) {
            std::cout << "Found Match!\n";
            std::cout << "Name: " + database[i].name +"\n";
            std::cout << "Surname: " + database[i].surname +"\n";
            std::cout << "Grades: " + database[i].classRecord +"\n";
            return;
        }
    }
    std::cout << "No match found...\n";
}

void WHTMIC023::gradeStudent( vector<StudentRecord>& database, string studentNum, string grade ) {
    for (int i = 0; i < database.size(); i++) {
        if (database[i].studentNum == studentNum) {
            database[i].classRecord += (grade + " ");
            std::cout << "Added grade successfully!\n";
            return;
        }
    }
    std::cout << "The entered student number could not be found...\n";
}
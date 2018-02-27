#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "DatabaseLib.h"

using std::string;
using std::vector;
using std::cout;
using WHTMIC023::StudentRecord;

vector<StudentRecord> database;
 
void WHTMIC023::addStudent( string name, string surname, string studentNum, string classRecord ) {
    StudentRecord record = {name, surname, studentNum, classRecord};
    database.push_back(record);
    cout << "Added student record to database.\n";
}

void WHTMIC023::saveDatabase( const char* filepath ) {
    std::ofstream outFile;
    outFile.open(filepath);
    for (int i = 0; i < database.size(); i++) {
        string current = database[i].name + " " + database[i].surname + " " + database[i].studentNum + " " + database[i].classRecord;
        outFile << current << std::endl;
    }
    outFile.close();
    cout << "Saved database to file.\n";
}

void WHTMIC023::readDatabase( const char* filepath ) {
    vector<StudentRecord>().swap(database);
    std::ifstream inFile;
    inFile.open(filepath);
    string line;
    while (getline(inFile, line)) {
        std::stringstream split(line);
        string token;
        int count = 0;
        StudentRecord newRecord;
        while (getline(split, token, ' ')) {
            if (count == 0)
                newRecord.name = token;
            if (count == 1)
                newRecord.surname = token;
            if (count == 2)
                newRecord.studentNum = token;
            if (count == 3)
                newRecord.classRecord = token;
            else
                newRecord.classRecord += " " + token;
            count++;
        }
        database.push_back(newRecord);
    }
    inFile.close();
    cout << "Imported database from file.\n";
}

void WHTMIC023::queryStudent( string studentNum ) {
    std::cout << database.size() +"\n";
    for (int i = 0; i < database.size(); i++) {
        if (database[i].studentNum == studentNum) {
            cout << "Name: " + database[i].name +"\n";
            cout << "Surname: " + database[i].surname +"\n";
            cout << "Grades: " + database[i].classRecord +"\n";
            return;
        }
    }
    cout << "No match found...\n";
}

void WHTMIC023::gradeStudent( string studentNum) {
    for (int i = 0; i < database.size(); i++) {
        if (database[i].studentNum == studentNum) {
            int total = 0;
            int count = 0;
            int current;
            string token;
            std::stringstream grades(database[i].classRecord);
            while (getline(grades, token, ' ')) {
                std::stringstream(token) >> current;
                total += current;
                count+=1;
            }
            int average = total / count;
            cout << "Average grade: " << average << std::endl;
            return;
        }
    }
    cout << "The entered student number could not be found...\n";
}
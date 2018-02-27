#ifndef DATABASEDRIVER_H
#define DATABASEDRIVER_H

using std::string;

namespace WHTMIC023 {

    struct StudentRecord {
        std::string name;
        std::string surname;
        std::string studentNum;
        std::string classRecord;
    };

    void addStudent( std::vector<StudentRecord> database, string name, string surname, string studentNum );

    void saveDatabase( string filepath );

    std::vector<StudentRecord> readDatabase( string filepath );

    void queryStudent( std::vector<StudentRecord> database, string studentNum );

    void gradeStudent( std::vector<StudentRecord> database, string studentNum, string grade );
}
#endif
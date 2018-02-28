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

    void addStudent( string name, string surname, string studentNum, string classRecord );

    void saveDatabase( const char* filepath );

    void readDatabase( const char* filepath );

    void queryStudent( string studentNum );

    void gradeStudent( string studentNum );
}
#endif
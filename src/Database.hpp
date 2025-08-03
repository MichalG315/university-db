#pragma once
#include <string>
#include <vector>
#include "Student.hpp"

class Database {
private:
    std::vector<Student> database_;

public:
    void addNewStudent(Student student);
    Student getStudentData();
    void showAllDatabase();
    void showSearchedDatabase(std::vector<Student> students);
    void printStudentData(Student student);
    std::vector<Student> searchBySurname(const std::string& surname);
    std::vector<Student> searchByPesel(const long pesel);
    void sortByPesel();
    void sortBySurname();
    void removeByIndex(const int index);
    void addStudentsFromFile(std::vector<Student> students);
    void saveDatabaseToFile(std::string fileName);
    static bool compareByPesel(Student& a, Student& b);
    static bool compareBySurname(Student& a, Student& b);
    std::vector<Student> getStudentsDatabaseForTest();
};
#pragma once
#include <string>
#include <vector>
#include "Student.hpp"

class Database {
private:
    std::vector<Student> database_;

public:
    void addNewStudent();
    Student getStudentData();
    void showAllDatabase();
    void showSearchedDatabase(std::vector<Student> students);
    void printStudentData(Student student);
    void searchBySurname();
    void searchByPesel();
    void sortByPesel();
    void sortBySurname();
    void removeByIndex();
    void addStudentsFromFile(std::vector<Student> students);
    void saveDatabaseToFile(std::string fileName);
    static bool compareByPesel(Student& a, Student& b);
    static bool compareBySurname(Student& a, Student& b);
};
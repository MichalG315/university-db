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
};
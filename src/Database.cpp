#include "Database.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Gender.hpp"
#include "Student.hpp"
#include "StudentUtils.hpp"

void Database::addNewStudent() {
    Student student = getStudentData();
};

Student Database::getStudentData() {
    return Student(
        StudentUtils::getStudentName(),
        StudentUtils::getStudentSurname(),
        StudentUtils::getStudentAddress(),
        StudentUtils::getStudentGender(),
        StudentUtils::getStudentIndex(),
        StudentUtils::getStudentPesel());
};

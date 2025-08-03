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
    database_.push_back(student);
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

void Database::showAllDatabase() {

    std::cout <<"########## Printing  Database ##########\n";
    for (Student& student : database_)
    {
        std::cout <<"########################################\n";
        printStudentData(student);
    }
    std::cout <<"########################################\n\n";
}

void Database::printStudentData(Student student) {
    std::cout << "Student name: " << student.getName() << "\n";
    std::cout << "Student surname: " << student.getSurname() << "\n";
    std::cout << "Student address: " << student.getAddress() << "\n";
    std::cout << "Student gender: " << StudentUtils::toString(student.getGender()) << "\n";
    std::cout << "Student index: " << student.getIndex() << "\n";
    std::cout << "Student pesel: " << student.getSurname() << "\n";
}

#include "Database.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "FileUtils.hpp"
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
    std::cout << "########## Printing  Database ##########\n";
    for (Student& student : database_) {
        std::cout << "########################################\n";
        printStudentData(student);
    }
    std::cout << "########################################\n\n";
}

void Database::showSearchedDatabase(std::vector<Student> students) {
    for (Student& student : students) {
        std::cout << "########################################\n";
        printStudentData(student);
    }
    std::cout << "########################################\n\n";
}

void Database::printStudentData(Student student) {
    std::cout << "Student name: " << student.getName() << "\n";
    std::cout << "Student surname: " << student.getSurname() << "\n";
    std::cout << "Student address: " << student.getAddress() << "\n";
    std::cout << "Student gender: " << StudentUtils::toString(student.getGender()) << "\n";
    std::cout << "Student index: " << student.getIndex() << "\n";
    std::cout << "Student pesel: " << student.getPesel() << "\n";
}

void Database::searchBySurname() {
    std::string surname;
    std::vector<Student> results;

    if (database_.empty()) {
        std::cerr << "Database is empty!\n";
        return;
    }

    std::cout << "Provide surname to search: ";
    std::cin >> std::ws >> surname;

    for (Student& student : database_) {
        if (surname.compare(student.getSurname()) == 0) {
            results.push_back(student);
        }
    }

    if (results.empty()) {
        std::cerr << "No student with provided name was found!\n";
        return;
    }

    std::cout << "############ Found students ############\n";
    showSearchedDatabase(results);
}

void Database::searchByPesel() {
    std::string pesel;
    std::vector<Student> results;

    if (database_.empty()) {
        std::cerr << "Database is empty!\n";
        return;
    }

    std::cout << "Provide pesel to search: ";
    std::cin >> std::ws >> pesel;

    for (Student& student : database_) {
        if (std::stol(pesel) == student.getPesel()) {
            results.push_back(student);
        }
    }

    if (results.empty()) {
        std::cerr << "No student with provided pesel was found!\n";
        return;
    }

    std::cout << "############ Found students ############\n";
    showSearchedDatabase(results);
}

void Database::sortByPesel() {
    if (database_.empty()) {
        std::cerr << "Database is empty!\n";
        return;
    }

    std::sort(database_.begin(), database_.end(), Database::compareByPesel);

    showAllDatabase();
}

bool Database::compareByPesel(Student& a, Student& b) {
    return a.getPesel() < b.getPesel();
}

void Database::addStudentsFromFile(std::vector<Student> students) {
    database_.insert(database_.end(), students.begin(), students.end());
}

void Database::saveDatabaseToFile(std::string fileName) {
    FileUtils::writeStudentsToCSV(fileName, database_);
}

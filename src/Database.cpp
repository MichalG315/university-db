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

void Database::addNewStudent(Student student) {
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

std::vector<Student> Database::searchBySurname(const std::string& surname) {
    std::vector<Student> results;

    if (database_.empty()) {
        std::cerr << "Database is empty!\n";
        return results;
    }

    for (Student& student : database_) {
        if (surname.compare(student.getSurname()) == 0) {
            results.push_back(student);
        }
    }

    if (results.empty()) {
        std::cerr << "No student with provided name was found!\n";
        return results;
    }

    std::cout << "############ Found students ############\n";
    showSearchedDatabase(results);
    return results;
}

std::vector<Student> Database::searchByPesel(const long pesel) {
    std::vector<Student> results;

    if (database_.empty()) {
        std::cerr << "Database is empty!\n";
        return results;
    }

    for (Student& student : database_) {
        if (pesel == student.getPesel()) {
            results.push_back(student);
        }
    }

    if (results.empty()) {
        std::cerr << "No student with provided pesel was found!\n";
        return results;
    }

    std::cout << "############ Found students ############\n";
    showSearchedDatabase(results);
    return results;
}

void Database::sortByPesel() {
    if (database_.empty()) {
        std::cerr << "Database is empty!\n";
        return;
    }

    std::sort(database_.begin(), database_.end(), Database::compareByPesel);

    showAllDatabase();
}

void Database::sortBySurname() {
    if (database_.empty()) {
        std::cerr << "Database is empty!\n";
        return;
    }

    std::sort(database_.begin(), database_.end(), Database::compareBySurname);

    showAllDatabase();
}

void Database::removeByIndex(const int index) {
    if (database_.empty()) {
        std::cerr << "Database is empty!\n";
        return;
    }

    for (auto it = database_.begin(); it != database_.end(); ++it) {
        if (it->getIndex() == index) {
            database_.erase(it);
            std::cout << "Student with index: " << index << " is removed.\n";
            return;
        }
    }
    std::cout << "No student with provided index found.\n";
}

bool Database::compareByPesel(Student& a, Student& b) {
    return a.getPesel() < b.getPesel();
}

bool Database::compareBySurname(Student& a, Student& b) {
    return a.getSurname() < b.getSurname();
}

void Database::addStudentsFromFile(std::vector<Student> students) {
    database_.insert(database_.end(), students.begin(), students.end());
}

void Database::saveDatabaseToFile(std::string fileName) {
    FileUtils::writeStudentsToCSV(fileName, database_);
}

std::vector<Student> Database::getStudentsDatabaseForTest() {
    return database_;
}

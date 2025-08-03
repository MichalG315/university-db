#include "FileUtils.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Student.hpp"
#include "StudentUtils.hpp"

std::vector<Student> FileUtils::readStudentsFromFile(const std::string& filename) {
    std::vector<Student> students;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Failed to open file for reading.\n";
        return students;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, surname, address, genderStr, indexStr, peselStr;

        std::getline(ss, name, ',');
        std::getline(ss, surname, ',');
        std::getline(ss, address, ',');
        std::getline(ss, genderStr, ',');
        std::getline(ss, indexStr, ',');
        std::getline(ss, peselStr, ',');

        Gender gender = StudentUtils::mapToGender(genderStr);
        int index = std::stoi(indexStr);
        long pesel = std::stol(peselStr);

        students.emplace_back(name, surname, address, gender, index, pesel);
    }
    return students;
}

void FileUtils::writeStudentsToCSV(const std::string& filename, const std::vector<Student>& students) {
    std::ofstream file(filename);

    if (!file) {
        std::cerr << "Failed to open file for write.\n";
        return;
    }

    for (auto s : students) {
        file << s.getName() << ","
             << s.getSurname() << ","
             << s.getAddress() << ","
             << StudentUtils::toString(s.getGender()) << ","
             << s.getIndex() << ","
             << s.getPesel() << "\n";
    }
}
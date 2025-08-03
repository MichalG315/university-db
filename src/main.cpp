#include <iostream>
#include <string>
#include "Database.hpp"
#include "FileUtils.hpp"
#include "StudentUtils.hpp"
#include "Tests.hpp"

int main() {
    Database database;
    Tests tests;
    tests.runTests();

    int choice;
    std::string fileName = "../files/input.csv";

    database.addStudentsFromFile(FileUtils::readStudentsFromFile(fileName));

    while (true) {
        std::cout << "\n\n##### What do you want to do? Provide number #####\n\n";
        std::cout << "1 -> Add new student\n";
        std::cout << "2 -> Show all database\n";
        std::cout << "3 -> Search by surname\n";
        std::cout << "4 -> Search by pesel\n";
        std::cout << "5 -> Sort by pesel\n";
        std::cout << "6 -> Sort by surname\n";
        std::cout << "7 -> Delete by index\n";
        std::cout << "8 -> Exit program\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            database.addNewStudent(database.getStudentData());
            break;
        case 2:

            database.showAllDatabase();
            break;
        case 3:
            database.searchBySurname(StudentUtils::getStudentSurname());
            break;
        case 4:
            database.searchByPesel(StudentUtils::getStudentPesel());
            break;
        case 5:
            database.sortByPesel();
            break;
        case 6:
            database.sortBySurname();
            break;
        case 7:
            database.removeByIndex(StudentUtils::getStudentIndex());
            break;
        case 8:
            std::cout << "Exit\n";
            database.saveDatabaseToFile(fileName);
            return 0;
        default:
            std::cout << "Provided number: -> " << choice << " <- is not correct. Please provide correct number.\n";
            break;
        }
    }
    return 0;
}

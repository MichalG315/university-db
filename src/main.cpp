#include <iostream>
#include "Database.hpp"

int main(int argc, char const* argv[]) {
    Database database;
    int choice;

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
            database.addNewStudent();
            break;
        case 2:
            std::cout << "All database displayed\n";
            break;
        case 3:
            std::cout << "Search for a student by surname\n";
            break;
        case 4:
            std::cout << "Search for a student by pesel\n";
            break;
        case 5:
            std::cout << "Sort students by surname\n";
            break;
        case 6:
            std::cout << "Sort students by pesel\n";
            break;
        case 7:
            std::cout << "Delete a student by pesel\n";
            break;
        case 8:
            std::cout << "Exit\n";
            return 0;
        default:
            std::cout << "Provided number: -> " << choice << "<- is not correct. Please provide correct number.\n";
            break;
        }
    }
    return 0;
}

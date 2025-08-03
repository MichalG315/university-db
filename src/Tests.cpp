#include "Tests.hpp"
#include <iostream>
#include <vector>
#include "Database.hpp"
#include "Gender.hpp"
#include "Student.hpp"

void Tests::runTests() {
    Database database;

    Student student1("Emily", "Smith", "London", Gender::Male, 100001, 64092691498L);
    Student student2("John", "Doe", "Manchester", Gender::Male, 100002, 60042173151L);
    Student student3("Olivia", "Johnson", "Bristol", Gender::Male, 100003, 78111841551L);

    database.addNewStudent(student1);
    database.addNewStudent(student2);
    database.addNewStudent(student3);

    if (database.getStudentsDatabaseForTest().size() == 3) {
        std::cout << "1. test passed. Added 3 students\n";
    } else {
        std::cout << "1. test failed. Can not add 3 students\n";
    }

    Student foundStudent1 = database.searchBySurname("Smith").front();
    if (foundStudent1.getSurname().compare("Smith") == 0) {
        std::cout << "2. test passed. Student with surname Smith found.\n";
    } else {
        std::cout << "2. test failed. Student with surname Smith is not found.\n";
    }

    Student foundStudent2 = database.searchByPesel(78111841551L).front();
    if (foundStudent2.getPesel() == 78111841551L) {
        std::cout << "3. test passed. Student with pesel 78111841551 found.\n";
    } else {
        std::cout << "3. test failed. Student with pesel 78111841551L is not found.\n";
    }

    database.sortByPesel();
    Student firstStudentAfterSortingByPesel = database.getStudentsDatabaseForTest().front();

    if (firstStudentAfterSortingByPesel.getPesel() == 60042173151L) {
        std::cout << "4. test passed. Database is sorted by Pesel\n";
    } else {
        std::cout << "4. test failed.  Database is not sorted by Pesel.\n";
    }

    database.sortBySurname();
    Student firstStudentAfterSortingBySurname = database.getStudentsDatabaseForTest().front();

    if (firstStudentAfterSortingBySurname.getSurname().compare("Doe") == 0) {
        std::cout << "5. test passed. Database is sorted by surname\n";
    } else {
        std::cout << "5. test failed.  Database is not sorted by surname.\n";
    }

    database.removeByIndex(100002);
    if (database.searchBySurname("Doe").empty() && database.getStudentsDatabaseForTest().size() == 2) {
        std::cout << "6. test passed. Student has been removed by index.\n";
    } else {
        std::cout << "6. test failed. Student has not been removed by index.\n";
    }
    return;
}

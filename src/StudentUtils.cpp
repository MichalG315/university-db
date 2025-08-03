#include "StudentUtils.hpp"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
#include <string>
#include "Gender.hpp"

std::string StudentUtils::getStudentName() {
    std::string name;
    while (true) {
        std::cout << "What is the student's name? ";
        std::cin.sync();
        std::getline(std::cin, name);

        if (!name.empty()) {
            return name;
        } else {
            std::cout << "Provided name is empty. Try again.\n";
        }
    }
}
std::string StudentUtils::getStudentSurname() {
    std::string surname;
    while (true) {
        std::cout << "What is the student's surname? ";
        std::cin.sync();
        std::getline(std::cin, surname, '\n');

        if (!surname.empty()) {
            return surname;
        } else {
            std::cout << "Provided surname is empty. Try again.\n";
        }
    }
}
std::string StudentUtils::getStudentAddress() {
    std::string address;
    while (true) {
        std::cout << "What is the student's address? ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin >> std::ws, address, '\n');

        if (!address.empty()) {
            return address;
        } else {
            std::cout << "Provided address is empty. Try again.\n";
        }
    }
}
Gender StudentUtils::getStudentGender() {
    std::string gender;
    Gender mappedGender;

    while (true) {
        std::cout << "What is the student's gender? Female or Male? ";
        std::cin >> gender;
        mappedGender = mapToGender(toLowerCase(gender));

        if (!gender.empty() && !(mappedGender == Gender::Other)) {
            return mappedGender;
        } else {
            std::cout << "Provided gender is empty or is incorrect. Try again.\n";
        }
    }
}
int StudentUtils::getStudentIndex() {
    std::string index;
    while (true) {
        std::cout << "What is the student's index? The index should contain 6 digits. ";
        std::cin >> index;

        if (!index.empty() && isDigitsOnly(index) && index.length() == 6) {
            return std::stoi(index);
        } else {
            std::cout << "Provided index is empty or is not only digits. Try again.\n";
        }
    }
}
long StudentUtils::getStudentPesel() {
    std::string pesel;
    while (true) {
        std::cout << "What is the student's pesel? Pesel should contain 11 digits. ";
        std::cin >> pesel;

        if (!pesel.empty() && isDigitsOnly(pesel) && pesel.length() == 11) {
            return std::stol(pesel);
        } else {
            std::cout << "Provided pesel is empty or is not only digits. Try again.\n";
        }
    }
}

Gender StudentUtils::mapToGender(std::string gender) {
    if (gender == "male") {
        return Gender::Male;
    } else if (gender == "female") {
        return Gender::Female;
    } else {
        return Gender::Other;
    }
}

std::string StudentUtils::toString(Gender gender) {
    if (gender == Gender::Female) {
        return "Female";
    } else {
        return "Male";
    }
}

std::string StudentUtils::toLowerCase(const std::string& input) {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}

bool StudentUtils::isDigitsOnly(const std::string& str) {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

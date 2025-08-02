#include "StudentUtils.hpp"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include "Gender.hpp"

std::string StudentUtils::getStudentName() {
    std::string name;
    while (true) {
        std::cout << "What is the student's name? ";
        std::cin >> name;

        if (isNotEmpty(name)) {
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
        std::cin >> surname;

        if (isNotEmpty(surname)) {
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
        std::cin >> address;

        if (isNotEmpty(address)) {
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
        mappedGender = mapToGender(gender);

        if (isNotEmpty(gender) && !(mappedGender == Gender::Other)) {
            return mappedGender;
        } else {
            std::cout << "Provided gender is empty or is incorrect. Try again.\n";
        }
    }
}
int StudentUtils::getStudentIndex() {
    std::string index;
    while (true) {
        std::cout << "What is the student's index? ";
        std::cin >> index;

        if (isNotEmpty(index) && isDigitsOnly(index)) {
            return std::stoi(index);
        } else {
            std::cout << "Provided index is empty or is not only digits. Try again.\n";
        }
    }
}
long StudentUtils::getStudentPesel() {
    std::string pesel;
    while (true) {
        std::cout << "What is the student's pesel? ";
        std::cin >> pesel;

        if (isNotEmpty(pesel) && isDigitsOnly(pesel)) {
            return std::stol(pesel);
        } else {
            std::cout << "Provided pesel is empty or is not only digits. Try again.\n";
        }
    }
}

bool StudentUtils::isNotEmpty(const std::string& input) {
    return !input.empty();
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

std::string StudentUtils::toLowerCase(const std::string& input) {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}

bool StudentUtils::isDigitsOnly(const std::string& str) {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}
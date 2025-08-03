#include "StudentUtils.hpp"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "Gender.hpp"

std::string StudentUtils::getStudentName() {
    std::string name;

    std::cout << "What is the student's name? ";
    std::cin.sync();
    std::getline(std::cin >> std::ws, name);

    return name;
}
std::string StudentUtils::getStudentSurname() {
    std::string surname;

    std::cout << "What is the student's surname? ";
    std::cin.sync();
    std::getline(std::cin >> std::ws, surname);

    return surname;
}
std::string StudentUtils::getStudentAddress() {
    std::string address;

    std::cout << "What is the student's address? ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin >> std::ws, address);

    return address;
}
Gender StudentUtils::getStudentGender() {
    std::string gender;
    Gender mappedGender;

    while (true) {
        std::cout << "What is the student's gender? Female or Male? ";
        std::cin >> std::ws >> gender;
        mappedGender = mapToGender(toLowerCase(gender));

        if (!(mappedGender == Gender::Other)) {
            return mappedGender;
        } else {
            std::cerr << "Provided gender is incorrect. Try again.\n";
        }
    }
}
int StudentUtils::getStudentIndex() {
    std::string index;

    while (true) {
        std::cout << "What is the student's index? The index should contain 6 digits. ";
        std::cin >> std::ws >> index;

        if (index.length() != 6) {
            std::cerr << "Provided index is not 6 digits long. Try again.\n";
            continue;
        }

        if (!isDigitsOnly(index)) {
            std::cerr << "Provided index must contain only digits.Try again.\n";
            continue;
        }

        return std::stoi(index);
    }
}
long StudentUtils::getStudentPesel() {
    std::string pesel;

    while (true) {
        std::cout << "What is the student's pesel? Pesel should contain 11 digits. ";
        std::cin >> std::ws >> pesel;

        if (pesel.length() != 11) {
            std::cerr << "Provided pesel is not 11 digits long. Try again.\n";
            continue;
        }

        if (!isDigitsOnly(pesel)) {
            std::cerr << "Provided pesel must contain only digits.Try again.\n";
            continue;
        }

        if (!isPeselValid(pesel)) {
            std::cerr << "Provided pesel is not valid.Try again.\n";
            continue;
        }

        return std::stol(pesel);
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

bool StudentUtils::isPeselValid(std::string& pesel) {
    std::vector<int> coeff = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    int checkSum = 0;
    int lastNumber;

    for (int i = 0; i < 10; ++i) {
        checkSum += ((pesel[i] - '0') * coeff[i]) % 10;
    }

    lastNumber = 10 - (checkSum % 10);

    if ((pesel.back() - '0') == lastNumber) {
        return true;
    } else {
        return false;
    }
}

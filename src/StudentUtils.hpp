#pragma once
#include <string>
#include "Gender.hpp"

class StudentUtils {
public:
    static std::string getStudentName();
    static std::string getStudentSurname();
    static std::string getStudentAddress();
    static Gender getStudentGender();
    static int getStudentIndex();
    static long getStudentPesel();
    static bool isNotEmpty(const std::string& input);
    static Gender mapToGender(std::string gender);
    static std::string toString(Gender gender);
    static std::string toLowerCase(const std::string& input);
    static bool isDigitsOnly(const std::string& str);
};
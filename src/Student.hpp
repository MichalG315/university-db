#pragma once
#include <string>
#include "Gender.hpp"

class Student {
public:
    std::string name_;
    std::string surname_;
    std::string address_;
    Gender gender_;
    int index_;
    long pesel_;

public:
    Student(
        const std::string& name,
        const std::string& surname,
        const std::string& address,
        Gender gender,
        int index,
        long pesel);
};
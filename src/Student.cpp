#include "Student.hpp"
#include <string>
#include "Gender.hpp"

Student::Student(
    const std::string& name,
    const std::string& surname,
    const std::string& address,
    Gender gender,
    int index,
    long pesel)
    : name_(name),
      surname_(surname),
      address_(address),
      gender_(gender),
      index_(index),
      pesel_(pesel) {}

;

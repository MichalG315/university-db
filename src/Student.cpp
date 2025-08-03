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

std::string Student::getName() {
    return name_;
}
std::string Student::getSurname() {
    return surname_;
}
std::string Student::getAddress() {
    return address_;
}
Gender Student::getGender() {
    return gender_;
}
int Student::getIndex() {
    return index_;
}
long Student::getPesel() {
    return pesel_;
}

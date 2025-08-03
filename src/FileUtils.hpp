#pragma once
#include <vector>
#include "Student.hpp"

class FileUtils {
public:
    static std::vector<Student> readStudentsFromFile(const std::string& filename);
    static void writeStudentsToCSV(const std::string& filename, const std::vector<Student>& students);
};
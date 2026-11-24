// Jareth Franco
// Program: Shape File Parser
// Date: November 23, 2026
// FileUtils.cpp - Opens the input file or throws a FileOpenException.

#include "FileUtils.h"
#include "Exceptions.h"

void openFileForReading(std::ifstream& file, const std::string& filename) {
    file.open(filename);
    if (!file.is_open()) {
        throw FileOpenException("Could not open file: " + filename);
    }
}

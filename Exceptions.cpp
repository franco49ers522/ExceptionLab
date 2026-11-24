// Jareth Franco
// Program: Shape File Parser
// Date: November 23, 2026
// Exceptions.cpp - Implements the messages for the custom exceptions.

#include "Exceptions.h"

/**
 * @brief Returns the error message for FileOpenException.
 */
const char* FileOpenException::what() const noexcept {
    // .c_str() returns a const char* representation of the std::string
    return msg.c_str();
}

/**
 * @brief Returns the error message for ParseException.
 */
const char* ParseException::what() const noexcept {
    // .c_str() returns a const char* representation of the std::string
    return msg.c_str();
}

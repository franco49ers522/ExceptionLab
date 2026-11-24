// Jareth Franco
// Program: Shape File Parser
// Date: November 23, 2026
// GeometryUtils.cpp - Validates dimensions and calculates areas and perimeters.

#include "GeometryUtils.h"

#include <cmath>
#include <stdexcept>

namespace {
    constexpr double PI = 3.141592653589793;

    void validateDimension(double value, const char* message) {
        if (!std::isfinite(value) || value <= 0) {
            throw std::invalid_argument(message);
        }
    }
}

double calculateArea(double side) {
    validateDimension(side, "Square side must be a positive, finite number.");
    return side * side;
}

double calculateArea(double length, double width) {
    validateDimension(length, "Rectangle length must be a positive, finite number.");
    validateDimension(width, "Rectangle width must be a positive, finite number.");
    return length * width;
}

double calculateCircleArea(double radius) {
    validateDimension(radius, "Circle radius must be a positive, finite number.");
    return radius * (PI * radius);
}

double calculatePerimeter(double side) {
    validateDimension(side, "Square side must be a positive, finite number.");
    return 4 * side;
}

double calculatePerimeter(double length, double width) {
    validateDimension(length, "Rectangle length must be a positive, finite number.");
    validateDimension(width, "Rectangle width must be a positive, finite number.");
    return 2 * (length + width);
}

double calculateCirclePerimeter(double radius) {
    validateDimension(radius, "Circle radius must be a positive, finite number.");
    return 2 * PI * radius;
}

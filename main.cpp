// Jareth Franco
// Program: Shape File Parser
// Date: November 23, 2026
// main.cpp - Reads one shape per line and reports calculations or input errors.

#include "Exceptions.h"
#include "FileUtils.h"
#include "GeometryUtils.h"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

int main() {
    std::cout << std::fixed << std::setprecision(2);

    std::string filename;
    std::ifstream file;
    std::cout << "Enter filename: ";
    std::getline(std::cin, filename);

    try {
        openFileForReading(file, filename);
    } catch (const FileOpenException& error) {
        std::cerr << "File error: " << error.what() << '\n';
        return 1;
    }

    std::cout << "--- Processing Shapes ---\n";
    std::string line;
    int lineNumber = 0;

    while (std::getline(file, line)) {
        ++lineNumber;

        // Read each row separately so a bad value cannot affect the next row.
        std::istringstream row(line);
        std::string shape;
        if (!(row >> shape)) {
            continue;
        }

        try {
            double area;
            double perimeter;
            std::string extra;

            if (shape == "square") {
                double side;
                if (!(row >> side) || (row >> extra)) {
                    throw ParseException("Square requires exactly one numeric side.");
                }
                area = calculateArea(side);
                perimeter = calculatePerimeter(side);
            } else if (shape == "rectangle") {
                double length, width;
                if (!(row >> length >> width) || (row >> extra)) {
                    throw ParseException("Rectangle requires a numeric length and width.");
                }
                area = calculateArea(length, width);
                perimeter = calculatePerimeter(length, width);
            } else if (shape == "circle") {
                double radius;
                if (!(row >> radius) || (row >> extra)) {
                    throw ParseException("Circle requires exactly one numeric radius.");
                }
                area = calculateCircleArea(radius);
                perimeter = calculateCirclePerimeter(radius);
            } else {
                throw ParseException("Unknown shape: " + shape);
            }

            if (!std::isfinite(area) || !std::isfinite(perimeter)) {
                throw std::overflow_error("Area or perimeter is too large to display.");
            }

            std::cout << "Line " << lineNumber << ": " << shape
                      << " | Area: " << area << " | Perimeter: " << perimeter << '\n';
        } catch (const ParseException& error) {
            std::cerr << "Line " << lineNumber << ": Parse error: " << error.what() << '\n';
        } catch (const std::invalid_argument& error) {
            std::cerr << "Line " << lineNumber << ": Invalid dimension: " << error.what() << '\n';
        } catch (const std::exception& error) {
            std::cerr << "Line " << lineNumber << ": Error: " << error.what() << '\n';
        }
    }

    if (!file.eof()) {
        std::cerr << "File error: Could not finish reading " << filename << '\n';
        return 1;
    }

    std::cout << "--- Processing Complete ---\n";
    return 0;
}

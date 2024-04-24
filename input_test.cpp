#include <iostream>
#include <string>
#include <cctype>  // For std::isdigit and std::isalpha functions

int main() {
    std::string input;
    std::cout << "Enter a single character or number: ";
    std::cin >> input;  // Take input from the user

    if (input.length() == 1) {  // Check if the input is exactly one character long
        char c = input[0];  // Extract the single character
        if (std::isdigit(c)) {  // Check if the character is a digit
            std::cout << "number\n";
        } else if (std::isalpha(c)) {  // Check if the character is an alphabetic letter
            std::cout << "letter\n";
        } else {
            std::cout << "neither\n";  // Handle non-alphanumeric characters
        }
    } else {
        std::cout << "Please enter exactly one character.\n";
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono> // For timing

// Function to generate a vector filled with random integers
std::vector<int> generateRandomIntegers(size_t count) {
    std::vector<int> vec(count);
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Seed for random number generation
    std::generate(vec.begin(), vec.end(), []() { return std::rand() % 10000; }); // Random numbers between 0 and 9999
    return vec;
}

// Functional style quicksort implementation
void quicksort(std::vector<int>& vec, int low, int high) {
    auto partition = [&](int low, int high) {
        int pivot = vec[high]; // Pivot
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (vec[j] < pivot) {
                i++;
                std::swap(vec[i], vec[j]); // Place all smaller elements to left of pivot
            }
        }
        std::swap(vec[i + 1], vec[high]);
        return i + 1;
    };

    if (low < high) {
        int pi = partition(low, high);
        quicksort(vec, low, pi - 1);  // Before partition index
        quicksort(vec, pi + 1, high); // After partition index
    }
}

// Function to find elements containing the digit '2'
void findElementsWithTwo(const std::vector<int>& vec) {
    for (int num : vec) {
        if (std::to_string(num).find('2') != std::string::npos) {
            std::cout << num << " ";
        }
    }
}

int main() {
    std::vector<int> numbers = generateRandomIntegers(10000); // Generate 10 000 random integers

    // Time the sorting process
    auto start = std::chrono::high_resolution_clock::now();
    quicksort(numbers, 0, numbers.size() - 1); // Apply quicksort
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> sort_time = end - start;

    std::cout << "Sorting took " << sort_time.count() << " milliseconds.\n";
    std::cout << "After sorting:\n";
    for (int i = 0; i < 10; ++i) { // Print the first 10 elements
        std::cout << numbers[i] << " ";
    }
    std::cout << "...\n";

    // Time the search for elements containing the digit '2'
    start = std::chrono::high_resolution_clock::now();
    std::cout << "Elements containing '2': ";
    findElementsWithTwo(numbers);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> find_time = end - start;

    std::cout << "\nFinding elements took " << find_time.count() << " milliseconds.\n";

    return 0;
}

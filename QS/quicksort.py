import random
import time

# Function to generate a list filled with random integers
def generate_random_integers(count):
    return [random.randint(0, 9999) for _ in range(count)]

# Quick sort implementation (in-place)
def quicksort(arr, low, high):
    def partition(low, high):
        pivot = arr[high]
        i = low - 1
        for j in range(low, high):
            if arr[j] < pivot:
                i += 1
                arr[i], arr[j] = arr[j], arr[i]
        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        return i + 1
    
    if low < high:
        pi = partition(low, high)
        quicksort(arr, low, pi - 1)
        quicksort(arr, pi + 1, high)

# Function to find elements containing the digit '2'
def find_elements_with_two(arr):
    return [num for num in arr if '2' in str(num)]

def main():
    numbers = generate_random_integers(10000)  # Generate 10 000 random integers

    # Time the sorting process
    start_time = time.time()
    quicksort(numbers, 0, len(numbers) - 1)  # Apply quicksort
    end_time = time.time()
    print(f"Sorting took {end_time - start_time:.4f} seconds.")

    print("After sorting:")
    print(numbers[:10], "...")  # Print the first 10 elements

    # Time the search for elements containing the digit '2'
    start_time = time.time()
    result = find_elements_with_two(numbers)
    end_time = time.time()
    print("Elements containing '2':", result[:10], "...")  # Print first 10 matches for brevity
    print(f"Finding elements took {end_time - start_time:.4f} seconds.")

if __name__ == '__main__':
    main()

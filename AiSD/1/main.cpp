#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <fstream>
#include "sorting_algorithms.h"


void sort_using_algorithm(std::vector<int>& data, int algorithm) {
    std::cout << "\n\n\n---Sorting Algorithm: ";
    switch (algorithm)
    {
    case 1:
        std::cout << "Insertion sort---\n";
        insertion_sort(data);
        break;
    case 2:
        std::cout << "Shell sort---\n";
        shell_sort(data);
        break;
    case 3:
        std::cout << "Selection sort---\n";
        selection_sort(data);
        break;
    case 4:
        std::cout << "Heap sort---\n";
        heap_sort(data);
        break;
    case 5:
        std::cout << "Quick sort with left pivot---\n";
        quick_sort_left_pivot(data,0, data.size() - 1);
        break;
    case 6:
        std::cout << "Quick sort with random pivot---\n";
        quick_sort_random_pivot(data,0, data.size() - 1);
        break;
    default:
        std::cout << "There's no such thing, mate 0_0" << std::endl;
        break;
    }
}

int main(int argc, char* argv[]) {
    // Command-line arguments: make run INPUT = path/to/data.txt

    if (argc != 2) {
        std::cerr << "Usage: make run INPUT = <file_name>\n";
        return 1;
    }

    // Open the file
    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "Unable to open file " << argv[1] << "\n";
        return 1;
    }

    // Read the data from the file
    std::vector<int> data;
    int x,n;
    while (file >> x) {
        data.push_back(x);
    }

    // Close the file
    file.close();
    
    std::cout << "\n\n---SELECT THE SORTING ALGORITHM---\n\n1. Insertion sort\n2. Shell sort\n3. Selection sort\n4. Heap sort\n5. Quick sort with left pivot\n6. Quick sort with random pivot\n\n";
    std::cin >> n;
    // Array before sorting
    std::cout << "\n\n----Array before----\n\n";
    for (const auto &elem : data) {
        std::cout << elem << " ";
    }

    // Sorting algorithm
    sort_using_algorithm(data, n);

    // Print the sorted data
    std::cout << "\n\n----Sorted data----\n\n";
    for (const auto &value : data) {
        std::cout << value << " ";
    }
    std::cout << "\n";

    return 0;
}
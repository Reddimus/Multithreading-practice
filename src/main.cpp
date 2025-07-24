#include <iostream>
#include "threadspractice.h"

int main()
{
    std::cout << "Testing Order" << std::endl;

    // Test case 1
    std::cout << "Input: [A1, A2, A3] -> Output: ";
    ThreadedAlgorithmsTest::in_order({algorithm1, algorithm2, algorithm3});

    // Test case 2
    std::cout << "Input: [A2, A1, A3] -> Output: ";
    ThreadedAlgorithmsTest::in_order({algorithm2, algorithm1, algorithm3});

    // Test case 3
    std::cout << "Input: [A3, A1, A2] -> Output: ";
    ThreadedAlgorithmsTest::in_order({algorithm3, algorithm1, algorithm2});

    // Test case 4
    std::cout << "Input: [A2, A3, A1] -> Output: ";
    ThreadedAlgorithmsTest::in_order({algorithm2, algorithm3, algorithm1});

    // Test case 5
    std::cout << "Input: [A3, A2, A1] -> Output: ";
    ThreadedAlgorithmsTest::in_order({algorithm3, algorithm2, algorithm1});

    // Test case 6
    std::cout << "Input: [A1, A3, A2] -> Output: ";
    ThreadedAlgorithmsTest::in_order({algorithm1, algorithm3, algorithm2});

    return 0;
}

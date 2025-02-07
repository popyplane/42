#include "../inc/Array.hpp"

int main()
{
    try {
        // Test default constructor
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        // Test constructor with size parameter
        Array<int> intArray(5);
        std::cout << "intArray size: " << intArray.size() << std::endl;
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
        }

        // Test copy constructor
        Array<int> copyArray = intArray;
        std::cout << "copyArray size: " << copyArray.size() << std::endl;

        // Modify original and check copy
        intArray[0] = 42;
        std::cout << "intArray[0]: " << intArray[0] << ", copyArray[0]: " << copyArray[0] << std::endl;

        // Test assignment operator
        Array<int> assignedArray;
        assignedArray = intArray;
        std::cout << "assignedArray size: " << assignedArray.size() << std::endl;
        std::cout << "assignedArray[0]: " << assignedArray[0] << std::endl;

        // Test out-of-bounds access
        try {
            std::cout << intArray[10] << std::endl; // Should throw an exception
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Test with another type
        Array<std::string> strArray(3);
        strArray[0] = "Hello";
        strArray[1] = "World";
        strArray[2] = "!";
        for (unsigned int i = 0; i < strArray.size(); ++i) {
            std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
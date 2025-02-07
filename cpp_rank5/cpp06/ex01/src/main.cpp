#include "../inc/Serializer.hpp"

int main()
{
    Data original;
    original.id = 42;
    original.name = "Test Data";

    std::cout << "Original Data: " << original.id << ", " << original.name << std::endl;

    uintptr_t raw = Serializer::serialize(&original);
    Data* deserialized = Serializer::deserialize(raw);

    std::cout << "Deserialized Data: " << deserialized->id << ", " << deserialized->name << std::endl;

    if (deserialized == &original)
        std::cout << "Serialization and deserialization worked correctly." << std::endl;
    else
        std::cout << "Something went wrong with serialization/deserialization." << std::endl;
    return (0);
}
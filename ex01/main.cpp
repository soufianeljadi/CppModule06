#include "Serializer.hpp"

int main() 
{
    Data data;
    data.n = 1337;

    std::cout << "Original data: " << data.n << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized data: " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized data: " << deserializedData->n << std::endl;

    return 0;
}
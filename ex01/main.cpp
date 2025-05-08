#include "Serializer.hpp"

int main() 
{
    Data data;
    data.n = 1337;

    // Serialize the data
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized data: " << raw << std::endl;

    // Deserialize the data
    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized data: " << deserializedData->n << std::endl;

    return 0;
}
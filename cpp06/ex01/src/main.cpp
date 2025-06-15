#include "Serializer.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <string>" << std::endl;
    return 1;
  }

  Data data;
  data.str = argv[1];
  uintptr_t raw = Serializer::serialize(&data);
  Data *ptr = Serializer::deserialize(raw);
  std::cout << "original ptr:     " << &data << std::endl;
  std::cout << "deserialized ptr: " << ptr << std::endl;

  return 0;
}

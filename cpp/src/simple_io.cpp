#include <iostream>
#include <fstream>
#include "types.h"

void write_to_file(const complex_vector& v)
{
    std::ofstream file;
    file.open("./file.bin", std::ios_base::binary);
    const char* char_ptr { reinterpret_cast<const char*>( v.data() ) };
    file.write(char_ptr, sizeof(complex_double) * v.size());
}

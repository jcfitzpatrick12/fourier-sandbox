#include <iostream>
#include "types.h"

void write_to_file(const complex_vector& f)
{
    std::cout << "Here!" << "\n";
    const complex_double* ptr { f.data() };
    for (int i {0}; i < f.size(); ++i)
    {
        std::cout << *(ptr + i) << "\n";
    }
}

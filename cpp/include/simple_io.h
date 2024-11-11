#ifndef SIMPLE_IO_H
#define SIMPLE_IO_H

#include <fstream>
#include "types.h"
#include "constants.h"

// Compute the total number of bytes stored in the array managed by the vector.
template <typename T>
size_t total_bytes(const std::vector<T> &v)
{
    return sizeof(T) * v.size();
}

// Get the dir path for this repository (based on a preset environment variable)
static const fs::path get_fourier_series_dir_path()
{
    const char* dir_path_ptr { std::getenv(FOURIER_SERIES_ENV_VAR_NAME) };
    if (!dir_path_ptr)
    {
        throw std::runtime_error("Environment variable not set!");    
    }
    std::string dir_path(dir_path_ptr);
    return fs::path(dir_path);
}

// Get the file path for the write file.
static const fs::path get_file_path(const std::string &file_name)
{
    fs::path fourier_series_dir_path { get_fourier_series_dir_path() };
    fs::path data_dir_name { DATA_DIR_NAME };
    return fourier_series_dir_path / data_dir_name / file_name;

}

// Write the underlying array managed by the vector to a binary file.
template <typename T>
void write_to_file(const std::string &file_name,
                   const std::vector<T> &v)
{
    const char* bytes_ptr { reinterpret_cast<const char*>( v.data() ) };

    fs::path file_path { get_file_path(file_name) };
    fs::create_directories( file_path.parent_path() );

    std::ofstream file(file_path, std::ios_base::binary);
    file.write(bytes_ptr, total_bytes(v));
    file.close();
}

#endif
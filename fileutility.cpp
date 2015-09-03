
#include "fileutility.h"

#include <assert.h>
#include <stdlib.h>
#include <fstream>

std::string FileUtility::m_resource_path;

bool FileUtility::ReadFile(const char* file,
                           char **out_data,
                           int* out_data_size)
{
    bool result = false;
    std::ifstream fs(file, std::ifstream::ate | std::ifstream::binary);

    result = fs.is_open();

    *out_data_size = fs.tellg();

    result = *out_data_size > 0;

    if (result)
    {
        *out_data = (char*)malloc(*out_data_size + 1);
        fs.seekg(0, std::ifstream::beg);
        fs.read(*out_data, *out_data_size);
        fs.close();
        out_data[*out_data_size] = 0;
    }

    return result;
}

const char* FileUtility::GetResourcePath()
{
    return m_resource_path.c_str();
}

const char* FileUtility::GetFullResourcePath(const char *file)
{
    return (m_resource_path + file).c_str();
}

void FileUtility::SetResourcePath(const char *path)
{
    m_resource_path = path;
}


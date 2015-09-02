
#include "fileutility.h"

#include <stdio.h>

FileUtility::FileUtility()
{

}

FileUtility::~FileUtility()
{

}

bool FileUtility::ReadFile(const char *file, char **out_data)
{
    bool result = false;
    FILE* file_ptr;
    long size;

    file_ptr = fopen(file, "rb");

    result = file_ptr != NULL;

    if (result)
    {
        fseek(file_ptr, 0, SEEK_END);
        size = ftell(file_ptr);
        *out_data = (char*)malloc(size + 1);
        fseek(file_ptr, 0, SEEK_SET);
        fread(buffer, size, 1, file_ptr);
        fclose(file_ptr);
        (*out_data)[length] = 0;
    }

    return result;
}


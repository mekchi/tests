#ifndef FILEUTILITY_H
#define FILEUTILITY_H

#include <string>

class FileUtility
{
public:
    static void SetResourcePath(const char* path);
    static const char* GetResourcePath();
    static const char* GetFullResourcePath(const char* file);
    static bool ReadFile(const char* file,
                         char** out_data,
                         int* out_data_size);

private:
    FileUtility() {}
    ~FileUtility(){}

    static std::string m_resource_path;
};

#endif // FILEUTILITY_H

#ifndef FILEUTILITY_H
#define FILEUTILITY_H


class FileUtility
{
public:
    FileUtility();
    ~FileUtility();

    static bool ReadFile(const char* file, char** out_data);
};

#endif // FILEUTILITY_H

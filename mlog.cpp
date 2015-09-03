
#include "mlog.h"

#include <cstdarg>
#include <stdio.h>
#include <iostream>

MLog::MLog()
{

}

MLog::~MLog()
{

}

void MLog::Error(MLogErrorType error_type, const char *str, ...)
{
    static char buffer[4096];
    va_list arguments;
    int number = 0;

    va_start(arguments, str);
    vsprintf(buffer, str, arguments);
    std::cerr << ErrorType(error_type) << " : " << buffer << std::endl;
    va_end(arguments);

}

const char* MLog::ErrorType(MLogErrorType error_type)
{
    switch(error_type)
    {
    case MLOG_ET_OPENGL:
        return "OPENGL ERROR";

    case MLOG_ET_FILE:
        return "FILE_ERROR";

    case MLOG_ET_ERROR:
        return "ERROR";

    case MLOG_ET_INIT:
        return "INIT ERROR";

    default:
        return "";
    }
}


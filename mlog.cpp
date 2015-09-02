
#include "mlog.h"

#include <iostream>

MLog::MLog()
{

}

MLog::~MLog()
{

}

void MLog::Error(MLogErrorType error_type, const char *info)
{
    std::cerr << ErrorType(error_type) << " : " << info;
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
        return;
    }
}


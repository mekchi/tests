
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
    va_list arguments;
    int number = 0;

	fprintf(stderr, "%s : ", ErrorType(error_type));
    va_start(arguments, str);
    vfprintf(stderr, str, arguments);
    va_end(arguments);
	fprintf(stderr, "\n");

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

	case MLOG_ET_LOG:
		return "LOG";

    default:
        return "";
    }
}


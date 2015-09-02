#ifndef MLOG_H
#define MLOG_H

class MLog
{
public:
    MLog();
    ~MLog();

    enum MLogErrorType
    {
        MLOG_ET_INIT,
        MLOG_ET_ERROR,
        MLOG_ET_FILE,
        MLOG_ET_OPENGL
    };

    static Error(MLogErrorType error_type, const char* info);

private:

    static const char* ErrorType(MLogErrorType error_type);

};

#endif // MLOG_H

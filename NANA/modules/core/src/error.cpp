#include "../include/core/error.h"
#include <iostream>
#include <ostream>

namespace NANA {

////////////////////////////////// Exception /////////////////////////////////


Exception::Exception()
{
    code = 0;
    line = 0;
}

Exception::Exception(int _code, const String& _err, const String& _func, const String& _file, int _line)
    : code(_code), err(_err), func(_func), file(_file), line(_line)
{
    formatMessage();
}

Exception::~Exception() throw() {}

/*!
 \return the error description and the context as a text string.
 */
const char* Exception::what() const throw()
{
    return msg.c_str();
}

void Exception::formatMessage()
{
    size_t pos = err.find('\n');
    bool multiline = pos != String::npos;
    if (multiline)
    {
        size_t prev_pos = 0;
        while (pos != String::npos)
        {
            std::cout << "> " << err.substr(prev_pos, pos - prev_pos) << std::endl;
            prev_pos = pos + 1;
            pos = err.find('\n', prev_pos);
        }
        std::cout << "> " << err.substr(prev_pos);
        if (err[err.size() - 1] != '\n')
            std::cout << std::endl;
    }

}


////////////////////////////////// CError /////////////////////////////////
CError* CError::instance(std::string filename)
{
    static CError* obj = nullptr;
    if (nullptr == obj) {
        obj = new CError(filename);
    }
    return obj;
}

CError::CError(std::string& filename)
{
    m_filename = filename;
}
//! @} core_basic


}


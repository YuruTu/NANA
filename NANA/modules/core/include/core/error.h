#pragma once
/**
 * @file error.h
 * @date 2021/11/11 20:54
 *
 * @author Administrator
 * Contact: 707101557@qq.com
 *
 * @brief �����׳��쳣����ֲ��OpenCV
 *
 * TODO: long description
 *
 * \note
*/
#include "core_global.h"
#include <vcruntime_exception.h>
#include <string>
namespace NANA {

//! @addtogroup core_basic
//! @{
///////////////////////////////////////Exception///////////////////////////////////////////
/**
 *@brief �����쳣�׳�
 */
class  NA_API Exception NA_FINAL: public std::exception
{
public:
    /*!
     Default constructor
     */
    Exception();
    /*!
     Full constructor. Normally the constructor is not called explicitly.
     Instead, the macros CV_Error(), CV_Error_() and CV_Assert() are used.
    */
    Exception(int _code, const String& _err, const String& _func, const String& _file, int _line);
    virtual ~Exception() throw();

    /*!
     \return the error description and the context as a text string.
    */
    virtual const char* what() const throw();
    void formatMessage();

    String msg; ///< the formatted error message

    int code; ///< error code @see CVStatus
    String err; ///< error description
    String func; ///< function name. Available only when the compiler supports getting it
    String file; ///< source file name where the error has occurred
    int line; ///< line number in the source file where the error has occurred
};

/// �����ʽ�Ƿ����׳��쳣
#define NA_Assert( expr ) do { if(!!(expr)) ; else throw NANA::Exception( NANA::Error::ERR_ASSERT, #expr, __FUNCTION__, __FILE__, __LINE__ ); } while(0);



/*!
 * @class CError ���ڼ�¼����
 */
class  CError {
public:
    static CError* instance(std::string filename = "error.txt");
private:
    CError(std::string& filename);

    std::string m_filename;//��¼������ļ�


};


//! @} core_basic



}


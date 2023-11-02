#include "..\include\math\rand.h"
#include <cmath>

namespace NANA {
namespace MATH {

double NA_API randNormal(double r_me, double sd)
{
    int  i;
    const int normal_count = 360;//样本数目采用360个
    double ccl_num, ccl_s;
    double ccl_ar[normal_count];
    ccl_num = 0;
    for (i = 0; i < normal_count; i++) {
        ccl_ar[i] = rand() % RAND_MAX / (double)(RAND_MAX-1);//生成一个[0,1]的均匀分布
        ccl_num += ccl_ar[i];
    }
    ccl_num -= ((double)normal_count * 0.5);//减去0-1均匀分布的均值
    ccl_s = 1.0 * (double)normal_count / 12.0;//0-1分布的方差为1/12
    ccl_s = sqrt(ccl_s);
    ccl_num /= ccl_s;//此时ccl_num接近标准正态分布的一个子集
    ccl_num *= sd;
    ccl_num += r_me;
    return ccl_num;
}

double NA_API randNormalWitghBoxMuller()
{
    double x1, x2;
    x1 = std::rand() % RAND_MAX / (double)RAND_MAX;
    x2 = std::rand() % RAND_MAX / (double)RAND_MAX;
    double ccl_num = std::sqrt(-2 * std::log(x1)) * cos(2 * NA_PI * x2);
    return ccl_num;
}

}
}


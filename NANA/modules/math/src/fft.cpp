#include "..\include\math\fft.h"
#include <cmath>

namespace NANA {



void fft(NAFLOAT* p, Complex<NAFLOAT>* f, int n, int k) {
    int it, m, is, i, j, nv;
    double q, s, poddr, poddi;
    for (it = 0; it < n; ++it) {
        m = it;
        is = 0;
        for (i = 0; i < k; ++i) {
            j = m >> 1;
            is = is << 1 + (m - j << 1);
            m = j;
            f[it].re = p[is];
            f[it].im = 0.0;
        }
    }
    std::vector<NAFLOAT> pm(n);//记录傅里叶变换的模
    std::memcpy(&pm[0], p, n * sizeof(NAFLOAT));
    std::vector<NAFLOAT> pt(n, 0.0);//记录傅里叶变换的幅角
    double temp = NA_2PI / static_cast<NAFLOAT>(n);
    pm[0] = 1.0;
    pt[0] = 0.0;
    pm[1] = std::cos(temp);
    pt[1] = -std::sin(temp);
    for (i = 2; i < n - 1; ++i) {
        temp = pm[i - 1] * pm[1];
        q = pt[i - 1] * pt[i];
        s = (pm[i - 1] + pt[i - 1]) * (pm[1] + pt[1]);
        pm[i] = temp - q;
        pt[i] = s - temp - q;
    }
    m = n >> 1;
    nv = 2;
    for (i = k - 2; i >= 0; --i) {
        m >>= 1;
        nv <<= 1;
        for (it = 0; it <= (m - 1) * nv; it += nv) {
            for (j = 0; j < (nv >> 1); ++j) {
                temp = pm[m * j] * f[it + j + nv >> 1].re;
                q = pt[m * j] * f[it + j + nv >> 1].im;
                s = pm[m * j] + pt[m * j];
                s *= (f[it + j + nv >> 1].re + f[it + j + nv >> 1].im);
                poddr = temp - q;
                poddi = s - poddr;
                f[it + j + nv >> 1].re = f[it + j].re - poddr;
                f[it + j + nv >> 1].im = f[it + j].im - poddi;
                f[it + j].re += poddr;
                f[it + j].im += poddi;
            }
        }
    }



}


}





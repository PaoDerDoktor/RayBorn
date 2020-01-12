#include "../include/RGBUtils.hpp"

#include <cmath>

namespace rbRGB {
    double to1_0(const double d) {
        return std::abs((d == 1 || d == -1)? 1 : std::fmod(d, 1));
    }

    double to1_0(const    int i) {
        return std::abs(i%256);
    }


    int to255_0(const double d) {
        return std::abs(std::round(d*255));
    }
}
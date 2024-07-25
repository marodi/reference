#ifndef CONVERTERS_HPP
#define CONVERTERS_HPP

#include "string.hpp"

namespace Converters{
    int stringToInt(const String& s);

    const String intToString(const int num);
}

#endif
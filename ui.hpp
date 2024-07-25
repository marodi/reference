#ifndef UI_HPP
#define UI_HPP

#include <iostream>
#include <stdlib.h>
#include "converters.hpp"
#include "string.hpp"
#include "film.hpp"
#include "document.hpp"
#include "family.hpp"

namespace Interface{
    void writeOptions(const String* names, const int* en);

    int getOption(const int* en);

    void writeString(const String& s);

    const String getString();

    void pause();

    void writeMovie(Film* f);

    void clear();
}

#endif
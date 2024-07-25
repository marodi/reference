#ifndef FILE_HPP
#define FILE_HPP

#include <fstream>
#include <string>
#include <iostream>
#include "filmArray.hpp"
#include "string.hpp"
#include "family.hpp"
#include "document.hpp"
#include "converters.hpp"

namespace FileHandling{
    void readInput(const String& src, FilmArray& dest);

    void saveFilmArray(const String& dest, FilmArray& src);
}

#endif
#ifndef FILMARRAY_HPP
#define FILMARRAY_HPP
#include "film.hpp"
#include <stdexcept>

class FilmArray{
    Film** arr;
    int size;
public:
    FilmArray();

    void add(Film*);

    void remove(const int i);

    const Film* operator[](const int i) const;

    Film* operator[](const int i);

    const int indexOf(const String& s);

    const int length();

    ~FilmArray();
};

#endif
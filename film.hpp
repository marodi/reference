#ifndef FILM_HPP
#define FILM_HPP
#include "string.hpp"
#include "converters.hpp"

class Film{
    String title;
    int duration;
    int releaseYear;
public:
    Film(String title, int duration, int rY);

    Film(const Film& f);

    Film& operator=(const Film& f);

    const String& getTitle() const;

    const int getDuration() const;

    const int getReleaseYear() const;

    void setTitle(const String& t);

    void setDuration(const int t);

    void setReleaseYear(const int t);

    virtual String toString() const ;

    virtual void modify(String* sa);

    virtual ~Film();
};

#endif
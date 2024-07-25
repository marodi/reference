#ifndef FAMILY_HPP
#define FAMILY_HPP
#include "film.hpp"
#include <ctype.h>

class Family : public Film{
    int ageLimit;
public:
    Family(String title, int duration, int rY, int aL);

    Family(const Family& f);

    Family& operator=(const Family& f);

    const int getAgeLimit() const;

    void setAgeLimit(const int aL);

    String toString() const;
    
    void modify(String* sa);

    ~Family();
};

#endif
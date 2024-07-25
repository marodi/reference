#include "family.hpp"

Family::Family(String title, int duration, int rY, int aL):Film(title, duration, rY){
    this->ageLimit = aL;
}

Family::Family(const Family& f):Film(f){
    this->ageLimit = f.getAgeLimit();
}

Family& Family::operator=(const Family& f){
    if(this == &f){
        return *this;
    }
    this->Film::operator=(f);
    this->ageLimit = f.getAgeLimit();
    return *this;
}

const int Family::getAgeLimit() const{
    return this->ageLimit;
}

void Family::setAgeLimit(const int aL){
    this->ageLimit = aL;
}

String Family::toString() const{
    String res = this->Film::toString() + ';';
    res += Converters::intToString(this->ageLimit);
    return res;
}

void Family::modify(String* sa){
    if((sa[3].length() == 0 && sa[4].length() > 0) || (sa[3].length() == 0 && sa[4].length() == 0)){
        throw "A film kategoriaja nem valtoztathato meg.";
    }
    this->Film::modify(sa);
    try{
        this->ageLimit = Converters::stringToInt(sa[3]);
    }catch(const char* e){
        throw e;
    }
}

Family::~Family(){}
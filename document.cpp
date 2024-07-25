#include "document.hpp"

Document::Document(String title, int duration, int rY, String description):Film(title, duration, rY), description(description){}

Document::Document(const Document& d):Film(d), description(d.getDescription()){}

Document& Document::operator=(const Document& d){
    if(this == &d){
        return *this;
    }
    this->Film::operator=(d);
    this->description = d.getDescription();
    return *this;
}

const String& Document::getDescription() const{
    return this->description;
}

void Document::setDescription(const String& s){
    this->description = s;
}

String Document::toString() const{
    String res = this->Film::toString() + ";;";
    res += this->description;
    return res;
}

void Document::modify(String* sa){
    if((sa[3].length() > 0 && sa[4].length() == 0) || (sa[3].length() == 0 && sa[4].length() == 0)){
        throw "A film kategoriaja nem valtoztathato meg.";
    }
    this->Film::modify(sa);
    this->description = sa[4];
}

Document::~Document(){}
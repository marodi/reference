#include "film.hpp"

Film::Film(String title, int duration, int rY):title(title){
    this->duration = duration;
    this->releaseYear = rY;
}

Film::Film(const Film& f):title(f.getTitle()){
    this->duration = f.getDuration();
    this->releaseYear = f.getReleaseYear();
}

Film& Film::operator=(const Film& f){
    if(this == &f){
        return *this;
    }
    this->title = f.getTitle();
    this->duration = f.getDuration();
    this->releaseYear = f.getReleaseYear();
    return *this;
}

const String& Film::getTitle() const{
    return this->title;
}

const int Film::getDuration() const {
    return this->duration;
}

const int Film::getReleaseYear() const{
    return this->releaseYear;
}

void Film::setTitle(const String& t){
    this->title = t;
}

void Film::setDuration(const int t){
    this->duration = t;
}

void Film::setReleaseYear(const int t){
    this->releaseYear = t;
}

String Film::toString() const{
    String res;
    res += this->title + ';' + Converters::intToString(this->duration) + ';' +  Converters::intToString(this->releaseYear);
    return res;
}

void Film::modify(String* sa){
    this->title = sa[0];
    this->duration = Converters::stringToInt(sa[1]);
    this->releaseYear = Converters::stringToInt(sa[2]);
}

Film::~Film(){}
#include "string.hpp"

String::String(const char* ch){
    this->size = strlen(ch);
    this->p = new char[this->size+1];
    strcpy(this->p, ch);
}

String::String(const char ch){
    this->size = 1;
    this->p = new char[this->size+1];
    this->p[0] = ch;
    this->p[1] = '\0';
}

String::String(const String& s){
    this->size = s.length();
    this->p = new char[this->size+1];
    strcpy(this->p, s.cStr());
}

const int String::length() const{
    return this->size;
}

const char* String::cStr() const{
    return this->p;
}

String& String::operator=(const String& s){
    if(this == &s){
        return *this;
    }
    this->size = s.length();
    delete this->p;
    this->p = new char[this->size+1];
    strcpy(this->p, s.cStr());
    return *this;
}

String& String::operator=(const char* ch){
    this->size = strlen(ch);
    delete this->p;
    this->p = new char[this->size+1];
    strcpy(this->p, ch);
    return *this;
}

String& String::operator=(const char ch){
    this->size = 1;
    delete this->p;
    this->p = new char[this->size+1];
    this->p[0] = ch;
    this->p[1] = '\0';
    return *this;
}

String String::operator+(const char* ch) const{
    int newSize = this->size + strlen(ch)+1;
    char* temp = new char[newSize];
    strcpy(temp, this->p);
    strcat(temp, ch);
    String res(temp);
    delete[] temp;
    return res;
}

String String::operator+(const char ch) const{
    int newSize = this->size + 2;
    char* temp = new char[newSize];
    strcpy(temp, this->p);
    temp[newSize-2] = ch;
    temp[newSize-1] = '\0';
    String res(temp);
    delete[] temp;
    return res;
}

String String::operator+(const String& s) const{
    int newSize = this->size + strlen(s.cStr())+1;
    char* temp = new char[newSize];
    strcpy(temp, this->p);
    strcat(temp, s.cStr());
    String res(temp);
    delete[] temp;
    return res;
}

void String::operator+=(const char* ch){
    this->size += strlen(ch);
    char* temp = new char[this->size+1];
    strcpy(temp, this->p);
    strcat(temp, ch);
    delete[] this->p;
    this->p = temp;
}

void String::operator+=(const char c){
    this->size += 1;
    char* temp = new char[this->size+1];
    strcpy(temp, this->p);
    temp[this->size-1] = c;
    temp[this->size] = '\0';
    delete[] this->p;
    this->p = temp;
}

void String::operator+=(const String& s){
    this->size += s.length();
    char* temp = new char[this->size+1];
    strcpy(temp, this->p);
    strcat(temp, s.cStr());
    delete[] this->p;
    this->p = temp;
}

void String::demolish(){
    delete[] this->p;
    this->p = NULL;
}

const char String::operator[](const int i) const{
    if(i < 0 || i > this->size-1){
        throw std::out_of_range("String indexhiba");
    }
    return this->p[i];
}

char& String::operator[](const int i){
    if(i < 0 || i > this->size-1){
        throw std::out_of_range("String indexhiba");
    }
    return this->p[i];
}

String* String::split(const char ch) const{
    int len = 2;
    for (int i = 0; this->p[i] != '\0'; i++){
        if(this->p[i] == ch){
            len++;
        }
    }
    String* res = new String[len];
    int index = 0;
    for (int i = 0; this->p[i] != '\0'; i++){
        if(this->p[i] != ch){
            res[index] += this->p[i];
        }else{
            index++;
        }
    }
    res[len-1].demolish();
    return res;
}

const bool String::equals(const char* ch) const{
    return strcmp(this->p, ch) == 0;
}

const bool String::equals(const String& s) const{
    return strcmp(this->p, s.cStr()) == 0;
}

String::~String(){
    if(this->p != NULL){
        delete[] this->p;
    }
};

String operator+(const char* ch, const String& s){
    return String(ch) + String(s);
}

String operator+(const char ch, const String& s){
    return String(ch) + String(s);
}

std::ostream& operator<<(std::ostream& os, const String& s){
    return os << s.cStr();
}
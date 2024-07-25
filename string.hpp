#ifndef STRING_H
#define STRING_H
#include <string.h>
#include <iostream>
#include <stdexcept>

class String{
    char* p;
    size_t size;
public:
    String(const char* ch = "");

    String(const char ch);

    String(const String& s);

    String& operator=(const String& s);

    String& operator=(const char* ch);

    String& operator=(const char ch);

    String operator+(const char* ch) const;

    String operator+(const char ch) const;

    String operator+(const String& s) const;

    void operator+=(const char* ch);

    void operator+=(const char c);

    void operator+=(const String& s);

    const char operator[](const int i) const;

    char& operator[](const int i);

    void demolish();

    const int length() const;

    const char* cStr() const;

    String* split(const char ch) const;

    const bool equals(const char* ch) const;

    const bool equals(const String& s) const; 

    ~String();
};

String operator+(const char* ch, const String& s);

String operator+(const char ch, const String& s);

std::ostream& operator<<(std::ostream& os, const String& s);

#endif
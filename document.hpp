#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP
#include "film.hpp"

class Document : public Film{
    String description;
public:
    Document(String title, int duration, int ry, String description);
    
    Document(const Document& d);

    Document& operator=(const Document& d);

    const String& getDescription() const;

    void setDescription(const String& s);

    String toString() const;

    void modify(String* sa);

    ~Document();
};

#endif
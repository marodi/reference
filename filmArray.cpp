#include "filmArray.hpp"

FilmArray::FilmArray(){
    this->arr = NULL;
    this->size = 0;
}

void FilmArray::add(Film* f){
    Film** newArr = new Film*[this->size+1];
    int index = 0;
    for (int i = 0; i < this->size; i++){
        newArr[index++] = this->arr[i];
    }
    newArr[index] = f;
    if(this->arr != NULL){
        delete[] this->arr;
    }
    this->arr = newArr;
    this->size++;
}

void FilmArray::remove(const int i){
    if(i < 0 || i > this->size-1){
        throw std::out_of_range("FilmArray torles");
    }
    if(this->size-1 > 0){
        Film** newArr = new Film*[this->size-1];
        int index = 0;
        for (int j = 0; j < this->size; j++){
            if(j != i){
                newArr[index++] = this->arr[j];
            }
        }
        delete[] this->arr;
        this->arr = newArr;
    }
    if(this->size-1 == 0){
        delete this->arr;
        this->arr = NULL;
    }
    this->size--;
}

const Film* FilmArray::operator[](const int i) const{
    if(i < 0 || i > this->size-1){
        throw std::out_of_range("FilmArray lekerdezes const");
    }
    return this->arr[i];
}

Film* FilmArray::operator[](const int i){
    if(i < 0 || i > this->size-1){
        throw std::out_of_range("FilmArray lekerdezes");
    }
    return this->arr[i];
}

const int FilmArray::indexOf(const String& s){
    int index = -1;
    for (int i = 0; i < this->size && index < 0; i++){
        if(this->arr[i]->getTitle().equals(s)){
            index = i;
        }
    }
    return index;
}

const int FilmArray::length(){
    return this->size;
}

FilmArray::~FilmArray(){
    if(this->arr != NULL){
        delete[] this->arr;
    }
}
#include "ui.hpp"

void Interface::clear(){
    //system("cls");
}

void Interface::writeOptions(const String* names, const int* en){
    for (int i = 0; en[i] != -1; i++){
        std::cout << "(" << i << ") " << names[en[i]] << std::endl;
    }
}

int Interface::getOption(const int* en){
    String input;
    int num = 0;
    int leng = 0;
    for (int i = 0; en[i] != -1; i++){
        leng++;
    }
    bool failed = false;
    do{
        try{
            input = getString();
            num = Converters::stringToInt(input);
            failed = false;
        }catch(const char* e){    
            std::cout << "Szamot adj meg!" << std::endl;
            failed = true;
        }
        if(num < 0 || num >= leng){
            std::cout << "0-tol " << leng-1 <<"-ig adj meg szamot!" << std::endl;
            failed = true;
        }
    }while(failed);
    return en[num];
}

void Interface::writeString(const String& s){
    std::cout << s;
}

const String Interface::getString(){
    String res;
    bool firstBreak = true;
    char c;
    c = getchar();
    while(c != '\n' || firstBreak){
        if(c != '\n'){
            res += c;
        }
        c = getchar();
        firstBreak = false;
    }
    return res;
}

void Interface::pause(){
    getchar();
}

void writeChars(const char c, const int n){
    for (int i = 0; i < n; i++){
        std::cout << c;
    }
}

int max(int a, int b){
    return a > b ? a : b;
}

void Interface::writeMovie(Film* f){
    String fields[] = {"Cim", "Idotartam (perc)", "Kiadas eve", "Korhatar", "Leiras"};
    String* values = f->toString().split(';');
    std::cout << '+';
    for (int i = 0; values[i].cStr() != NULL; i++){
        if(values[i].length() > 0){
            writeChars('-', max(values[i].length(), fields[i].length()));
            std::cout << '+';
        }
    }
    std::cout << "\n|";
    for (int i = 0; values[i].cStr() != NULL; i++){
        if(values[i].length() > 0){
            std::cout << fields[i];
            writeChars(' ', max(values[i].length(), fields[i].length()) - fields[i].length());
            std::cout << '|';
        }
    }
    std::cout << std::endl;
    std::cout << '+';
    for (int i = 0; values[i].cStr() != NULL; i++){
        if(values[i].length() > 0){
            writeChars('-', max(values[i].length(), fields[i].length()));
            std::cout << '+';
        }
    }
    std::cout << "\n|";
    for (int i = 0; values[i].cStr() != NULL; i++){
        if(values[i].length() > 0){
            std::cout << values[i];
            writeChars(' ', max(values[i].length(), fields[i].length()) - values[i].length());
            std::cout << '|';
        }
    }
    std::cout << std::endl;
    std::cout << '+';
    for (int i = 0; values[i].cStr() != NULL; i++){
        if(values[i].length() > 0){
            writeChars('-', max(values[i].length(), fields[i].length()));
            std::cout << '+';
        }
    }
    delete[] values;
}
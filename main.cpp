#include <iostream>
#include <stdexcept>
#include "string.hpp"
#include "filmArray.hpp"
#include "document.hpp"
#include "family.hpp"
#include "file.hpp"
#include "ui.hpp"
#include "converters.hpp"

#include "gtest_lite.h"

int main(){
    try{
        FilmArray movies;
        String filePath = "db.txt";
        FileHandling::readInput(filePath, movies);
        //                      0           1           2         3           4                  5                      6               7     8
        String options[] = {"Kilepes", "Hozzaadas", "Torles", "Kereses", "Modositas", "Kilepes megerositese", "Torles megerositese", "Megse", ""};
        int actualMenu = 8;
        int optionsEnabled[9];
        while(actualMenu != 5){
            int indexToDelete = 0;
            if(actualMenu == 8){//Fomenu
                if(movies.length() == 0){
                    optionsEnabled[0] = 0;
                    optionsEnabled[1] = 1;
                    optionsEnabled[2] = -1;
                }else{
                    for (size_t i = 0; i < 5; i++){
                        optionsEnabled[i] = i;
                    }
                    optionsEnabled[5] = -1;
                }
                Interface::clear();
                Interface::writeOptions(options, optionsEnabled);
                actualMenu = Interface::getOption(optionsEnabled);
            }
            if(actualMenu == 0){//Kilepes
                optionsEnabled[0] = 7;
                optionsEnabled[1] = 5;
                optionsEnabled[2] = -1;
                Interface::clear();
                Interface::writeOptions(options, optionsEnabled);
                actualMenu = Interface::getOption(optionsEnabled);
            }
            if(actualMenu == 1){//Hozzaadas
                optionsEnabled[1] = -1;
                Interface::clear();
                
                Interface::writeString("cim;lejtszasi ido;kiadas eve;[korhatar];[szoveges leiras]\n");
                String input = Interface::getString();
                if(input.equals("")){
                    actualMenu = 8;
                }else{
                    String* params = input.split(';');
                    if(params[0].length() >0 && params[1].length() >0 && params[2].length() >0 && params[3].length() == 0 && params[4].length() == 0 ){
                        movies.add(new Film(params[0],Converters::stringToInt(params[1]),Converters::stringToInt(params[2])));
                    }else if(params[0].length() >0 && params[1].length() >0 && params[2].length() >0 && params[3].length() > 0 && params[4].length() == 0 ){
                        movies.add(new Family(params[0],Converters::stringToInt(params[1]),Converters::stringToInt(params[2]),Converters::stringToInt(params[3])));
                    }else if(params[0].length() >0 && params[1].length() >0 && params[2].length() >0 && params[3].length() == 0 && params[4].length() > 0 ){
                        movies.add(new Document(params[0],Converters::stringToInt(params[1]),Converters::stringToInt(params[2]),params[4]));
                    }else{
                        Interface::writeString("A megadott adatok nem sorolhatoak ba egy kategoriaba sem.");
                        Interface::pause();
                    }
                    delete[] params;
                }
                
                actualMenu = 8;
            }
            if(actualMenu == 2){//Torles
                optionsEnabled[0] = -1;
                Interface::clear();
                String title;
                title = Interface::getString();
                indexToDelete = movies.indexOf(title);
                if(indexToDelete == -1){
                    Interface::writeString("Nincs talalat.");
                    Interface::pause();
                    actualMenu = 8;
                }else{
                    actualMenu = 6;
                }
            }
            if(actualMenu == 3){//Kereses
                optionsEnabled[0] = -1;
                Interface::clear();
                String title;
                title = Interface::getString();
                if(movies.indexOf(title) > -1){
                    Interface::writeMovie(movies[movies.indexOf(title)]);
                }else{
                    Interface::writeString("A film nem talalhato.\n");
                }
                Interface::pause();
                actualMenu = 8;
            }
            if(actualMenu == 4){//Modositas
                optionsEnabled[0] = -1;
                Interface::clear();
                try{
                    String title = Interface::getString();
                    Film* filmToModify = movies[movies.indexOf(title)];
                    String fields[] = {"cim", "ido", "kiadas", "korhatar", "leiras"};
                    Interface::writeString("Valaszthato mezok: \n");
                    for (int i = 0; i < 5; i++){
                        Interface::writeString(fields[i]+" ");
                    }
                    Interface::writeString("\n");

                    String input = Interface::getString();
                    String* params = input.split(';');
                    String* newParameters = filmToModify->toString().split(';');
                    int indexOfParameter = -1;
                    for (int i = 0; i < 5; i++){
                        if(fields[i].equals(params[0])){
                            indexOfParameter = i;
                        }
                    }
                    if(indexOfParameter == -1){
                        Interface::writeString("A mezo nem talalhato.\n");
                    }else{
                        newParameters[indexOfParameter] = params[1];
                    }

                    filmToModify->modify(newParameters);
                    
                    delete[] params;
                    delete[] newParameters;
                }catch(const char* e){
                    Interface::writeString(e + '\n');
                }catch(std::out_of_range& e){
                    if(strcmp(e.what(), "FilmArray lekerdezes") == 0){
                        Interface::writeString("A film nem talalhato.\n");
                    }else{
                        Interface::writeString("Hiba.\n");
                    }
                }catch(std::exception& e){
                    Interface::writeString(e.what()+'\n');
                }
                actualMenu = 8;
            }
            if(actualMenu == 5){//Kilepes megerositese
                FileHandling::saveFilmArray(filePath, movies);
            }
            if(actualMenu == 6){//Torles megerositese
                optionsEnabled[0] = 7;
                optionsEnabled[1] = 6;
                optionsEnabled[2] = -1;
                Interface::clear();
                Interface::writeOptions(options, optionsEnabled);
                int choice;
                choice = Interface::getOption(optionsEnabled);
                if(choice == 6){
                    movies.remove(indexToDelete);
                }
                actualMenu = 8;
            }
            if(actualMenu == 7){//Megse
                actualMenu = 8;
            }
        }
    }catch(const char* e){
        Interface::writeString("Ismeretlen hiba: ");
        Interface::writeString(e + '\n');
    }catch(std::out_of_range& e){
        Interface::writeString("Ismeretlen hiba: ");
        Interface::writeString(e.what() + '\n');
    }catch(std::exception& e){
        Interface::writeString("Ismeretlen hiba: ");
        Interface::writeString(e.what() + '\n');
    }
    return 0;
}
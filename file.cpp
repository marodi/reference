#include "file.hpp"

const String readLine(std::ifstream& is){
    std::string line;
    std::getline(is, line); 
    return String(line.c_str());
}

void FileHandling::readInput(const String& src, FilmArray& dest){
    std::ifstream input(src.cStr());
    String row = readLine(input);
    while(row.length() > 0){
        String* params = row.split(';');
        if(params[0].length() >0 && params[1].length() >0 && params[2].length() >0 && params[3].length() == 0 && params[4].length() == 0 ){
            dest.add(new Film(params[0],Converters::stringToInt(params[1]),Converters::stringToInt(params[2])));
        }else if(params[0].length() >0 && params[1].length() >0 && params[2].length() >0 && params[3].length() > 0 && params[4].length() == 0 ){
            dest.add(new Family(params[0],Converters::stringToInt(params[1]),Converters::stringToInt(params[2]),Converters::stringToInt(params[3])));
        }else if(params[0].length() >0 && params[1].length() >0 && params[2].length() >0 && params[3].length() == 0 && params[4].length() > 0 ){
            dest.add(new Document(params[0],Converters::stringToInt(params[1]),Converters::stringToInt(params[2]),params[4]));
        }
        delete[] params;
        row = readLine(input);
    }
    input.close();
}


void FileHandling::saveFilmArray(const String& dest, FilmArray& src){
    String outString;
    for (int i = 0; i < src.length(); i++){
        if(i != 0){
            outString += '\n';
        }
        String curr = src[i]->toString();
        outString += curr;
        int numOfSeps = 0;
        for (int j = 0; j < curr.length(); j++){
            if(curr[j] == ';'){
                numOfSeps++;
            }
        }
        for (int j = 0; j < 4 - numOfSeps; j++){
            outString += ';';
        }
    }
    std::ofstream output(dest.cStr());
    output << outString;
    output.close();
}
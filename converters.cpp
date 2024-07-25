#include "converters.hpp"

int Converters::stringToInt(const String& s){
    char nums[] = "0123456789";
    for (int i = 0; i < s.length(); i++){
        bool contains = false;
        for (int j = 0; j < strlen(nums) && !contains; j++){
            if(nums[j] == s[i]){
                contains = true;
            }
        }
        if(!contains){
            throw "toInt formatumhiba";
        }
    }
    int res = 0;
    int mul = 1;
    int leng = s.length()-1;
    while(leng > 0){
        mul *= 10;
        leng--;
    }
    for (int i = 0; i < s.length(); i++){
        res += (s[i]-48)*mul;
        mul /= 10;
    }
    return res;
}

const String Converters::intToString(const int num){
    String res;
    int div = 1;
    while(num / div > 0){
        div *= 10;
    }
    div /= 10;
    int victNum = num;
    while(div > 0){
        res += (victNum / div)+48;
        victNum %= div;
        div /= 10;
    }
    if(num == 0){
        res += 48;
    }
    return res;
}
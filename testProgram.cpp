#include <iostream>
#include <sstream>
#include <stdexcept>
#include "string.hpp"
#include "filmArray.hpp"
#include "document.hpp"
#include "family.hpp"
#include "file.hpp"
#include "ui.hpp"
#include "converters.hpp"

#include "gtest_lite.h"
#include "memtrace.h"

int mainm(){
    FilmArray array;
    array.add(new Film("Capahurrikan", 76, 2017));
    array.add(new Family("Dragam a kolykok osszementek!", 114, 2002, 18));
    array.add(new Document("Husvet-szigetek", 60, 2020, "A husve-szigeteki szobrokat talan az idegenek keszitettek?"));
    array.remove(1);
    TEST(Memoriaszivargas, filmArray){
        //memtrace::mem_dump(array, array.length(), stdout);
    }ENDM

    return 0;
}
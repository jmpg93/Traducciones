//
//  tIdioma.cpp
//  Traducciones
//
//  Created by Jose Maria Puerta on 26/04/14.
//  Copyright (c) 2014 Jose Maria Puerta. All rights reserved.
//

#include "tIdioma.h"

tIdioma::tIdioma(){
    lengua = "";
}
tIdioma::~tIdioma(){
   lengua = "";
}

void tIdioma::ponLengua(string len){
    lengua = len;
}

string tIdioma::dameLengua(){
    return lengua;
}

bool tIdioma::comparaIdioma(tIdioma idiomas){  
    return lengua == idiomas.dameLengua();
}
void tIdioma::leerIdioma(){
    cin >> lengua;
}
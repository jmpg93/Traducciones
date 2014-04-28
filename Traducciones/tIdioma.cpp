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

void tIdioma::ponLengua(string len){
    lengua = len;
}

string tIdioma::dameLengua(){
    return lengua;
}

bool tIdioma::comparaIdioma(tIdioma * idiomas){
    bool resul = false;
    int i = 0;
    
    while (idiomas[i].dameLengua()!="") {
        if (lengua == idiomas[i].dameLengua()) {
            resul = true;
        }
    }
    
    return resul;
}
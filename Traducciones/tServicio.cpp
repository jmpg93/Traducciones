//
//  tServicio.cpp
//  Traducciones
//
//  Created by Jose Maria Puerta on 26/04/14.
//  Copyright (c) 2014 Jose Maria Puerta. All rights reserved.
//

#include "tServicio.h"
tServicio::tServicio(tTraductor * tradu, tIdioma iO, tIdioma iD){
    traductor = tradu;
    idiomaDestino = iD;
    idiomaOrigen = iO;
}
tServicio::tServicio(){
    traductor = NULL;
    idiomaDestino = *new tIdioma();
    idiomaOrigen = *new tIdioma();
}

tServicio::~tServicio(){
    traductor = NULL;
}

void tServicio::muestraServicio(){
    
    cout << "=============================" << endl;
    cout << "Idioma origen: " << idiomaOrigen.dameLengua() << endl;
    cout << "Idioma destino: " << idiomaDestino.dameLengua() << endl << endl;
    cout << "Traductores implicados: " << endl;
    traductor->muestraTraductores();
    cout << "=============================" << endl;
    cout << endl;
}


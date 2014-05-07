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
void tServicio::muestraServicio(){
    for (int i = 0; i < traductor->dameTraductores() ; i++) {
        
    }
}
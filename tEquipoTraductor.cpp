//
//  tEquipoTraductor.cpp
//  Traducciones
//
//  Created by Jose Maria Puerta on 26/04/14.
//  Copyright (c) 2014 Jose Maria Puerta. All rights reserved.
//

#include "tEquipoTraductor.h"

tEquipoTraductor::tEquipoTraductor(){
    numIntegrantes = 0;
    equitoTraductor[0] = new tTraductor();
}

void tEquipoTraductor::aniadeTraductor(tTraductor *tradu){
    equitoTraductor[numIntegrantes] = tradu;
    numIntegrantes++;
}
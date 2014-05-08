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
    equitoTraductor[0] = new tEmpleado();
}

void tEquipoTraductor::aniadeTraductor(tEmpleado *tradu){
    tradu->ocupaTraductor();
    equitoTraductor[numIntegrantes] = tradu;
    numIntegrantes++;
}

bool tEquipoTraductor::comparaIdiomasEquipoOrigenDestino(){
    bool enc = false;
    enc = equitoTraductor[0]->comparaIdiomasDeEmpleados(equitoTraductor[1]);
    return enc;
}
tEmpleado * tEquipoTraductor::dameIntegrante(int pos){
    return equitoTraductor[pos];
}
int tEquipoTraductor::dameIntegrantes(){
    return numIntegrantes;
}

int tEquipoTraductor::numeroTraductores(){
    return numIntegrantes;
}

void tEquipoTraductor::muestraTraductores(){
    for (int i = 0; i < numIntegrantes; i++) {
        equitoTraductor[i]->muestraTraductores();
    }
}

bool tEquipoTraductor::dameServicio(){
    return true;
}

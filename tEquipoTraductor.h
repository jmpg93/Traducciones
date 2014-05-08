//
//  tEquipoTraductor.h
//  Traducciones
//
//  Created by Jose Maria Puerta on 26/04/14.
//  Copyright (c) 2014 Jose Maria Puerta. All rights reserved.
//

#ifndef __Traducciones__tEquipoTraductor__
#define __Traducciones__tEquipoTraductor__

#include <iostream>

#include "tTraductor.h"
#include "tEmpleado.h"

class tEquipoTraductor: public tTraductor{
public:
    void aniadeTraductor(tEmpleado *tradu);
    tEquipoTraductor();
    
    bool comparaIdiomasEquipoOrigenDestino();
    
    int dameIntegrantes();
    
    tEmpleado * dameIntegrante(int);
    
    int numeroTraductores();
    void muestraTraductores();
    
    bool dameServicio();
    
private:
    tEmpleado * equitoTraductor[3];
    int numIntegrantes;
};
#endif /* defined(__Traducciones__tEquipoTraductor__) */

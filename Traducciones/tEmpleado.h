//
//  tEmpleado.h
//  Traducciones
//
//  Created by Jose Maria Puerta on 26/04/14.
//  Copyright (c) 2014 Jose Maria Puerta. All rights reserved.
//

#ifndef __Traducciones__tEmpleado__
#define __Traducciones__tEmpleado__

#include <iostream>
#include <string>

#include "tTraductor.h"
#include "tIdioma.h"

using namespace std;

class tEmpleado: public tTraductor{
public:
    tEmpleado();
        
    void ponNombre();
    string dameNombre();
    
    void ponIdiomas();
    tIdioma * dameIdiomas();
    
    void aniadeEmpleado();
    
         
private:
    tIdioma * idiomas[5];
    string nombre;
    string apellido;
};

#endif /* defined(__Traducciones__tEmpleado__) */

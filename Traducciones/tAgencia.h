//
//  tAgencia.h
//  Traducciones
//
//  Created by Jose Maria Puerta on 26/04/14.
//  Copyright (c) 2014 Jose Maria Puerta. All rights reserved.
//

#ifndef __Traducciones__tAgencia__
#define __Traducciones__tAgencia__

#include <iostream>
#include <fstream>

#include "tEmpleado.h"
#include "tServicio.h"

class tAgencia{
public:
    tAgencia();
    void muestraMenu();
    
    void gestionaEmpleados();
    void gestionarServicios();
    
private:
    tEmpleado * empleados[100];
    tServicio * servicios[10];
};

#endif /* defined(__Traducciones__tAgencia__) */

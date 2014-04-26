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
private:
    tEmpleado equitoTraductor[3];
};
#endif /* defined(__Traducciones__tEquipoTraductor__) */

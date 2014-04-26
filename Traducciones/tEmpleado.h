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

#include "tTraductor.h"
#include "tIdioma.h"

class tEmpleado: public tTraductor{
public:
private:
    tIdioma idiomas[5];
    
};
#endif /* defined(__Traducciones__tEmpleado__) */

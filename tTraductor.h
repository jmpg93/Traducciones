//
//  tTraductor.h
//  Traducciones
//
//  Created by Jose Maria Puerta on 26/04/14.
//  Copyright (c) 2014 Jose Maria Puerta. All rights reserved.
//

#ifndef __Traducciones__tTraductor__
#define __Traducciones__tTraductor__

#include "tIdioma.h"

#include <iostream>

class tTraductor{
public:
    tTraductor();
    void ocupaTraductor();
    void liberaTraductor();
    bool dameServicio();
    
    virtual int numeroTraductores() = 0;
    virtual void muestraTraductores() = 0;
    
private:
    bool enServicio;
    

};
#endif /* defined(__Traducciones__tTraductor__) */

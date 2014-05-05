//
//  tServicio.h
//  Traducciones
//
//  Created by Jose Maria Puerta on 26/04/14.
//  Copyright (c) 2014 Jose Maria Puerta. All rights reserved.
//

#ifndef __Traducciones__tServicio__
#define __Traducciones__tServicio__

#include <iostream>

#include "tTraductor.h"
#include "tIdioma.h"

class tServicio{
public:
    tServicio(tTraductor * traduc, tIdioma iO, tIdioma iD);
private:
    tTraductor * traductor;
    
    tIdioma idiomaOrigen;
    tIdioma idiomaDestino;
};
#endif /* defined(__Traducciones__tServicio__) */

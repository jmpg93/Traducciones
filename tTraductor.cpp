//
//  tTraductor.cpp
//  Traducciones
//
//  Created by Jose Maria Puerta on 26/04/14.
//  Copyright (c) 2014 Jose Maria Puerta. All rights reserved.
//

#include "tTraductor.h"

tTraductor::tTraductor(){
    enServicio = false;
}

void tTraductor::liberaTraductor(){
    enServicio = false;
}
void tTraductor::ocupaTraductor(){
    enServicio = true;
}

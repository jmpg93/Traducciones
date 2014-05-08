//
//  tIdioma.h
//  Traducciones
//
//  Created by Jose Maria Puerta on 26/04/14.
//  Copyright (c) 2014 Jose Maria Puerta. All rights reserved.
//

#ifndef __Traducciones__tIdioma__
#define __Traducciones__tIdioma__

#include <iostream>

using namespace std;

class tIdioma{
public:
    
    tIdioma();
    ~tIdioma();
    
    string dameLengua();
    void ponLengua(string);
    
    bool comparaIdioma(tIdioma);
    void leerIdioma();
    
private:
    string lengua;

};
#endif /* defined(__Traducciones__tIdioma__) */

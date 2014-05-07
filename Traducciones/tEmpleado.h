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
        
    void ponNombre(string);
    string dameNombre();
    
    void ponIdiomas();
    tIdioma * dameIdioma(int);
    int dameIdiomasHablados();
    
    void aniadeEmpleado();
    void cargaEmpleado(string);
    void mostrarEmpleado();
    
    bool tieneIdioma(tIdioma);
    bool comparaIdiomasDeEmpleados(tEmpleado *);
    
    int numeroTraductores();
    
    void muestraTraductores();
         
private:
    tIdioma * idiomas[5];
    string nombre;
    string apellido;
    int idiomasHablados;
};

#endif /* defined(__Traducciones__tEmpleado__) */

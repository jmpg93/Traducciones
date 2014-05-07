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
#include "tEquipoTraductor.h"

class tAgencia{
public:
    tAgencia();
    void muestraMenu();
    
    void gestionaEmpleados();
    void gestionarServicios();
    
    void contratarEmpleado();
    void despedirEmpleado();
    void mostrarEmpleados();
    
    bool guardaListaEmpleados();
    void borraEmpleado(string, string);
    
    bool buscaTraductor(tIdioma, tIdioma);
    bool buscaEquipoTraductor(tIdioma, tIdioma);
    
    bool contrataServicio(tTraductor*, tIdioma, tIdioma);
    void contrataServicio();
    
    bool rescindirServicio();
    void mostrarServicios();
    
    tEmpleado * buscaUltimoEmpleado(tEquipoTraductor *);

    
private:
    tEmpleado * empleados[100];
    tServicio * servicios[10];
    
    int numeroEmpleados;
    int numeroServicios;
};

#endif /* defined(__Traducciones__tAgencia__) */

//
//  tAgencia.cpp
//  Traducciones
//
//  Created by Jose Maria Puerta on 26/04/14.
//  Copyright (c) 2014 Jose Maria Puerta. All rights reserved.
//
#include <stdlib.h>

#include "tAgencia.h"

using namespace::std;

void tAgencia::muestraMenu(){
    int opcion;
    cout << "Bienvenido al sistema de traducciones" << endl;
    
    cout << "1. Gestionar empleados" << endl;
    cout << "" << endl;
    cout << "2. Gestionar servicios" << endl;
    
    cin >> opcion;
    
    switch (opcion) {
        case 1:
            gestionaEmpleados();
            break;
        case 2:
            gestionarServicios();
            break;
        default:
            break;
    }
    
}

void tAgencia::gestionaEmpleados(){
    system("CLS");
    
    int opcion;
    cout << "Gestionando empleados" << endl;
    
    cout << "1. Contratar empleado" << endl;
    cout << "2. Despedir empleadoss" << endl;
    cout << "3. Mostrar empleados" << endl;
    
    cin >> opcion;
    
    switch (opcion) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
            
        default:
            break;
    }
}
void tAgencia::gestionarServicios(){
    system("CLS");
    
    int opcion;
    cout << "Gestionando servicios" << endl;
    
    cout << "1. Contratar servicio" << endl;
    cout << "2. Rescindir servicio" << endl;
    cout << "3. Mostrar servicios activos" << endl;
    
    cin >> opcion;
    
    switch (opcion) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
            
        default:
            break;
    }
}
//
//  tAgencia.cpp
//  Traducciones
//
//  Created by Jose Maria Puerta on 26/04/14.
//  Copyright (c) 2014 Jose Maria Puerta. All rights reserved.
//
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iostream>
#include <stdio.h>

#include "tAgencia.h"

using namespace::std;

tAgencia::tAgencia(){

    ifstream infile;
    infile.open ("empleados.txt");
    numeroEmpleados = 0;
    string linea;
    if (infile.is_open())
    {
        while (getline(infile, linea)) {
            numeroEmpleados++;
        }
        
        
        cout << linea;
        infile.close();
    }
    
    
}

void tAgencia::muestraMenu(){
    int opcion;
    cout << "Bienvenido al sistema de traducciones" << endl;
    
    cout << "1. Gestionar empleados" << endl;
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
    //system("cls");
    //system("clear");
    //clrscr();
    
    int opcion;
    cout << "Gestionando empleados" << endl;
    
    cout << "1. Contratar empleado" << endl;
    cout << "2. Despedir empleadoss" << endl;
    cout << "3. Mostrar empleados" << endl;
    
    cin >> opcion;
    
    switch (opcion) {
        case 1:
            contratarEmpleado();
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
void tAgencia::contratarEmpleado(){

    if (empleados[numeroEmpleados] == NULL) {
        empleados[numeroEmpleados] = new tEmpleado();
    }
    empleados[numeroEmpleados]->aniadeEmpleado();
    numeroEmpleados++;
    if(guardaListaEmpleados()){
        cout << "Empleado contratado correctamente" << endl;
    }else cout << "Error contratando" << endl;
}


bool tAgencia::guardaListaEmpleados(){
    bool resul = true;
    
    fstream ficheroSalida;
    
    
    ficheroSalida.open ("empleados.txt", ios::out);
    
    if (ficheroSalida.is_open()) {
        for (int i = 0; i < numeroEmpleados; i++) {
            
            ficheroSalida << empleados[i]->dameNombre() << " ";
            tIdioma *idiomas = empleados[i]->dameIdiomas();
            
            for (int j = 0; j < empleados[i]->dameIdiomasHablados();j++) {
                
                ficheroSalida << idiomas[j].dameLengua();
            }
        }
        
        ficheroSalida.close();
    }
    else resul = false;
    
    
    for (int i = 0; i < numeroEmpleados; i++){
        
    }
    
    return resul;
}
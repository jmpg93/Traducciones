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
#include "tIdioma.h"

using namespace::std;

tAgencia::tAgencia(){

    ifstream infile;
    infile.open ("//Users/jmpg93/Development/empleados.txt");
    numeroEmpleados = 0;
    string linea;
    if (infile.is_open())
    {
        while (getline(infile, linea)) {
            if (empleados[numeroEmpleados]==NULL) {
                empleados[numeroEmpleados] = new tEmpleado();
            }
            empleados[numeroEmpleados]->cargaEmpleado(linea);
            numeroEmpleados++;
        }
        infile.close();
    }
    
    
}

void tAgencia::muestraMenu(){
    int opcion;
    
    cout << "Bienvenido al sistema de traducciones" << endl;
    do {
        cout << "1. Gestionar empleados" << endl;
        cout << "2. Gestionar servicios" << endl;
        cout << "3. Salir" << endl;
        
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                gestionaEmpleados();
                break;
            case 2:
                gestionarServicios();
                break;
            case 3:
                break;
            default:
                break;
        }
    } while (opcion!=3);
    
}


void tAgencia::gestionaEmpleados(){
    //system("cls");
    //system("clear");
    //clrscr();
    int opcion;
    
    do {
        
        cout << "Gestionando empleados" << endl;
        
        cout << "1. Contratar empleado" << endl;
        cout << "2. Despedir empleados" << endl;
        cout << "3. Mostrar empleados" << endl;
        cout << "4. Volver" << endl;
        
        
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                contratarEmpleado();
                break;
            case 2:
                despedirEmpleado();
                break;
            case 3:
                mostrarEmpleados();
                break;
                
            default:
                break;
        }
    } while (opcion!=4);
    
    if (opcion == 4) muestraMenu();
    
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

void tAgencia::mostrarEmpleados(){
    cout << endl << "Lista de empleados actualmente contratados" << endl;
    for (int i = 0 ; i < numeroEmpleados; i++) {
        cout << i + 1 << ".   ";
        empleados[i]->mostrarEmpleado();
    }
    cout << endl;
}

void tAgencia::despedirEmpleado(){
    string nombre;
    string apellido;
    
    mostrarEmpleados();
    cout << endl << "Introduzca el nombre y apellido del empleado que va a ser despedido" << endl;
    
    cin >> nombre >> apellido;
    borraEmpleado(nombre, apellido);
    numeroEmpleados--;
    
    guardaListaEmpleados();
    
}

bool tAgencia::guardaListaEmpleados(){
    bool resul = true;
    
    fstream ficheroSalida;
    
    
    ficheroSalida.open ("/Users/jmpg93/Development/empleados.txt", ios::out);
    
    if (ficheroSalida.is_open()) {
        tIdioma * idioma = new tIdioma();
        
        for (int i = 0; i < numeroEmpleados; i++) {
            
            ficheroSalida << empleados[i]->dameNombre() << " ";
            ficheroSalida << empleados[i]->dameIdiomasHablados() << " ";
            
            
            
            for (int j = 0; j < empleados[i]->dameIdiomasHablados();j++) {
                idioma = empleados[i]->dameIdioma(j);
                ficheroSalida << idioma->dameLengua();
                ficheroSalida << " ";
            }
            ficheroSalida << endl;
        }
        
        ficheroSalida.close();
    }
    else resul = false;
    
    
    for (int i = 0; i < numeroEmpleados; i++){
        
    }
    
    return resul;
}

void tAgencia::borraEmpleado(string nom, string ap){
    tEmpleado * empleado = NULL;
    
    int i = 0;
    bool enc = false;
    
    while (i < numeroEmpleados && !enc) {
        if (empleados[i]->dameNombre() == nom + " " + ap) {
            empleado = empleados[i];
            enc = true;
        }
        i++;
    }
    
    if (empleado == NULL) cout << "No se ha encontrado el empleado" << endl;
    else cout << "Se ha borrado correctamente el empelado: " << empleado->dameNombre() << endl;
    
    i = i - 1;
    for (int j = i; j <= numeroEmpleados - i; j++) {
        empleados[j] = empleados[j+1];
    }
}

void tAgencia::buscaTraductor(tIdioma iOrigen, tIdioma iDestino){
    bool destino = false, origen = false;
    for (int i = 0; i<numeroEmpleados; i++) {
        for (int j = 0; j < empleados[i]->dameIdiomasHablados(); j++){
            tIdioma * idiomaHablado = empleados[i]->dameIdioma(j);
            
            if (iOrigen.comparaIdioma(idiomaHablado)) {
                origen = true;
            }
            
            if (iDestino.comparaIdioma(idiomaHablado)) {
                destino = true;
            }
        }
    }
}
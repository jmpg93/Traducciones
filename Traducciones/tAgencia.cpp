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
    numeroServicios = 0;
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
    
    for (int i = 0; i<10; i++) {
        servicios[i] = NULL;
    }
    
    
}

void tAgencia::muestraMenu(){
    int opcion;
    system("clear");
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
    system("clear");
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
    system("clear");
    int opcion;
    do {
        
        cout << "Gestionando servicios" << endl;
        
        cout << "1. Contratar servicio" << endl;
        cout << "2. Rescindir servicio" << endl;
        cout << "3. Mostrar servicios activos" << endl;
        cout << "4. Volver" << endl;
        
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                if(!contrataServicio()) cout << "Error contratando nuevo servicio" << endl;
                break;
            case 2:
                rescindirServicio();
                break;
            case 3:
                mostrarServicios();
                break;
            case 4:
                break;
                
            default:
                break;
        }
    } while (opcion!=4);
    
    if (opcion == 4) muestraMenu();
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

bool tAgencia::buscaTraductor(tIdioma iOrigen, tIdioma iDestino){
    
    bool destino = false, origen = false;
    bool enc = false;
    int i = 0;
    
    while (!enc && i<numeroEmpleados) {
        int j = 0;
        origen = false;
        destino = false;
        while (!enc && j < empleados[i]->dameIdiomasHablados()){
            tIdioma * idiomaHablado = empleados[i]->dameIdioma(j);
            if (!empleados[i]->dameServicio()) {
                
                origen = origen || idiomaHablado->comparaIdioma(iOrigen);
                destino = destino || idiomaHablado->comparaIdioma(iDestino);
                
                if (origen && destino) enc = contrataServicio(empleados[i], iOrigen, iDestino);
            }
            j++;
        }
        
        i++;
    }
    return enc;
}

bool tAgencia::buscaEquipoTraductor(tIdioma iOrigen, tIdioma iDestino){
    
    tEquipoTraductor * equipo = new tEquipoTraductor();
    
    bool destino = false, origen = false, comun = false;
    bool enc = false;
    int j = 0;
    
    while (!origen && j < numeroEmpleados) {
        if (!empleados[j]->dameServicio() && empleados[j]->tieneIdioma(iOrigen)){
            equipo->aniadeTraductor(empleados[j]);
            origen = true;
        }
        j++;
    }
    
    j = 0;
    while (!destino && j < numeroEmpleados) {
        if (!empleados[j]->dameServicio() && empleados[j]->tieneIdioma(iDestino)){
            equipo->aniadeTraductor(empleados[j]);
            destino = true;
        }
        j++;
    }
    if (origen && destino) {
        comun = equipo->comparaIdiomasEquipoOrigenDestino();
        if(!comun){
            tEmpleado * ultimoIntegrante = buscaUltimoEmpleado(equipo);
            if (ultimoIntegrante!=NULL) {
                comun = true;
                equipo->aniadeTraductor(ultimoIntegrante);
            }
        }
        
    }else{
        cout << "Error creando el equipo" << endl;
    }
    if (origen && destino && comun) enc = contrataServicio(equipo, iOrigen, iDestino);
    else cout << "Error creando el equipo" << endl;
    return enc;
}

bool tAgencia::contrataServicio(tTraductor * tradu, tIdioma iOrigen, tIdioma iDestino){
    bool resul = false;
    tradu->ocupaTraductor();
    servicios[numeroServicios] = new tServicio(tradu, iOrigen, iDestino);
    if (servicios[numeroServicios]!=NULL) {
        resul = true;
    }
    numeroServicios++;
    return resul;
}


tEmpleado * tAgencia::buscaUltimoEmpleado(tEquipoTraductor * equipo){
    tEmpleado * ultimoIntegrante = NULL;
    bool enc = false, empleadoIdiomaOrigen = false, empleadoIdiomaDestino = false;
    int i = 0;
    
    while (!enc && i < numeroEmpleados) {
        if (!empleados[i]->dameServicio()) {
            empleadoIdiomaOrigen= empleados[i]->comparaIdiomasDeEmpleados(equipo->dameIntegrante(0));
            empleadoIdiomaDestino = empleados[i]->comparaIdiomasDeEmpleados(equipo->dameIntegrante(1));
            if (empleadoIdiomaOrigen && empleadoIdiomaDestino) {
                ultimoIntegrante = empleados[i];
                enc = true;
            }
        }
        i++;
    }
    
    return ultimoIntegrante;
}

void tAgencia::mostrarServicios(){
    if (numeroServicios == 0) {
        cout << "No hay servicios activos" << endl;
        
    }else{
        
        
        cout << "Mostrando servicios activos:" << endl << endl;
        for (int i = 0; i < numeroServicios; i++) {
            
            cout << "=============================" << endl;
            cout << "Servicio " << i + 1 << endl;
            servicios[i]->muestraServicio();
        }
    }
}
bool tAgencia::contrataServicio(){
    bool encontrado = false;
    tIdioma origen = tIdioma();
    cout << "Introduce idioma origen" << endl;
    origen.leerIdioma();
    
    tIdioma destino = tIdioma();
    cout << "Introduce idioma destino" << endl;
    destino.leerIdioma();
    encontrado = buscaTraductor(origen,destino);
    if (!encontrado) encontrado = buscaEquipoTraductor(origen, destino);
    return encontrado;
}

bool tAgencia::rescindirServicio(){
    int opcion;
    bool enc = false;
    
    mostrarServicios();
    
    cout << "Elige que servicio deseas rescindir: " << endl;
    
    cin >> opcion;
    opcion = opcion - 1;
    
    while ((opcion <= numeroServicios || opcion >= 0) && !enc) {
        delete servicios[opcion];
        servicios[opcion] = NULL;
        enc = true;
    }
    if (enc){
        for (int j = opcion; j <= numeroServicios - opcion; j++) {
            servicios[j] = servicios[j+1];
        }
        numeroServicios--;
    }
    
    return enc;
}
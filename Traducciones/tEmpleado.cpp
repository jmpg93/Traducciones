//
//  tEmpleado.cpp
//  Traducciones
//
//  Created by Jose Maria Puerta on 26/04/14.
//  Copyright (c) 2014 Jose Maria Puerta. All rights reserved.
//

#include "tEmpleado.h"

tEmpleado::tEmpleado(){
    nombre = "";
    apellido = "";
    idiomas[0] = new tIdioma();
}

void tEmpleado::aniadeEmpleado(){
    //num no puede ser mayor que 5
    int num = 0;
    
    nombre = "jose";
    
    cout << "Introduce el nombre y primer apellido: ";
    cin >> nombre;
    cin >> apellido;
    cout << endl;
    
    cout << "Introduce numero de idiomas que domina: ";
    cin >> idiomasHablados;
    cout << endl;
    
    cout << "Introduce los idiomas" << endl;
    
    for (int i = 0; i < idiomasHablados; i++) {
        string lengua;
        cin >> lengua;
        if (idiomas[i]==NULL) {
            idiomas[i] = new tIdioma();
        }
        idiomas[i]->ponLengua(lengua);
    }

}

void tEmpleado::cargaEmpleado(string datos){
    int lengt = datos.length();
    
    unsigned long pos = datos.find_first_of(" ");
    nombre = datos.substr(0,pos);
    datos = datos.substr(pos + 1, lengt);
    
    pos = datos.find_first_of(" ");
    apellido = datos.substr(0,pos);
    datos = datos.substr(pos + 1, lengt);
    
    pos = datos.find_first_of(" ");
    string aux =  datos.substr(0, pos);
    idiomasHablados = (int)aux[0] - 48;
    datos = datos.substr(pos + 1, lengt);
    
    
    for (int i = 0; i < idiomasHablados; i++){
        pos = datos.find_first_of(" ");
        string aux =  datos.substr(0, pos);
        datos = datos.substr(pos + 1, lengt);
        if(idiomas[i]==NULL){
            idiomas[i] = new tIdioma();
        }
        idiomas[i]->ponLengua(aux);
    }
    
}
int tEmpleado::dameIdiomasHablados(){
    return idiomasHablados;
}
tIdioma * tEmpleado::dameIdiomas(){
    return idiomas[0];
}

void tEmpleado::ponNombre(string nom){
    nombre = nom;
}
string tEmpleado::dameNombre(){
    return nombre + " " + apellido;
}